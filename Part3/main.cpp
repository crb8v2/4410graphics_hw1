
#include <GL/glut.h>
#include <iostream>
#include <cmath>

void myInit(void);
void myDisplay(void);
void myMouse(int, int, int, int);
void myKeyboard(unsigned char, int, int);
void myMotion(int,int);
void drawDot(int, int);
void drawLine(int,int, int);

GLint mouseStart[2];

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Homework 1 Part 3");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
//    glutKeyboardFunc(myKeyboard);
    glutMotionFunc(myMotion);
    myInit();
    glutMainLoop();
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0);         //set the background color
    glColor3f(0.0f, 0.0f, 0.0f);            //drawing color
    glPointSize(10.0);                       // pixel with of draw
    glMatrixMode(GL_PROJECTION);            // set up matrices
    glLoadIdentity();                       // tbd
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);     // tbd

    return;
}

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    return;
}


void myMouse( int button, int state, int xx, int yy) {
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON) {
            drawDot(xx, 640 - yy);
            glFlush();
        } else if (GLUT_RIGHT_BUTTON) {
            float aa = (rand()/(float)RAND_MAX);
            float bb = (rand()/(float)RAND_MAX);
            float cc = (rand()/(float)RAND_MAX);

            glColor3f(aa,bb,cc);
        }
    }
    return;
}

void myKeyboard(unsigned char theKey, int mouseX, int mousey) {
    return;
}

void myMotion(int xx, int yy) {
    mouseStart[0] = xx;
    mouseStart[1] = 640-yy;
    glFlush();
    return;
}

void drawDot(int xx, int yy){
    glBegin(GL_POINTS);
    glVertex2i(xx, yy);
    glEnd();

    return;
}

void drawLine(int xx, int yy, int nn) {
    glBegin(GL_LINES);

    for (int ii = 0; ii < nn; ii ++)
        glVertex2f(xx,yy);

    glEnd();

    return;
}







//
//#include <GL/glut.h>
//int ww = 600, wh = 400;
//int first = 0;
//int xi, yi, xf, yf;
//void drawLine(int x1, int y1, int x2, int y2)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLineWidth(5.0);
//    glBegin(GL_LINES);
//    glVertex2i(x1, y1);
//    glVertex2i(x2, y2);
//    glEnd();
//    glFlush();
//}
//void display()
//{
//    glClearColor(1.0, 1.0, 0.0, 1.0);
//    glColor3f(1.0, 0.0, 0.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glFlush();
//}
//void mouse(int btn, int state, int x, int y)
//{
//    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//    {
//        switch(first)
//        {
//            case 0:
//                xi = x;
//                yi = (wh-y);
//                first = 1;
//                break;
//            case 1:
//                xf = x;
//                yf = (wh-y);
//                drawLine(xi,yi,xf,yf);
//                first = 0;
//                break;
//        }
//    }
//}
//void myinit()
//{
//    glViewport(0,0,ww,wh);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
//    glMatrixMode(GL_MODELVIEW);
//}
//int main(int argc, char** argv)
//{
//    glutInit(&argc,argv);
//    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(ww,wh);
//    glutCreateWindow("demo");
//    glutDisplayFunc(display);
//    myinit();
//    glutMouseFunc(mouse);
//    glutMainLoop();
//    return 0;
//}