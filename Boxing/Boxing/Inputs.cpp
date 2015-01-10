//================================Mouse====================================
#include "Inputs.h"
#include "Camera.h"
#include "Body.h"

GLfloat		ratio = 1.0;
Camera		camera;
int isTopViewActive = 0;

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