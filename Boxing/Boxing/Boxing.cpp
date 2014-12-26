//		  Boxing.cpp
// Harel Ezra , Hagai Asaban
//------------------------------------------------
#include "Entrance.h"
#include "Arena.h"
#include "Tribune.h"
#include "World.h"
#include "Inputs.h"
#include "Boxers.h"
#include "Crowd.h"

void my_init(void);
void my_display(void);
void my_idle(void);
void printInstructions(void);

using std::cout;
using std::endl;

Boxers boxers;
Crowd crowd;


//--------------------------------Initialization function-------------------------
void my_init(void)
{
	// This method initialize matrix and colors
	
	// Background color = black
	glClearColor(0, 0, 0, 1);

	// Define the light source
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHT0_DIFFUSE);
	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT0_POSITION);
	glShadeModel(GL_SMOOTH);

	// Turn on the lights
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); 
	
	boxers.init_body();

	// Set the materials to be tracked by the color
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Define the matrix and 3D mode
	glOrtho(LEFT_EDGE, RIGHT_EDGE, BOTTOM_EDGE, TOP_EDGE, OUTSIDE_EDGE, INSIDE_EDGE); // 3D axes definition
	glEnable(GL_DEPTH_TEST);  //for 3D work
}

// This method display rotating man
void my_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //DEPTH_BUFFER

	// Return axis to basic position
	glLoadIdentity();

	place_camera();

	draw_axes();

	glColor3ub(255, 255, 0);
	draw_world();
	draw_lamp();
	draw_tribunes();
	draw_arena();
	draw_entrance();
	crowd.draw_crowds();
	boxers.draw_boxer1();
	boxers.draw_boxer2();
	//glPushMatrix();
	//	glCallList(CROWD_LIST);		
	//	//glTranslatef(0., 0., 80.);
	//	//glRotatef(-180., 0., 1., 0.);
	//	//draw one more boxer.
	//	glCallList(CROWD_LIST);
	//glPopMatrix();
	

	glutSwapBuffers(); // for animation
}


// This method output the instructions to the C++ window
void printInstructions()
{
	cout << "Instructions:" << endl;
	cout << "Press the left/right/up/down arrow keys to move the whole world." << endl
		 << "Press [/] to rotate the viewpoint." << endl
		 << "Press +/- to zoom in/out." << endl
		 << endl
		 << "In animate mode:" << endl
		 << "Press the up/down arrow keys to speed up/slow down animation." << endl;
}

void main(int argc, char **argv)
{
	printInstructions();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Define the window size and position on the screen
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	glutCreateWindow("Boxing - by Harel Ezra & Hagai Asaban");

	// Initialize everything
	my_init();

	// Set display function and idle function (the changes every loop)
	glutDisplayFunc(my_display);
	glutIdleFunc(my_idle);

	// Define mouse input
	glutMotionFunc(pressed_mouse);
	glutMouseFunc(mouse);

	// Define keyboard input
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_key_input);
	glutReshapeFunc(change_size);

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




//void fillRandomColor() {
//
//	// Define random color
//	srand(time(NULL));
//	red = (double)(rand() % 1000) / 1000;
//	green = (double)(rand() % 1000) / 1000;
//	blue = (double)(rand() % 1000) / 1000;
//	glColor3f(red, green, blue);
//}
