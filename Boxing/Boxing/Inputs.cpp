//================================Mouse====================================
#include "Inputs.h"
#include "Camera.h"
#include "Body.h"

Area translation[5] = {
	{ 0, 120, 40, -30.0, 30.0, 0.0, 0.05 },
	{ 1, 180, 40, -30.0, 30.0, 0.0, 0.05 },
	{ 2, 180, 40, -200.0, 200.0, 0.0, 0.1 },
	{ 3, 180, 120, -100, 100, 0.0, 0.5 },
	{ 4, 240, 120, -100, 100, 0.0, 0.5 }
};

/*
gluLookAt initial values, view point rotation
*/
GLfloat eye[3] = { 0.0, 0.0, 60.0 };
GLfloat at[3] = { 0.0, 0.0, 0.0 };
GLfloat up[3] = { 0.0, 1.0, 0.0 };

GLuint old_thetaW3 = 0;
GLuint old_thetaX4 = 0;
GLuint old_thetaE5 = 0;
GLuint old_thetaC6 = 0;
GLuint old_thetaS11 = 0;
GLuint old_thetaD12 = 0;
GLint selection = 0;

static GLint choise = 2;
static GLint m_choise = 0;


GLfloat		yrot;				// Y Rotation
GLfloat		walkbias = 0;
GLfloat		walkbiasangle = 0;
GLfloat		lookupdown = 0.0f;
const float piover180 = 0.0174532925f;
float		heading;
float		xpos;
float		zpos;
GLfloat		ratio = 1.0;
Camera		camera;
int isTopViewActive = 0;

//--------------------------------Display area for mouse conrol-------------------
void area_update(Area* area, int update)
{
	if (selection != area->id)
		return;

	area->value += update * area->step;

	if (area->value < area->min)
		area->value = area->min;
	else if (area->value > area->max)
		area->value = area->max;

}

int area_hit(Area* area, int x, int y)
{
	if ((x > 0 && x < WINDOW_WIDTH) &&
		(y > 0 && y < WINDOW_HEIGHT))
		return area->id;
	return 0;
}

int old_y, old_x;

void mouse(int button, int state, int x, int y)
{
	selection = 0;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
		&& (m_choise == 0 || m_choise == 2)) {
		selection += area_hit(&translation[0], x, y);
		if (m_choise == 0) selection += area_hit(&translation[0], x, y);
		if (m_choise == 2) selection += area_hit(&translation[3], x, y);
		old_x = x;
		my_idle();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN
		&& ((m_choise == 0 || m_choise == 1) || m_choise == 2)) {
		if (m_choise == 0) selection += area_hit(&translation[1], x, y);
		if (m_choise == 1) selection += area_hit(&translation[2], x, y);
		if (m_choise == 2) selection += area_hit(&translation[4], x, y);
		old_y = y;
		my_idle();
	}
}

void pressed_mouse(int x, int y)
{
	area_update(&translation[0], x - old_x);
	area_update(&translation[1], old_y - y);
	area_update(&translation[2], old_y - y);
	area_update(&translation[3], x - old_x);
	area_update(&translation[4], old_y - y);
	old_y = y;
	old_x = x;

	my_idle();
}

//--------------------------------Keyboard control function-----------------------

// Keyboard input processing routine.
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{

	// if Esc -> Exit the program
	case 27:
		exit(0);
		break;
	
	// If SPACE -> activate top view
	case 32:

		// If need to disable top view
		if (isTopViewActive) {
			camera.topViewDisable();
			isTopViewActive = 0;
		}
		else {
			camera.topView();
			isTopViewActive = 1;
		}

		break;

	// move forward.
	case 'W':
	case 'w': 
		if (!isTopViewActive) // If top view is not active
			camera.moveForward();
		break;

	// move backward.
	case 'S':
	case 's': 
		if (!isTopViewActive) // If top view is not active
			camera.moveBackward();
		break;

	//// move left.
	//case 'A':
	//case 'a': 
	//	if (!isTopViewActive) // If top view is not active
	//		camera.moveLeft();
	//	break;

	//// move right.
	//case 'D':
	//case 'd': 
	//	if (!isTopViewActive) // If top view is not active
	//		camera.moveRight();
	//	break;

	// default - do nothing
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void special_key_input(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		camera.lookLeft();
	}

	if (key == GLUT_KEY_RIGHT)
	{
		camera.lookRight();
	}

	if (key == GLUT_KEY_DOWN)
	{
		if (!isTopViewActive) // If top view is not active
			camera.lookDown();
	}

	if (key == GLUT_KEY_UP)
	{
		if (!isTopViewActive) // If top view is not active
			camera.lookUp();
	}

	if (key == GLUT_KEY_PAGE_UP)
	{
		if (!isTopViewActive) // If top view is not active
			camera.moveUp();
	}

	if (key == GLUT_KEY_PAGE_DOWN)
	{
		if (!isTopViewActive) // If top view is not active
			camera.moveDown();
	}

	glutPostRedisplay();
}

// This method occurs every time the window change its size
void change_size(int w, int h)	{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) {
		h = 1;
	}

	ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); // Load the matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(45, ratio, 1, OUTSIDE_EDGE);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// 1. camera position vector
	// 2. point of look vector
	// 3. up vector
	gluLookAt(camera.getX(),
			  camera.getY(),
			  camera.getZ(),
			  camera.getX() + camera.getCenterX(),
			  camera.getY() + camera.getCenterY(),
			  camera.getZ() + camera.getCenterZ(),
			  0.0,
			  1.0,
			  0.0);
}


//--------------------------------Reshape & redisplay functions-------------------
//void change_size(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-30.0, 30.0, -30.0 * (GLfloat)h / (GLfloat)w,
//		30.0 * (GLfloat)h / (GLfloat)w, -200, 200);
//	else
//		glOrtho(-30.0 * (GLfloat)w / (GLfloat)h,
//		30.0 * (GLfloat)w / (GLfloat)h, -30.0, 30.0, -200, 200);
//
//	gluPerspective(1.0, (float)w / h, 2.0, 1.0);
//	gluLookAt(translation[3].value, translation[4].value, eye[2],
//		at[0], at[1], at[2], up[0], up[1], up[2]);
//	glTranslatef(translation[0].value, translation[1].value,
//		translation[2].value);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}

//{
//	if (key == 'q') { choise = 2; }		// Head horiz
//	if (key == 'a') { choise = 1; }		// Head vert
//
//	if (key == 'w') { choise = 3; }	//left arm horiz
//	if (key == 's') { choise = 11; }		//left arm vert
//
//	if (key == 'e') { choise = 5; }	//right arm horiz
//	if (key == 'd') { choise = 12; }		//right arm horiz
//
//	if (key == 'r') { choise = 7; }		//left leg vert
//	if (key == 'f') { choise = 13; }	//left leg horiz
//
//	if (key == 't') { choise = 9; }		//right leg horiz
//	if (key == 'g') { choise = 14; }	//right leg vert
//
//	if (key == 'z') { choise = 0; }		//torso
//
//	if (key == 'x') { choise = 4; }		//left_lower_arm
//
//	if (key == 'c') { choise = 6; }		//right_lower_arm
//
//	if (key == 'v') { choise = 8; }		//left_lower_leg
//
//	if (key == 'b') { choise = 10; }	//right_lowerleg
//
//	if (key == ',') { choise = 15; }	//left_foot
//
//	if (key == '.') { choise = 16; }	//right_foot
//
//	if (key == 'm') { glutTimerFunc(100, timer_walk, 0); }	//animation walk
//
//	if (key == 'n') {
//		old_thetaW3 = theta[3];
//		old_thetaX4 = theta[4];
//		old_thetaE5 = theta[5];
//		old_thetaC6 = theta[6];
//		old_thetaS11 = theta[11];
//		old_thetaD12 = theta[12];
//
//		theta[3] = 0;	// 0-30
//		theta[4] = 0;	// 0
//		theta[11] = -15;	// 0
//		theta[5] = 60;	// 0
//		theta[6] = -120;	// 0
//		theta[12] = 15;	// 0
//		glutTimerFunc(200, timer_kick, 0);/*glutTimerFunc(100,timer_kick,0);*/
//	}	//animation kick
//
//	if (key == '9') {
//		theta[choise] += 5.0;
//		if (theta[choise] > 360.0) theta[choise] -= 360.0;
//		glutPostRedisplay();
//	}
//	if (key == '0') {
//		theta[choise] -= 5.0;
//		if (theta[choise] < 360.0) theta[choise] += 360.0;
//		glutPostRedisplay();
//	}
//}