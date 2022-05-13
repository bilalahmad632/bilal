#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define PI 3.1415926

struct vertex{
int x,y;
};

void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}

void setup()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void drawCircMesh(float xc,float yc, float radius,int nodes)
{
    float x,y,angle,inc=2*PI/nodes;
    struct vertex points[nodes];
    int i=0,j,k;

    for(angle=0;angle<=2*PI;angle+=inc)
    {

        x=xc+radius*cos(angle);
        y=yc+radius*sin(angle);

        points[i].x=x;
        points[i].y=y;

        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();

        glFlush(); delay(100);
        i++;
    }

    for(j=0;j<nodes;j++)
    {
        for(k=0;k<nodes;k++)
        {   glBegin(GL_LINES);
            glVertex2i(points[j].x,points[j].y);
            glVertex2i(points[k].x,points[k].y);
            glEnd();
            glFlush(); delay(10);
        }
    }


}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,0);
    glPointSize(2);

    drawCircMesh(320,240,180,25);
//    glColor3f(1,0,1);
//    drawCircMesh(320,340,80,16);
//    glColor3f(1,0,0);
//     drawCircMesh(400,200,80,10);
//    glColor3f(0,0,1);
//     drawCircMesh(500,140,80,20);
//    glColor3f(1,0,1);


}

void main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Circular Mesh");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
}


