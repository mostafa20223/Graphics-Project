#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#include "glm.h"
#include "imageloader.h"

static int  elbow = 0,  fingerUp = 0, fingerBase = 0, fingerUp1 = 0, fingerBase1 = 0, fingerUp2 = 0, fi_half3 = 0;
static int hor2 = 0, hor1 = 0, chest = 0, fi_half = 0, se_half = 0, fi_half2 = 0, se_half2 = 0, ar_1 = 0, ar_2 = 0, fi_half1 = 0;
static int fingerBase2 = 0, fingerBase3 = 0, fingerBase4 = 0, fingerBase5 = 0, fingerBase6 = 0, fingerBase7 = 0, fingerBase8 = 0;
static int fingerUp3 = 0, fingerUp4 = 0, fingerUp5 = 0, fingerUp6 = 0, fingerUp7 = 0, fingerUp8 = 0;
static int shoulder = 0, shoulder2 = 0;
double eye[] = { 0, 0, 1 };
double center[] = { 0, 0, -1 };
double up[] = { 0, 1, 0 };
double direction[] = { 0, 0, 0 };
double normal[] = { 0, 0, 0 };
double theta = 0, theta1 = 0.5, theta2 = -0.5;
int moving, startx, starty;
GLfloat angle = 0.0;
GLfloat angle2 = 0.0;
static int windowWidth = 1024, windowHeight = 768;
float aspect = float(windowWidth) / float(windowHeight);
GLMmodel* pmodel;
float y_pos = 0.3, x_pos = 0.0;
int state = 1;
int RRot = 0.0;
int delay = 0;

// RGBA
GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat light_diffuse[] = { 0.5, 0.5, 0.5,1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
// x, y, z, w
GLfloat light_position[] = { 0.5, 5.0, 0.0, 1.0 };
GLfloat lightPos1[] = { -0.5, -5.0, -2.0, 1.0 };
// Material Properties
GLfloat mat_amb_diff[] = { 0.643, 0.753, 0.934, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat shininess[] = { 100.0 };
// Left teapot specular
GLfloat teapotl_diff[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat teapotl_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat teapotl_shininess[] = { 10.0 };
// Middle teapot diffuse
GLfloat teapotm_diff[] = { 1.0, 0, 0.0, 1.0 };
GLfloat teapotm_specular[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat teapotm_shininess[] = { 1.0 };
// Right teapot glosy
GLfloat teapotr_diff[] = { 1.0, .0, 0.0, 1.0 };
GLfloat teapotr_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat teapotr_shininess[] = { 1000.0 };
// Cube
GLfloat cube_diff[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat cube_specular[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat cube_shininess[] = { 10.0 };

// Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
      GLuint textureId;
      glGenTextures(1, &textureId); //Make room for our texture
      glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
      //Map the image to the texture
      glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                               0,                            //0 for now
                               GL_RGB,                       //Format OpenGL uses for image
                               image->width, image->height,  //Width and height
                               0,                            //The border of the image
                               GL_RGB, //GL_RGB, because pixels are stored in RGB format
                               GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                                 //as unsigned numbers
                               image->pixels);               //The actual pixel data
      return textureId; //Returns the id of the texture
}

GLuint _textureId; //The id of the texture

void drawTexture() {
    Image* image = loadBMP("D:/Graphics-Project/finalproject/textures/floor6.bmp");
    _textureId = loadTexture(image);
    delete image;
}
// Initializes 3D rendering
void initRendering() {
      	// Turn on the power
        glEnable(GL_LIGHTING);
        // Flip light switch
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        // Assign light parameters
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
        // Material Properties
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE,mat_amb_diff);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
        GLfloat lightColor1[] = {1.0f, 1.0f,  1.0f, 1.0f };
        glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor1);
        glEnable(GL_NORMALIZE);
        // Enable smooth shading
        glShadeModel(GL_SMOOTH);
        // Enable Depth buffer
        glEnable(GL_DEPTH_TEST);
}

void rotatePoint(double a[], double theta, double p[]) {
	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];
	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];
	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);
	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);
	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];
	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];
}

void normalize(double a[]) {
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void turnLeft() {
	double speed = 3.1415 / 100;
	double direction[] = { 0, 1, 0 };
	rotatePoint(direction, speed, center);
}

void turnRight() {
	double speed = -3.1415 / 100;
	double direction[] = { 0, 1, 0 };
	rotatePoint(direction, speed, center);
}

void moveUp() {
	double speed = 0.01;
	center[1] += speed;
}

void moveDown() {
	double speed = -0.01;
	center[1] += speed;
}

void moveForward() {
	double speed = .01;
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	normalize(direction);
	eye[0] += direction[0] * speed;
	eye[2] += direction[2] * speed;
	center[0] += direction[0] * speed;
	center[2] += direction[2] * speed;
}

void moveBack() {
	double speed = -0.01;
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	normalize(direction);
	eye[0] += direction[0] * speed;
	eye[2] += direction[2] * speed;
	center[0] += direction[0] * speed;
	center[2] += direction[2] * speed;
}

void screen_menu(int value) {
    Image* image = 0;
	switch (value) {
	case '1':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor1.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	case '2':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor2.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	case '3':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor3.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	case '4':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor4.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	case '5':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor5.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	case '6':
	    image = loadBMP("D:/Graphics-Project/finalproject/textures/floor6.bmp");
        _textureId = loadTexture(image);
        delete image;
		break;
	}
	glutPostRedisplay();
}

void drawObject(void) {
    pmodel = glmReadOBJ("D:/Graphics-Project/finalproject/objects/desk/desk.obj");
    if (!pmodel) exit(0);
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    glmScale(pmodel, 0.15);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void drawObject1(void) {
    pmodel = glmReadOBJ("D:/Graphics-Project/finalproject/objects/monitor/monitor.obj");
    if (!pmodel) exit(0);
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    glmScale(pmodel, 0.15);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

void drawObject2(void) {
    pmodel = glmReadOBJ("D:/Graphics-Project/finalproject/objects/chair/Office_chair.obj");
    if (!pmodel) exit(0);
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    glmScale(pmodel, 0.15);
	glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}

GLuint startList;

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
    glPushMatrix();
        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glPushMatrix();
        glTranslatef(0.0, 0.0, -1.0);
        // Floor
        glPushMatrix();
            glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, _textureId);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glBegin(GL_QUADS);
                glNormal3f(0.0, -1.0, 0.0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-1.5, -0.25, 2.0);
                glTexCoord2f(5.0f, 0.0f);
                glVertex3f(1.5, -0.25, 2.0);
                glTexCoord2f(5.0f, 20.0f);
                glVertex3f(1.5, -0.25, -2.0);
                glTexCoord2f(0.0f, 20.0f);
                glVertex3f(-1.5, -0.25, -2.0);
            glEnd();
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
        // Objects
        glPushMatrix();
            glTranslatef(1.25, -0.15, -0.2);
            glRotatef(90, 0.0, 1.0, 0.0);
            glScalef(1.5, 1.5, 1.5);
            drawObject();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.25, 0.15, -0.2);
            glRotatef(270, 0.0, 1.0, 0.0);
            glScalef(1.5, 1.5, 1.5);
            drawObject1();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-0.85, 0.0, 0.25);
            glRotatef(90, 0.0, 1.0, 0.0);
            glScalef(2.0, 2.0, 2.0);
            drawObject2();
        glPopMatrix();
        // Chest
        glTranslatef(x_pos, y_pos, 0.25);
        glTranslatef(0.0, 0.05, 0.0);
        glRotatef((GLfloat)RRot, 0.0, 1.0, 0.0);
        glTranslatef(0.0, -0.05, 0.0);
        glPushMatrix();
            glScalef(0.5, 0.75, 0.125);
            glutWireCube(0.5);
        glPopMatrix();
        // Header
        glPushMatrix();
            glTranslatef(0.0, 0.25, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.1, 0.1);
                glutWireSphere(0.5, 8.0, 8.0);
            glPopMatrix();
        glPopMatrix();
        // Right Leg, Right Leg Second Half and Solid Leg
        glPushMatrix();
            glTranslatef(-0.1, -0.27, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)fi_half, 1.0, 0.0, 0.0);
            glRotatef((GLfloat)hor1, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.3, 0.1);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.15, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)fi_half1, 1.0, 0.0, 0.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.3, 0.1);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.1, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.1, 0.2);
                glutSolidCube(0.5);
            glPopMatrix();
        glPopMatrix();
        // Left Leg, Left Leg Second Half and Solid Leg
        glPushMatrix();
            glTranslatef(0.1, -0.27, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef(-(GLfloat)fi_half3, 1.0, 0.0, 0.0);
            glRotatef(-(GLfloat)hor2, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.3, 0.1);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.15, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)fi_half2, 1.0, 0.0, 0.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.3, 0.1);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.1, 0.0);
            glPushMatrix();
                glScalef(0.1, 0.1, 0.2);
                glutSolidCube(0.5);
            glPopMatrix();
        glPopMatrix();
        // Left Arm
        glPushMatrix();
            glTranslatef(0.17, 0.1, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)ar_1, 0.0, 0.0, 1.0);
            glRotatef((GLfloat)ar_2, 0.0, 1.0, 0.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.125, 0.25, 0.15);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.125, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.125, 0.25, 0.15);
                glutWireCube(0.5);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.025, -0.075, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.175, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
                glTranslatef(0.0, 0.05, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.025, -0.075, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerBase1, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerUp1, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.025, -0.075, 0.025);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerBase2, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerUp2, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.025, -0.075, -0.025);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerBase3, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerUp3, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        // Right Arm
        glPushMatrix();
            glTranslatef(-0.17, 0.1, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef(-(GLfloat)ar_1, 0.0, 0.0, 1.0);
            glRotatef(-(GLfloat)ar_2, 0.0, 1.0, 0.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.125, 0.25, 0.15);
                glutWireCube(0.5);
            glPopMatrix();
            glTranslatef(0.0, -0.125, 0.0);
            glTranslatef(0.0, 0.05, 0.0);
            glRotatef((GLfloat)-elbow, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.05, 0.0);
            glPushMatrix();
                glScalef(0.125, 0.25, 0.15);
                glutWireCube(0.5);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.025, -0.075, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.025, -0.075, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerBase5, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerUp5, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.025, -0.075, 0.025);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerBase6, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef((GLfloat)fingerUp6, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.025, -0.075, -0.025);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerBase7, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
                glTranslatef(0.0, -0.025, 0.0);
                glTranslatef(0.0, 0.1, 0.0);
                glRotatef(-(GLfloat)fingerUp7, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.1, 0.0);
                glPushMatrix();
                    glScalef(0.025, 0.05, 0.025);
                    glutWireCube(0.5);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void Timer(int x) {
	glutPostRedisplay();
	glutTimerFunc(0, Timer, 0);
	switch (state) {
    case 1:
        if (fi_half >= -55)
        {
            ar_1 = 50.0, elbow = -100.0;
            fi_half = (fi_half - 8) % 360;
        }
        else
            state = -1;
        break;
    case -1:
        fi_half = 0.0;
        if (fi_half3 <= 45)
        {
            ar_1 = 50.0, elbow = -100.0;
            fi_half3 = (fi_half3 + 8) % 360;
        }
        else
            state = 0;
        break;
	case 0:
        ar_1 = 0.0, elbow = 0.0, fi_half3 = 0.0;
        state = 2;
        break;
    case 2:
        if (y_pos <= 0.6)
        {
            y_pos += 0.05;
            ar_1 = (ar_1 + 8) % 360;
        }
        else
            state = -2;
        break;
    case -2:
        if (y_pos > 0.35)
        {
            y_pos -= 0.05;
            ar_1 = (ar_1 - 8) % 360;
        }
        else
            state = 3;
        break;
    case 3:
        y_pos = 0.3;
        ar_1 = 0.0;
        RRot = -90.0;
        if (fi_half >= -25 && x_pos >= -0.25)
        {
            fi_half = (fi_half - 8) % 360;
//            x_pos += -0.05;
        }
        else if (fi_half3 >= -25 && x_pos >= -0.5)
        {
            fi_half = 0.0;
            fi_half3 = (fi_half3 + 8) % 360;
            x_pos += -0.05;
        }
        else
        {
            break;
        }
        break;
	}
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: turnLeft(); break;
	case GLUT_KEY_RIGHT: turnRight(); break;
	case GLUT_KEY_UP:
		if (center[1] <= 1.5)
			moveUp();
		break;
	case GLUT_KEY_DOWN:
		if (center[1] >= -1.5)
			moveDown();
		break;
	}
}

static void mouse(int button, int state, int x, int y) {
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

void Keyboard(unsigned char Key, int x, int y) {
	switch (Key) {
	case 'f':
        moveForward();
        glutPostRedisplay();
		break;
	case 'b':
        moveBack();
        glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

static void motion(int x, int y) {
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("ROOM");
	drawTexture();
	initRendering();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, aspect, 0.2, 10);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
	glutCreateMenu(screen_menu);
	glutAddMenuEntry("Texture Models", 0);
	glutAddMenuEntry(" ", 0);
	glutAddMenuEntry("Floor1", '1');
	glutAddMenuEntry("Floor2", '2');
	glutAddMenuEntry("Floor3", '3');
	glutAddMenuEntry("Floor4", '4');
	glutAddMenuEntry("Floor5", '5');
	glutAddMenuEntry("Original", '6');
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutTimerFunc(5000, Timer, 0);
	glutMainLoop();
	return 0;
}
