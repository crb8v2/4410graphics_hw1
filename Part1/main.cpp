// needs random colors

#include <iostream>
#include <GL/glut.h>

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0);         //set the background color
    glColor3f(0.0f, 0.0f, 0.0f);            //drawing color
    glPointSize(4.0);                       // pixel with of draw
    glMatrixMode(GL_PROJECTION);            // set up matrices
    glLoadIdentity();                       // tbd
    gluOrtho2D(0.0, 640.0, 0.0, 640.0);     // tbd
}

void myDisplay(void){


    srand(time(NULL));

    float a = (float)(rand()/(float)RAND_MAX);
    float b = (float)(rand()/(float)RAND_MAX);
    float c = (float)(rand()/(float)RAND_MAX);

    float d = (rand()/(float)RAND_MAX);
    float e = (rand()/(float)RAND_MAX);
    float f = (rand()/(float)RAND_MAX);

    int flag = 0;

    glClear(GL_COLOR_BUFFER_BIT);

    for(int aa = 0; aa <= 640; aa += 80){
        for(int bb = 0; bb <= 640; bb += 80){
            if (flag % 2 == 0){
                glColor3f(a,b,c);
            } else {
                glColor3f(d,e,f);
            }
            glRecti(aa, bb, aa + 80, bb + 80);
            flag++;
        }
    }

    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Homework 1 Part 1");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
