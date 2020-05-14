/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

//#include <GL/glut.h>

//#include <GL/glut.h>
//#include <stdlib.h>

static int  elbow = 0,  fingerUp = 0, fingerBase=0,fingerUp1=0, fingerBase1=0,fingerUp2=0,fi_half3=0;
static int hor2=0,hor1=0, chest=0,fi_half=0,se_half=0,fi_half2=0,se_half2=0,ar_1=0,ar_2=0,fi_half1=0;
static int fingerBase2=0,fingerBase3=0,fingerBase4=0,fingerBase5=0,fingerBase6=0,fingerBase7=0,fingerBase8=0;
static int fingerUp3=0,fingerUp4=0,fingerUp5=0,fingerUp6=0,fingerUp7=0,fingerUp8=0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
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







   glPopMatrix();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 's':
      if(fi_half2<=90)
      {
          fi_half2=(fi_half2+5)%360;
      }
      glutPostRedisplay();
      break;
   case 'S':
      if(fi_half2>=0)
      {
          fi_half2=(fi_half2-5)%360;
      }
      glutPostRedisplay();
      break;
   case 'a':
        if(fi_half1<=90)
        {
            fi_half1=(fi_half1+5)%360;
        }
        glutPostRedisplay();
        break;
   case 'A':
        if(fi_half1>=0)
        {
            fi_half1=(fi_half1-5)%360;
        }
        glutPostRedisplay();
        break;
   case 'e':

       if (elbow <=110)
       {
           elbow = (elbow + 5) % 360;
       }
       glutPostRedisplay();
            break;


   case 'E':
       //elbow =0;
       if (elbow>=-110)
       {
           elbow = (elbow - 5) % 360;
       }
       glutPostRedisplay();
       break;
   case 'h':
       if(hor1<=0)
       {
           hor1 =(hor1+5)%360;
       }
       glutPostRedisplay();
       break;
   case 'H':
        if(hor1>=-90)
        {
            hor1=(hor1-5)%360;
        }
        glutPostRedisplay();
        break;
   case 'g':
        if(hor2<=0)
        {
            hor2=(hor2+5)%360;
        }
        glutPostRedisplay();
        break;
   case 'G':
        if(hor2>=-90)
        {
            hor2=(hor2-5)%360;
        }
        glutPostRedisplay();
        break;

   case 'l':
        if (fi_half<=45)
        {
            fi_half = (fi_half + 5) % 360;
        }
        glutPostRedisplay();
        break;
   case 'L':
        if(fi_half>=-55)
        {
            fi_half=(fi_half-5)%360;
        }
        glutPostRedisplay();
        break;
   case 'z':
        if(fi_half3 <=45)
        {
            fi_half3=(fi_half3+5)%360;
        }
        glutPostRedisplay();
        break;
   case 'Z':
        if(fi_half3 >=-55)
        {
            fi_half3=(fi_half3-5)%360;
        }
        glutPostRedisplay();
        break;
   case 'm':
        if(ar_1<=110)
        {
            ar_1=(ar_1+5)%360;
        }
        glutPostRedisplay();
        break;
   case 'M':
        if(ar_1>=5)
        {
            ar_1=(ar_1-5)%360;
        }
        glutPostRedisplay();
        break;

   case 'd':
        if (ar_2<=85)
        {
            ar_2=(ar_2+5)%360;
        }
        glutPostRedisplay();
        break;
   case 'D':
        if(ar_2>=5)
        {
            ar_2=(ar_2-5)%360;
        }
        glutPostRedisplay();
        break;

   case 'f':
       if (fingerBase <=70)
       {
            fingerBase = (fingerBase + 5) % 360;
       }
       glutPostRedisplay();
       break;

   case 'F':
       //fingerBase =0;
       if (fingerBase>=0){
            fingerBase = (fingerBase - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'q':
       if (fingerBase1 <=70)
       {
            fingerBase1 = (fingerBase1 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'Q':
       //fingerBase =0;
       if (fingerBase1>=0){
            fingerBase1 = (fingerBase1 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'r':
       if (fingerBase2 <=70)
       {
            fingerBase2 = (fingerBase2 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'R':
       //fingerBase =0;
       if (fingerBase2>=0){
            fingerBase2 = (fingerBase2 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 't':
       if (fingerBase3 <=70)
       {
            fingerBase3 = (fingerBase3 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'T':
       //fingerBase =0;
       if (fingerBase3>=0){
            fingerBase3 = (fingerBase3 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'y':
       if (fingerBase4 <=70)
       {
            fingerBase4 = (fingerBase4 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'Y':
       //fingerBase =0;
       if (fingerBase4>=0){
            fingerBase4 = (fingerBase4 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'u':
       if (fingerBase5 <=70)
       {
            fingerBase5 = (fingerBase5 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'U':
       //fingerBase =0;
       if (fingerBase5>=0){
            fingerBase5 = (fingerBase5 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'i':
       if (fingerBase6 <=70)
       {
            fingerBase6 = (fingerBase6 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'I':
       //fingerBase =0;
       if (fingerBase6>=0){
            fingerBase6 = (fingerBase6 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'o':
       if (fingerBase7 <=70)
       {
            fingerBase7 = (fingerBase7 + 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'O':
       //fingerBase =0;
       if (fingerBase7>=0){
            fingerBase7 = (fingerBase7 - 5) % 360;
       }
       glutPostRedisplay();
       break;

    case 'w':
          if (fingerUp<=90)
          {
              fingerUp = (fingerUp + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'W':
       if (fingerUp>=0)
       {
           fingerUp = (fingerUp - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'p':
          if (fingerUp1<=90)
          {
              fingerUp1 = (fingerUp1 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'P':
       if (fingerUp1>=0)
       {
           fingerUp1 = (fingerUp1 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'j':
          if (fingerUp2<=90)
          {
              fingerUp2 = (fingerUp2 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'J':
       if (fingerUp2>=0)
       {
           fingerUp2 = (fingerUp2 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'k':
          if (fingerUp3<=90)
          {
              fingerUp3 = (fingerUp3 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'K':
       if (fingerUp3>=0)
       {
           fingerUp3 = (fingerUp3 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'x':
          if (fingerUp4<=90)
          {
              fingerUp4 = (fingerUp4 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'X':
       if (fingerUp4>=0)
       {
           fingerUp4 = (fingerUp4 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'c':
          if (fingerUp5<=90)
          {
              fingerUp5 = (fingerUp5 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'C':
       if (fingerUp5>=0)
       {
           fingerUp5 = (fingerUp5 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'v':
          if (fingerUp6<=90)
          {
              fingerUp6 = (fingerUp6 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'V':
       if (fingerUp6>=0)
       {
           fingerUp6 = (fingerUp6 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'b':
          if (fingerUp7<=90)
          {
              fingerUp7 = (fingerUp7 + 5) % 360;
          }
        glutPostRedisplay();
        break;
   case 'B':
       if (fingerUp7>=0)
       {
           fingerUp7 = (fingerUp7 - 5) % 360;
       }
        glutPostRedisplay();
        break;
  /*
   case 'w':
    if (fingerBase1<=90){
            fingerBase1 = (fingerBase1 + 5) % 360;
       }
       glutPostRedisplay();
       break;
   case 'W':
    if (fingerBase1>=-90){
            fingerBase1 = (fingerBase1 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'a':
          if (fingerUp1<=00)
          {
              fingerUp1 = (fingerUp1 + 5) % 360;
          }
        glutPostRedisplay();
        break;
    case 'A':
       if (fingerUp1>=-90)
       {
           fingerUp1 = (fingerUp1 - 5) % 360;
       }
        glutPostRedisplay();
        break;
    case 'm':
    if (fingerBase2<=90){
            fingerBase2 = (fingerBase2 + 5) % 360;
       }
       glutPostRedisplay();
       break;
   case 'M':
    if (fingerBase2>=-180){
            fingerBase2 = (fingerBase2 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'q':
        if (fingerUp2<=00)
          {
              fingerUp2 = (fingerUp2 + 5) % 360;
          }
        glutPostRedisplay();
        break;
    case 'Q':
       if (fingerUp2>=-90)
       {
           fingerUp2 = (fingerUp2 - 5) % 360;
       }
        glutPostRedisplay();
        break;

   case 'n':
    if (fingerBase3<=90){
            fingerBase3 = (fingerBase3 + 5) % 360;
       }
       glutPostRedisplay();
       break;
   case 'N':
    if (fingerBase3>=-180){
            fingerBase3 = (fingerBase3 - 5) % 360;
       }
       glutPostRedisplay();
       break;
    case 'r':
        if (fingerUp3<=00)
          {
              fingerUp3 = (fingerUp3 + 5) % 360;
          }
        glutPostRedisplay();
        break;
    case 'R':
       if (fingerUp3>=-90)
       {
           fingerUp3 = (fingerUp3 - 5) % 360;
       }
        glutPostRedisplay();
        break;
*/
   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle = angle + (x - startx);
    angle2 = angle2 + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
