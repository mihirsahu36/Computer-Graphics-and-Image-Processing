// Develop a program to demonstrate basic geometric operations on the 2D object

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float x[3][3] = {{0, 100, 50}, {0, 0, 50}, {1, 1, 1}};
float r[3][3];
void myinit()
{
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(-100, 500, -100, 500);
}

void triangle(float x[3][3])
{
    glColor4s(1, 1, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x[0][0], x[1][0]);
        glVertex2f(x[0][1], x[1][1]);
        glVertex2f(x[0][2], x[1][2]);
    glEnd();
}

void matrixmul(float mul[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            r[i][j] = 0;
            for (int k = 0; k < 3; k++)
                r[i][j] = r[i][j] + mul[i][k] * x[k][j];
        }
}

void translation()
{
    float t[3][3] = {{1, 0, 100}, {0, 1, 0}, {0, 0, 1}};
    printf("Enter the values of Tx and Ty : ");
    scanf("%f %f", &t[0][2], &t[1][2]);
    matrixmul(t);
    triangle(r);
}

void scaling()
{
    float s[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    printf("Enter the values of Sx and Sy : ");
    scanf("%f %f", &s[0][0], &s[1][1]);
    matrixmul(s);
    triangle(r);
}

void rotation()
{
    float theta = 0;
    printf("Enter the angle : ");
    scanf("%f", &theta);
    float angle = theta * 3.14 / 180;
    float cosx = cos(angle);
    float sinx = sin(angle);
    float rr[3][3] = {{cosx, -sinx, 0}, {sinx, cosx, 0}, {0, 0, 1}};
    matrixmul(rr);
    triangle(r);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    int ch;
    while (1)
    {
        glColor3d(1, 1, 1);
        printf("Enter the choice: \n0 for normal triangle \n1 for translation \n2 for scaling \n3 for rotation\n4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            triangle(x);
            break;
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter a valid choice.");
            break;
        }

        glColor3d(1, 0, 0);
        triangle(x);
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
