#pragma once
#include "Globals.h"
#include "Output.h"

//---------------------------------------------------------
//               INPUTS - KEYBOARD, MENU AND INSTRUCTIONS
//---------------------------------------------------------

// Keyboard input processing routine.
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{

		// 
	case 27:
		SwitchWindows(Intro);
		break;

		//move forward.
	case 'H':
	case 'h':
		SwitchWindows(SideHelpMenu);
		break;

		// If SPACE -> activate top view
	case 32:

		// If need to disable top view
		if (isTopViewActive) {
			camera.topViewDisable();
			isTopViewActive = false;
		}
		else {
			camera.topView();
			isTopViewActive = true;
		}
		break;

		// If 1 -> activate camera side view
	case '1':
		if (!isTopViewActive) // If top view is not active
			camera.sideView();
		break;

		// If 2 -> activate camera rocky view
	case '2':
		if (!isTopViewActive) // If top view is not active
			camera.rockyView();
		break;

		// If 3 -> activate camera clubber view
	case '3':
		if (!isTopViewActive) // If top view is not active
			camera.clubberView();
		break;

		// If 4 -> activate camera crowd view
	case '4':
		if (!isTopViewActive) // If top view is not active
			camera.crowdView();
		break;

		// If 5 -> activate camera corner view
	case '5':
		if (!isTopViewActive) // If top view is not active
			camera.cornerView();
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

	if (key == GLUT_KEY_F1)
	{

		SwitchWindows(ViewMode);

	}
	if (key == GLUT_KEY_F2)
	{
		SwitchWindows(PlayMode);
	}

	if (key == GLUT_KEY_F4)
	{
		exit(0);
	}

	glutPostRedisplay();
}

// This method handles the user's selected options
void my_menu(int id)
{
	// Turn lights on/off
	if (id == 1) {
		if (lightsOn) {
			glDisable(GL_LIGHT0);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			lightsOn = false;
		}
		else {
			glEnable(GL_LIGHT0);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			lightsOn = true;
		}
	}

	// Turn boxer animation on/off
	if (id == 2) {
		if (boxersAnimationOn)
			boxersAnimationOn = false;
		else
			boxersAnimationOn = true;
	}

	// Turn crowd animation on/off
	if (id == 3) {
		if (crowdAnimationOn)
			crowdAnimationOn = false;
		else
			crowdAnimationOn = true;
	}

	// Turn slow motion on/off
	if (id == 4) {
		if (slowMotionOn) {
			timerSeconds = TIMERMSECS;
			slowMotionOn = false;
		}
		else {
			timerSeconds = TIMERMSECS * 4;
			slowMotionOn = true;
		}
	}

	// Exit the program
	if (id == 5) exit(0);
}
