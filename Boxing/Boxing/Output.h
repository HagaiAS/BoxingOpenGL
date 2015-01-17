#pragma once
#include "Globals.h"
#include "Camera.h"
#include "Animation.h"
#include "Views.h"

using std::cout;
using std::endl;

int intro = 0;
int viewMode = 0;
int playMode = 0;
int sideHelpMenu = 0;
int parent = 0;

bool introHidden = false;
bool viewModeHidden = true;
bool playModeHidden = true;
bool helpMenuHidden = true;
bool parentHidden = false;

Camera camera;
// For the camera and display
GLfloat	ratio = 1.0;
bool isTopViewActive = false;

//------------------------------------------------
//                DRAWING FUNCTIONS
//------------------------------------------------

void my_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //DEPTH_BUFFER

	// Draw all objects
	//draw_axes();
	draw_world();
	draw_lamp();
	draw_tribunes();
	draw_arena();
	draw_entrance();
	crowd.draw_crowds(crowdAnglesClapping, crowdAnglesUpArms);
	boxer1.draw_boxer(boxersAngleY, 0., BOXER_RED_X, BOXER_RED_Y, BOXER_RED_Z);
	boxer2.draw_boxer(boxersAngleY, boxersAngleZ, BOXER_BLUE_X, BOXER_BLUE_Y, BOXER_BLUE_Z);

	glutSwapBuffers(); // for animation
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

	camera.updateView();
}


void Display_Parent(void)
{
	if (!parentHidden)
	{
		glClearColor(0.0, 0.8, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
}
void Display_Intro(void)
{
	if (!introHidden)
	{
		glClearColor(0.0, 0.8, 0.8, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		WelcomeIntroWindow();
		glutSwapBuffers();
	}
}
void Display_View_Mode(void)
{
	if (!viewModeHidden)
	{
		glClearColor(1, 0.5, 0, 1);  //orange
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//ViewModeSubWindow();
		glutSwapBuffers();
	}
}

void Display_Play_Mode(void)
{
	if (!playModeHidden)
	{
		glClearColor(0, 0, 1, 1); //black
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//PlayModeSubWindow();		
		glutSwapBuffers();
	}
}

void Display_Help()
{
	if (!helpMenuHidden)
	{
		glClearColor(0.8, 0.8, 0.8, 1); //gray
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		HelpSubWindow();
		glutSwapBuffers();
	}
}

void SwitchWindows(View activeView)
{
	switch (activeView)
	{
	case Parent:

		parentHidden = !parentHidden;

		if (!parentHidden)
		{
			introHidden = true;
			viewModeHidden = true;
			playModeHidden = true;
			helpMenuHidden = true;
		}

		Display_Parent();
		break;
	case Intro:

		introHidden = !introHidden;

		if (!introHidden)
		{
			parentHidden = true;
			viewModeHidden = true;
			playModeHidden = true;
			helpMenuHidden = true;
		}

		Display_Intro();
		break;

	case ViewMode:

		viewModeHidden = !viewModeHidden;

		if (!viewModeHidden)
		{
			parentHidden = false;
			helpMenuHidden = true;
			introHidden = true;
			boxersAnimationOn = false;
			crowdAnimationOn = false;
		}
		Display_Intro();
		Display_View_Mode();
		break;

	case PlayMode:

		playModeHidden = !playModeHidden;

		if (!playModeHidden)
		{
			parentHidden = false;
			introHidden = true;
			viewModeHidden = true;
			helpMenuHidden = true;
			boxersAnimationOn = true;
			crowdAnimationOn = true;
		}
		Display_Intro();
		Display_Play_Mode();

		break;
	case SideHelpMenu:

		helpMenuHidden = !helpMenuHidden;
		
		if (!helpMenuHidden)
		{	
			parentHidden = false;
			introHidden = true;
			viewModeHidden = true;
			playModeHidden = true;
		}
		Display_Intro();
		Display_Help();

		break;

	default:
		break;
	}
}
//
//void my_kill_wnd(unsigned char key, int x, int y)
//{
//	if (key == '1' && viewMode)
//	{
//		glutDestroyWindow(viewMode);
//		viewMode = 0;  //if we closed ViewMode window, ViewMode gets 0
//	}
//
//	if (key == '2' && playMode)
//	{
//		glutDestroyWindow(playMode);
//		playMode = 0;  //if we closed PlayMode window, PlayMode gets 0
//	}
//
//	if ((key == 'h' && sideHelpMenu) || (key == 'H' && sideHelpMenu))
//	{
//		glutDestroyWindow(sideHelpMenu);
//		sideHelpMenu = 0;  //if we closed sideHelpMenu window, sideHelpMenu gets 0
//	}
//
//	if (key == '0' && parent)
//	{
//		glutDestroyWindow(parent);
//		parent = 0;
//		exit(1);
//	}
//
//	Display_Parent();
//}


// This method output the instructions to the C++ window
void printInstructions()
{
	cout << "Instructions:" << endl;
	cout << "Press the left/right/up/down arrow keys to look at the specific direction." << endl
		<< "Press SPACE to activate top view." << endl
		<< "Press W/S to move forward/backward." << endl
		//<< "Press A/D to move left/right." << endl
		<< "Press PAGE UP/PAGE DOWN to move up/down." << endl
		<< endl
		<< "In animate mode:" << endl
		<< "Press the up/down arrow keys to speed up/slow down animation." << endl;
}

