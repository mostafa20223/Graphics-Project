#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>


static int  elbow = 0,  fingerUp = 0, fingerBase=0,fingerUp1=0, fingerBase1=0,fingerUp2=0,fi_half3=0;
static int hor2=0,hor1=0, chest=0,fi_half=0,se_half=0,fi_half2=0,se_half2=0,ar_1=0,ar_2=0,fi_half1=0;
static int fingerBase2=0,fingerBase3=0,fingerBase4=0,fingerBase5=0,fingerBase6=0,fingerBase7=0,fingerBase8=0;
static int fingerUp3=0,fingerUp4=0,fingerUp5=0,fingerUp6=0,fingerUp7=0,fingerUp8=0;
GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void robot_body(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   //glPushMatrix();
   glPushMatrix();
   glRotatef(2*angle2, 1.0, 0.0, 0.0);
   glRotatef(2*angle, 0.0, 1.0, 0.0);
   // chest
   //glTranslatef(0,0.0,0);
   //glRotatef((GLfloat)chest,0.0,0.0,1.0);
   glTranslatef(0.0,1.0,0.0);
   glPushMatrix();
   glScalef(2,3.0,0.5);
   glutWireCube(1);
   glPopMatrix();
   //glPopMatrix();
   //Header
   glPushMatrix();
    //glTranslatef(0.0,2.7,0.0);
    //glRotatef((GLfloat)chest,0.0,0.0,1.0);
    glTranslatef(0.0,2.0,0.0);
    glPushMatrix();
    glScalef(0.4,0.4,0.4);
    glutWireSphere(1.0,16.0,16.0);
    glPopMatrix();
   glPopMatrix();


   //Right leg

   glPushMatrix();
    glTranslatef(-0.7,-2.2,0.0);
    glTranslatef(0.0,0.6,0.0);
    glRotatef((GLfloat)fi_half,1.0,0.0,0.0);
    glRotatef((GLfloat)hor1,0.0,0,1.0);
    glTranslatef(0.0,-0.6,0.0);
    glPushMatrix();
    glScalef(0.5,1.5,0.5);
    glutWireCube(1);
    glPopMatrix();
   //glPopMatrix();

   //Right leg second half
    glTranslatef(0.0,-1.5,0.0);
    glTranslatef(0.0,0.8,0.0);
    glRotatef((GLfloat)fi_half1,1.0,0.0,0.0);
    glTranslatef(0.0,-0.8,0.0);
    glPushMatrix();
    glScalef(0.5,1.5,0.5);
    glutWireCube(1);
    glPopMatrix();

    // solid leg
    glTranslatef(0.0,-1.0,0.0);
    glPushMatrix();
    glScalef(0.5,0.5,1);
    glutSolidCube(1);
    glPopMatrix();
   glPopMatrix();

//left leg
   glPushMatrix();
    glTranslatef(0.7,-2.2,0.0);
    glTranslatef(0.0,0.6,0.0);
    glRotatef(-(GLfloat)fi_half3,1,0,0);
    glRotatef(-(GLfloat)hor2,0.0,0,1.0);
    glTranslatef(0.0,-0.6,0.0);
    glPushMatrix();
    glScalef(0.5,1.5,0.5);
    glutWireCube(1);
    glPopMatrix();

   //Right leg second half
    glTranslatef(0.0,-1.5,0.0);
    glTranslatef(0.0,0.8,0.0);
    glRotatef((GLfloat)fi_half2,1.0,0.0,0.0);
    glTranslatef(0,-0.8,0.0);
    glPushMatrix();
    glScalef(0.5,1.5,0.5);
    glutWireCube(1);
    glPopMatrix();

    // solid leg
    glTranslatef(0.0,-1.0,0.0);
    glPushMatrix();
    glScalef(0.5,0.5,1);
    glutSolidCube(1);
    glPopMatrix();
   glPopMatrix();

   //left arm
   glPushMatrix();
   //first half
    glTranslatef(1.4,1,-0.1);
    glTranslatef(0.0,0.5,0);
    glRotatef((GLfloat)ar_1,0,0,1);
    glRotatef((GLfloat)ar_2,0,1,0);
    glTranslatef(0.0,-0.5,0);
    glPushMatrix();
    glScalef(0.5,1,0.6);
    glutWireCube(1);
    glPopMatrix();
    // second half
    glTranslatef(0.0,-1,0.0);
    glTranslatef(0,0.5,0);
    glRotatef((GLfloat)elbow,1,0,0);
    glTranslatef(0,-0.5,0);
    glPushMatrix();
    glScalef(0.5,1,0.6);
    glutWireCube(1);
    glPopMatrix();

    //first finger
    glPushMatrix();
     glTranslatef(-0.2,-0.6,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerBase,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerUp,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //second finger
    glPushMatrix();
     glTranslatef(0.2,-0.6,0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerBase1,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerUp1,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //sthird finger
    glPushMatrix();
     glTranslatef(0.2,-0.6,0.25);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerBase2,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerUp2,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //fourth finger
    glPushMatrix();
     glTranslatef(0.2,-0.6,-0.25);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerBase3,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerUp3,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();
   glPopMatrix();





   //right arm
   glPushMatrix();
   //first half
    glTranslatef(-1.4,1,-0.1);
    glTranslatef(0.0,0.5,0);
    glRotatef(-(GLfloat)ar_1,0,0,1);
    glRotatef(-(GLfloat)ar_2,0,1,0);
    glTranslatef(0.0,-0.5,0);
    glPushMatrix();
    glScalef(0.5,1,0.6);
    glutWireCube(1);
    glPopMatrix();
    // second half
    glTranslatef(0.0,-1,0.0);
    glTranslatef(0,0.5,0);
    glRotatef((GLfloat)elbow,1,0,0);
    glTranslatef(0,-0.5,0);
    glPushMatrix();
    glScalef(0.5,1,0.6);
    glutWireCube(1);
    glPopMatrix();

    //first finger
    glPushMatrix();
     glTranslatef(-0.2,-0.6,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerBase4,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerUp4,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //second finger
    glPushMatrix();
     glTranslatef(-0.2,-0.6,0.25);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerBase5,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerUp5,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //third finger
    glPushMatrix();
     glTranslatef(-0.2,-0.6,-0.25);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerBase6,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef((GLfloat)fingerUp6,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();

    //fourth finger
    glPushMatrix();
     glTranslatef(0.2,-0.6,0.0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerBase7,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();

     glTranslatef(0,-0.2,0);
     glTranslatef(0,0.1,0);
     glRotatef(-(GLfloat)fingerUp7,0,0,1);
     glTranslatef(0,-0.1,0);
     glPushMatrix();
     glScalef(0.1,0.2,0.1);
     glutWireCube(1);
     glPopMatrix();
    glPopMatrix();


   glPopMatrix();






   //glutDisplayFunc(robot_body);
   glPopMatrix();
   glutSwapBuffers();
}


