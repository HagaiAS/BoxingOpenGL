#pragma once
#include "Globals.h"
#include "Input.h"

//------------------------------------------------
//                INITIALIZTION
//------------------------------------------------
void my_init(void)
{
	// Background color = black
	glClearColor(0, 0, 0, 1);

	// Define the light source
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHT0_DIFFUSE);
	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT0_POSITION);
	glShadeModel(GL_SMOOTH);

	// Turn on the lights
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Read all texture files
	readTextures(rockyTextureFiles, boxer1Textures);
	readTextures(clubberTextureFiles, boxer2Textures);
	readTextures(crowdTextureFiles, crowdTextures);
	loadTextureFromFile(worldTextureFiles[WALL_TEXTURE_ID], worldTextures, WALL_TEXTURE_ID);
	loadTextureFromFile(worldTextureFiles[FLOOR_TEXTURE_ID], worldTextures, FLOOR_TEXTURE_ID);

	// Initialize the bodies and camera
	camera.initCameraPosition();
	boxer1.init_body(boxer1Textures, false, 1., 0., 0.);
	boxer2.init_body(boxer2Textures, true, 0., 0., 1.);
	crowd.init_body(crowdTextures, false);

	// Set the materials to be tracked by the color
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Define the textures to replace the color of the objects
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	// Define the matrix and 3D mode
	glOrtho(LEFT_EDGE, RIGHT_EDGE, BOTTOM_EDGE, TOP_EDGE, OUTSIDE_EDGE, INSIDE_EDGE); // 3D axes definition
	glEnable(GL_DEPTH_TEST);  //for 3D work
}
//------------------------------------------------
//                Init FUNCTIONS
//------------------------------------------------
void View_Init(void)
{
	//glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-25, 25, -25, 25, -25, 25);
	glMatrixMode(GL_MODELVIEW);
}
//
//void Init_View_Mode()
//{
//	// View Mode subwindow 
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	viewMode = glutCreateSubWindow(parent, 5, 5, WINDOW_WIDTH, WINDOW_HEIGHT);   //---View Mode gets 2 
//	View_Init();
//	glutDisplayFunc(Display_View_Mode);
//	glutKeyboardFunc(keyboard);	// keyboard callback
//}
//
//void Init_View_Play()
//{
//	// Play Mode subwindow 
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	playMode = glutCreateSubWindow(parent, 5, 5, WINDOW_WIDTH, WINDOW_HEIGHT); //---Play Mode gets 3
//	View_Init();
//	glutDisplayFunc(Display_Play_Mode);
//	glutSpecialFunc(special_key_input);
//	glutKeyboardFunc(keyboard);  // keyboard callback
//}

void Init_Help_Menu()
{
	// Menu side sub window 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	sideHelpMenu = glutCreateSubWindow(parent, 0, 0, WINDOW_WIDTH, WINDOW_WIDTH);  //---help menu gets 4
	View_Init();
	glutDisplayFunc(Display_Help);
	glutSpecialFunc(special_key_input);
	glutKeyboardFunc(keyboard);  // keyboard callback
}

void Init_Parent()
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Define the window size and position on the screen
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	parent = glutCreateWindow("Boxing - by Harel Ezra & Hagai Asaban");

	// Initialize everything
	my_init();
	// Set the menu options
	glutCreateMenu(my_menu);
	glutAddMenuEntry("1.Lights - ON/OFF", 1);
	glutAddMenuEntry("2.Boxers animation - ON/OFF", 2);
	glutAddMenuEntry("3.Crowd animation - ON/OFF", 3);
	glutAddMenuEntry("4.Slow motion! - ON/OFF", 4);
	glutAddMenuEntry("5.Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Set display function and timer function (the changes every loop)
	glutDisplayFunc(my_display);
	glutTimerFunc(TIMERMSECS, make_delay, 1);

	// Define keyboard input
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_key_input);
	glutReshapeFunc(change_size);
}

void Init_Intro()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// Define the window size and position on the screen
	intro = glutCreateSubWindow(parent, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	View_Init();
	glutDisplayFunc(Display_Intro);
	glutSpecialFunc(special_key_input);
	glutKeyboardFunc(keyboard);	 // keyboard callback
}