// Boxing-1.cpp
// Harel Ezra and Hagai Asaban
//------------------------------------------------
#include "stdafx.h"
#include "time.h"
#include "cstdlib"
#include <glut.h> 
#include <math.h> 

#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1280
#define WINDOW_POS_X 10
#define WINDOW_POS_Y 10
#define Pi 3.14159
#define START_ANGLE 0.0

// Display lists
#define TRIBUNE_LIST 1 
#define ROPES_LIST 2 

// Edges
GLdouble LEFT_EDGE = -WINDOW_WIDTH / 2;
GLdouble RIGHT_EDGE = WINDOW_WIDTH / 2;
GLdouble BOTTOM_EDGE = -WINDOW_HEIGHT / 2;
GLdouble TOP_EDGE = WINDOW_HEIGHT / 2;
GLdouble OUTSIDE_EDGE = -WINDOW_WIDTH / 2;
GLdouble INSIDE_EDGE = WINDOW_WIDTH / 2;

// World
GLdouble WORLD_WIDTH = WINDOW_WIDTH - (WINDOW_WIDTH/10);
GLdouble WORLD_HEIGHT = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);

// Arena
GLdouble ARENA_SIZE = WINDOW_WIDTH / 5;
GLdouble ARENA_Y_SCALE = 0.3;
GLdouble ARENA_ROPES_NUMBER = 4;
GLdouble ARENA_ROPE_THICKNESS = 2;
GLdouble ARENA_ROPE_Y_DELTA = (ARENA_SIZE * ARENA_Y_SCALE) / ARENA_ROPES_NUMBER;
GLdouble ARENA_CORNER_THICKNESS = 7;

// Tribunes
GLint NUMBER_OF_STAIRS = 5;
GLdouble TRIBUNES_SIZE = ARENA_SIZE * 1.8;
GLdouble TRIBUNES_Y_SCALE = 0.05;
GLdouble TRIBUNES_Z_SCALE = 0.5;

// Roof, Floor, walls
GLdouble ROOF_Y = WORLD_HEIGHT / 2;
GLdouble FLOOR_Y = -WORLD_HEIGHT / 2;
GLdouble FRONT_Z_WALL = WORLD_WIDTH / 2;
GLdouble BACK_Z_WALL = -WORLD_WIDTH / 2;
GLdouble RIGHT_X_WALL = WORLD_WIDTH / 2;
GLdouble LEFT_X_WALL = -WORLD_WIDTH / 2;

// Body parts
GLdouble HEAD_RADIUS = 8;
GLdouble HEAD_RADIUS_WIDTH_SCALE = 0.8;
GLdouble EYE_RADIUS = 1;
GLdouble NOSE_RADIUS = 1;
GLdouble NOSE_RADIUS_WIDTH_SCALE = 2.5;

GLdouble NECK_RADIUS = 2;
GLdouble NECK_RADIUS_WIDTH_SCALE = 0.6;

GLdouble BODY_RADIUS_HEIGHT = 20;
GLdouble BODY_RADIUS_WIDTH_SCALE = 0.3;

GLdouble HAND_RADIUS_HEIGHT = 7;
GLdouble HAND_RADIUS_WIDTH_SCALE = 0.4;

GLdouble LEGS_RADIUS_HEIGHT = 7;
GLdouble LEGS_RADIUS_WIDTH_SCALE = 0.45;
GLdouble FOOTS_RADIUS_HEIGHT = 3;
GLdouble FOOTS_RADIUS_WIDTH_SCALE = 0.4;

double red;
double green;
double blue;
double angle = START_ANGLE;
double angle_delta = 0.83;
double body_angle = START_ANGLE;
double body_angle_delta = 0.52;
double arm_angle = START_ANGLE;
double arm_angle_delta = 1.92;

float headPos;
float neckPos;
float bodyPos;
bool rotateArms = false;
bool rotateAll = false;

void my_init(void);
void my_display(void);
void my_idle(void);
void keyInput(void);

void draw_axes();
void draw_head();
void draw_neck();
void draw_body();
void draw_hands();
void draw_legs();
void draw_face();
void draw_ball();
void draw_arena();
void draw_boxingRing();
void draw_corners();
void draw_ropes();
void draw_tribunes();
void draw_tribune();
void draw_world();

void rotateToFixZ();

// Camera class.
class Camera
{
	public:
		Camera();
		void incrementViewDirection();
		void decrementViewDirection();
		void incrementZoomDistance() { zoomDistance += 1.0; }
		void decrementZoomDistance() { zoomDistance -= 1.0; }

		float getViewDirection() const { return viewDirection; }
		float getZoomDistance() const { return zoomDistance; }

	private:
		float viewDirection;
		float zoomDistance;
};

// Global camera.
Camera camera;

// Camera constructor.
Camera::Camera()
{
	viewDirection = 0.0;
	zoomDistance = 30.0;
}

// Function to increment camera viewing angle.
void Camera::incrementViewDirection()
{
	viewDirection += 5.0;
	if (viewDirection > 360.0) viewDirection -= 360.0;
}

// Function to decrement camera viewing angle.
void Camera::decrementViewDirection()
{
	viewDirection -= 5.0;
	if (viewDirection < 0.0) viewDirection += 360.0;
}

// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------

// This method initialize matrix and colors
void my_init(void)
{
	// Background color = white
	glClearColor(0, 0, 0, 1);

	// Define the matrix and 3D mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // Load the matrix
	glOrtho(LEFT_EDGE, RIGHT_EDGE, BOTTOM_EDGE, TOP_EDGE, OUTSIDE_EDGE, INSIDE_EDGE); // 3D axes definition
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);  //for 3D work
}

// This method display rotating man
void my_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //DEPTH_BUFFER

	//every cadre return axis to basic position
	//try to delete it
	// we can put this command to Idle function
	glLoadIdentity();

	// Place camera
	gluLookAt(camera.getZoomDistance() * sin(camera.getViewDirection()*Pi / 180.0), 
			  0.0,
			  camera.getZoomDistance() * cos(camera.getViewDirection()*Pi / 180.0), 
			  0.0, 5.0, 1.0, 
			  0.0, 1.0, 0.0);

	// Rotate the whole man parts together anticlockwise
	//glRotatef(body_angle, 0., 1., 0.);

	/*glColor3ub(100, 0.5, 0.5);
	draw_head();
	glColor3f(1, 0.5, 0.5);
	draw_neck();
	glColor3f(0.3, 1., 0.62);
	draw_body();
	glColor3f(1, 0.5, 0.5);
	draw_hands();
	glColor3f(1, 0.5, 0.5);
	draw_legs();*/
	draw_axes();

	glColor3ub(255, 255, 0);
	draw_world();
	draw_ball();
	draw_tribunes(); 
	draw_arena();

	glutSwapBuffers(); // for animation
}

// This method change the angles for each draw
void my_idle(void)
{
	angle = angle + angle_delta;
	body_angle = body_angle + body_angle_delta;
	arm_angle = arm_angle + arm_angle_delta;

	// Keep moving if exceeds the max angle
	if (angle > 360.) {
		angle -= 360.;
	}
	if (body_angle > 360.) {
		body_angle -= 360.;
	}
	if ((arm_angle < 0.) || (arm_angle > 60.)) {
		arm_angle_delta = -arm_angle_delta;
	}

	// Call redisplay again
	glutPostRedisplay();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ']': // Rotate camera.
		camera.incrementViewDirection();
		glutPostRedisplay();
		break;
	case '[': // Rotate camera.
		camera.decrementViewDirection();
		glutPostRedisplay();
		break;
	case '+': // Zoom in.
		camera.decrementZoomDistance();
		glutPostRedisplay();
		break;
	case '-': // Zoom out.
		camera.incrementZoomDistance();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Define the window size and position on the screen
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	glutCreateWindow("Boxing - by Harel Ezra and Hagai Asaban");

	// Initialize everything
	my_init();

	// Set display function and idle function (the changes every loop)
	glutDisplayFunc(my_display);
	glutIdleFunc(my_idle);

	// Define keyboard input
	glutKeyboardFunc(keyInput);

	// Infinite loop
	glutMainLoop();
}

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------
//                DRAWING FUNCTIONS
//------------------------------------------------
//------------------------------------------------
//------------------------------------------------

void draw_axes() {
	
	glPushMatrix();
		glColor3f(1., 1., 1.);
		glBegin(GL_LINES); 
			glVertex3f(LEFT_EDGE, 0., 0.);
			glVertex3f(RIGHT_EDGE, 0., 0.);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(0., TOP_EDGE, 0.);
			glVertex3f(0., BOTTOM_EDGE, 0.);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(0., 0., INSIDE_EDGE);
			glVertex3f(0., 0., OUTSIDE_EDGE);
		glEnd();
	glPopMatrix();
}

void draw_ball() {
	glPushMatrix();
		glTranslatef(0., 200, 0.);

		glutWireSphere(50, 10, 10);
	glPopMatrix();
}

void draw_arena() {
	glPushMatrix();
		glColor3f(0.2, 0.4, 0.5);
		//glRotatef(body_angle, 0., 1., 0.);
		
		glTranslatef(0., FLOOR_Y + ((ARENA_SIZE / 2) * ARENA_Y_SCALE), 0.);
		glScalef(1., ARENA_Y_SCALE, 1.);
		glShadeModel(GL_SMOOTH);
		glutWireCube(ARENA_SIZE);
	glPopMatrix();

	draw_boxingRing();
}

// Draw the ropes around the arena and the corners
void draw_boxingRing() {
	draw_corners(); 
	draw_ropes();
}

// Draw the corners around the arena
void draw_corners() {

	glPushMatrix();

		// Start with the arena floor height and side
		glTranslatef(ARENA_SIZE / 2, FLOOR_Y + (ARENA_SIZE * ARENA_Y_SCALE), -ARENA_SIZE / 2);

		// Draw the corners
		glTranslatef(-ARENA_CORNER_THICKNESS, 0., ARENA_CORNER_THICKNESS);
		glRotatef(-90., 1., 0., 0.);
		glColor3f(1., 1., 1.);
		
		gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);
		
		glTranslatef(-ARENA_SIZE + (ARENA_CORNER_THICKNESS * 2), 0., 0.);
		gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);

		glTranslatef(0., -ARENA_SIZE + (ARENA_CORNER_THICKNESS * 2), 0.);
		gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);
		
		glTranslatef(ARENA_SIZE - (ARENA_CORNER_THICKNESS * 2), 0., 0.);
		gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);
	glPopMatrix();
}

// Draw the ropes around the arena
void draw_ropes() { 
	
	glNewList(ROPES_LIST, GL_COMPILE);
		glPushMatrix();
		
			// Start with the arena floor height and side
			glTranslatef(ARENA_SIZE / 2, FLOOR_Y + (ARENA_SIZE * ARENA_Y_SCALE), -ARENA_SIZE / 2);

			// Draw the ropes with delta between them
			glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
			glColor3f(1., 0., 0.);
			gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
			glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
			glColor3f(1., 1., 1.); 
			gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
			glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
			glColor3f(0., 0., 1.);
			gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
			glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
			glColor3f(1., 0., 0.);
			gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);

		glPopMatrix();
	glEndList();

	// Draw the four sides of ropes, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(ROPES_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(ROPES_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(ROPES_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(ROPES_LIST);
	glPopMatrix();
}

void draw_tribunes() {
	
	glNewList(TRIBUNE_LIST, GL_COMPILE);
		GLdouble deltaTribuneY = TRIBUNES_SIZE * TRIBUNES_Y_SCALE;
		GLdouble deltaScaleZ = 1 - 1.0 / NUMBER_OF_STAIRS;
		GLdouble deltaTribuneZ = (TRIBUNES_SIZE * TRIBUNES_Z_SCALE) / NUMBER_OF_STAIRS;
	
		glColor3f(0.4, 0.4, 0.4);

		glPushMatrix(); 
		
			GLdouble eqn[4] = { 0.0, 0.0, -1.0, FRONT_Z_WALL }; /* z < 0 */
			glClipPlane(GL_CLIP_PLANE0, eqn);
			glEnable(GL_CLIP_PLANE0);

			// Draw first stair
			glTranslatef(0.,
						 FLOOR_Y + ((TRIBUNES_SIZE / 2) * TRIBUNES_Y_SCALE),
						 FRONT_Z_WALL - ((TRIBUNES_SIZE / 2) * TRIBUNES_Z_SCALE));
			draw_tribune();
		
			// Draw next stairs
			for (int currStair = 2; currStair <= NUMBER_OF_STAIRS; currStair++) {
				//deltaTribuneZ = ;
				glScalef(1., 1., deltaScaleZ); 
				glTranslatef(0., deltaTribuneY, deltaTribuneZ);
			
				draw_tribune();
			}

			glDisable(GL_CLIP_PLANE0);

		glPopMatrix();
	glEndList();

	// Draw the four tribunes, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
	glPopMatrix();
}

void draw_tribune() {
	glPushMatrix();
		//glRotatef(body_angle, 0., 1., 0.);

		glScalef(1., TRIBUNES_Y_SCALE, TRIBUNES_Z_SCALE);

		glutWireCube(TRIBUNES_SIZE);
	glPopMatrix();
}

void draw_world() {
	glPushMatrix();
		//glTranslatef(0., -WINDOW_HEIGHT, 0.);
		glScalef(1., WORLD_HEIGHT / WORLD_WIDTH, 1.);

		glutWireCube(WORLD_WIDTH);
	glPopMatrix();
}

// This method draws man head
void draw_head() {
	headPos = TOP_EDGE - HEAD_RADIUS * 2;

	glPushMatrix();
	glTranslatef(0., headPos, 0.);
	rotateToFixZ();
	glScalef(HEAD_RADIUS_WIDTH_SCALE, HEAD_RADIUS_WIDTH_SCALE, 1.);

	glutWireSphere(HEAD_RADIUS, 10, 10); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	glColor3f(0.3, 0.62, 1.);
	draw_face();
}

// This method draws man face
void draw_face() {
	float rightEyePosX = ((HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) / 2) - EYE_RADIUS;
	float rightEyePosY = headPos + ((HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) / 2) - EYE_RADIUS;
	float rightEyePosZ = (HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) - EYE_RADIUS;
	float leftEyePosX = -rightEyePosX;
	float leftEyePosY = rightEyePosY;
	float leftEyePosZ = rightEyePosZ;

	glPushMatrix();
	glTranslatef(rightEyePosX, rightEyePosY, rightEyePosZ);
	rotateToFixZ();

	glutWireSphere(EYE_RADIUS, 4, 4); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftEyePosX, leftEyePosY, leftEyePosZ);
	rotateToFixZ();

	glutWireSphere(EYE_RADIUS, 4, 4); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw nose
	float nosePosX = (rightEyePosX + leftEyePosX) / 2;
	float nosePosY = headPos;
	float nosePosZ = rightEyePosZ + (NOSE_RADIUS * NOSE_RADIUS_WIDTH_SCALE);

	glPushMatrix();
	glTranslatef(nosePosX, nosePosY, nosePosZ);
	glRotatef(90, 0.1, 1., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(angle, 1., 0., 0.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	glScalef(NOSE_RADIUS_WIDTH_SCALE, 1.0, 1.0);

	glutWireSphere(NOSE_RADIUS, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man neck
void draw_neck() {
	neckPos = headPos - HEAD_RADIUS - (NECK_RADIUS * NECK_RADIUS_WIDTH_SCALE);

	glPushMatrix();
	glTranslatef(0., neckPos, 0.);
	rotateToFixZ();
	glScalef(1., 1., NECK_RADIUS_WIDTH_SCALE);

	glutWireSphere(NECK_RADIUS, 6, 6); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man body
void draw_body() {
	bodyPos = neckPos - (NECK_RADIUS * NECK_RADIUS_WIDTH_SCALE) - BODY_RADIUS_HEIGHT;

	glPushMatrix();
	glTranslatef(0., bodyPos, 0.);
	rotateToFixZ();
	glScalef(BODY_RADIUS_WIDTH_SCALE*1.8, BODY_RADIUS_WIDTH_SCALE, 1.);

	glutWireSphere(BODY_RADIUS_HEIGHT, 14, 14); //(radius, slices-vertical[פרוסות], stacks-horizontal);

	glPopMatrix();
}

// This method draws man hands
void draw_hands() {
	float rightArmX =
		bodyPos - (BODY_RADIUS_HEIGHT * BODY_RADIUS_WIDTH_SCALE * 2) - (HAND_RADIUS_HEIGHT * HAND_RADIUS_WIDTH_SCALE);
	float rightArmY = bodyPos + (HAND_RADIUS_HEIGHT);
	float leftArmX = -rightArmX;
	float leftArmY = rightArmY;

	glPushMatrix();
	glTranslatef(rightArmX, rightArmY, 0.);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(150, 0., 1., 0.);

	// If rotate arms
	if (rotateArms) {
		glRotatef(arm_angle, 1., 0., 0.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	}

	glScalef(HAND_RADIUS_WIDTH_SCALE, HAND_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftArmX, leftArmY, 0.);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(-150, 0., 1., 0.);

	// If rotate arms
	if (rotateArms) {
		glRotatef(arm_angle, 1., 0., 0.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	}

	glScalef(HAND_RADIUS_WIDTH_SCALE, HAND_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw the forearms
	float rightForearmX = rightArmX - rightArmX*sin(150.);
	float rightForearmY = rightArmY - HAND_RADIUS_HEIGHT - HAND_RADIUS_HEIGHT / 2 + HAND_RADIUS_HEIGHT;
	float leftForearmX = -rightForearmX - HAND_RADIUS_HEIGHT;
	float leftForearmY = rightForearmY - HAND_RADIUS_HEIGHT;

	glPushMatrix();
	glTranslatef(rightForearmX, rightForearmY, 0.);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(70, 0., 1., 0.2);

	// If rotate arms
	if (rotateArms) {
		glRotatef(arm_angle, 0.7, 0., 0.);
	}

	glScalef(HAND_RADIUS_WIDTH_SCALE / 1.5, HAND_RADIUS_WIDTH_SCALE / 1.5, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftForearmX, leftForearmY, 0);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(165, 0., 1., 0.);

	// If rotate arms
	if (rotateArms) {
		glRotatef(arm_angle, 0.7, 0., 0.);
	}

	glScalef(HAND_RADIUS_WIDTH_SCALE / 1.5, HAND_RADIUS_WIDTH_SCALE / 1.5, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man legs
void draw_legs() {
	float rightThighX =
		bodyPos - (BODY_RADIUS_HEIGHT * BODY_RADIUS_WIDTH_SCALE*1.8 / 1.2);
	float rightThighY = bodyPos - BODY_RADIUS_HEIGHT - LEGS_RADIUS_HEIGHT + (LEGS_RADIUS_HEIGHT / 2);
	float leftThighX = -rightThighX;
	float leftThighY = rightThighY;

	glPushMatrix();
	glTranslatef(rightThighX, rightThighY, 0.);
	glRotatef(77, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE, LEGS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftThighX, leftThighY, 0.);
	glRotatef(77, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE, LEGS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw calfs
	float rightCalfX = rightThighX;
	float rightCalfY = rightThighY - LEGS_RADIUS_HEIGHT - LEGS_RADIUS_HEIGHT + sin(77.);
	float leftCalfX = -rightCalfX;
	float leftCalfY = rightCalfY;

	glPushMatrix();
	glTranslatef(rightCalfX, rightCalfY, 0.);
	glRotatef(-77, 1., 0., 0.);

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE / 1.3, LEGS_RADIUS_WIDTH_SCALE / 1.3, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftCalfX, leftCalfY, 0.);
	glRotatef(-77, 1., 0., 0.);

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE / 1.3, LEGS_RADIUS_WIDTH_SCALE / 1.3, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw calfs
	float rightFootX = rightCalfX;
	float rightFootY =
		rightCalfY - LEGS_RADIUS_HEIGHT - ((FOOTS_RADIUS_HEIGHT / 2)*FOOTS_RADIUS_WIDTH_SCALE);
	float rightFootZ = FOOTS_RADIUS_HEIGHT*FOOTS_RADIUS_WIDTH_SCALE;
	float leftFootX = -rightFootX;
	float leftFootY = rightFootY;
	float leftFootZ = rightFootZ;

	glColor3f(0.5, 0.62, 0.4);

	glPushMatrix();
	glTranslatef(rightFootX, rightFootY, rightFootZ);
	glScalef(FOOTS_RADIUS_WIDTH_SCALE + 0.5, FOOTS_RADIUS_WIDTH_SCALE, 1.0);
	glRotatef(117, 1., 0., 0.);
	glutWireSphere(FOOTS_RADIUS_HEIGHT, 5, 5); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftFootX, leftFootY, leftFootZ);
	glScalef(FOOTS_RADIUS_WIDTH_SCALE + 0.5, FOOTS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(FOOTS_RADIUS_HEIGHT, 6, 6); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method fix the z axis to be up and rotate the object around the new z
void rotateToFixZ() {
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)   

	// If need to rotate all
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	}
}

void fillRandomColor() {
	
	// Define random color
	srand(time(NULL));
	red = (double)(rand() % 1000) / 1000;
	green = (double)(rand() % 1000) / 1000;
	blue = (double)(rand() % 1000) / 1000;
	glColor3f(red, green, blue);
}
