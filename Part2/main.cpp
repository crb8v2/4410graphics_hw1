#include <iostream>
#include <GL/glut.h>
#include<cmath>

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0);         //set the background color
    glColor3f(0.0f, 0.0f, 0.0f);            //drawing color
    glPointSize(4.0);                       // pixel with of draw
    glMatrixMode(GL_PROJECTION);            // set up matrices
    glLoadIdentity();                       // tbd
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);     // tbd
}

void myDisplay(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    srand(time(NULL));

    GLfloat numPolys, numLines;
    double xx, yy;
    const double PI = 3.14159;
    double r = 100;
    int nn = 0;

    float aa = (rand()/(float)RAND_MAX);
    float bb = (rand()/(float)RAND_MAX);
    float cc = (rand()/(float)RAND_MAX);

    while (nn < 3)
        nn = rand() % 11;

    for (int jj = 0; jj < nn; jj++) {
        xx = rand() % 640;
        yy = rand() % 640;


        glBegin(GL_POLYGON);
        for (int ii = 0; ii < nn; ii++) {
            double angle = ii * 2 * PI / nn;
            glColor3f(aa,bb,cc);
            glVertex2d(xx + r * cos(angle), yy + r * sin(angle));
        }

        glEnd();
    }
    glFlush();
}
//
//    nn = 4;
//
//    xx = (rand()/(GLfloat)RAND_MAX);
//    yy = (rand()/(GLfloat)RAND_MAX);
//    numPolys = nn;
//    numLines = nn;
//
//    for(int ii = 0; ii < nn; ii++) {
//        glBegin(GL_LINE_STRIP);
//
//        for (int jj = 0; jj < nn; jj++)
//            glVertex2f(xx, yy);
//
//        glEnd();
//    }
//    glFlush();
//}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Homework 1 Part 2");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
