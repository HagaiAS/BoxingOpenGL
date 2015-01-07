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
#include "ImageLoader.h"
#include "RgbImage.h"

void my_init(void);
void my_display(void);
void make_delay(int);
void my_idle(void);
void printInstructions(void);
void clapHands();
void moveHandsUp();
void loadTextureFromFile(char*, GLuint*, GLuint);
void readTextures(char**, GLuint*);

using std::cout;
using std::endl;

Boxers boxer1(BoxerAng1);
Boxers boxer2(BoxerAng2);
Crowd crowd;

// Animation variables
GLfloat BOXER_RED_MOVING_X = 0.;
GLfloat BOXER_RED_MOVING_SPEED = 4.0;
GLfloat BOXER_BLUE_MOVING_X = 0.;
GLfloat BOXER_BLUE_MOVING_SPEED = 5.0;
GLfloat CLAPPING_SPEED = 10.0;
GLfloat HANDS_UP_SPEED = 5.0;

// The textures id and files
GLuint worldTextures[NUM_OF_WORLD_TEXTURES];
GLuint boxer1Textures[NUM_OF_BODY_TEXTURES];
GLuint boxer2Textures[NUM_OF_BODY_TEXTURES];
GLuint crowdTextures[NUM_OF_BODY_TEXTURES];

char* worldTextureFiles[NUM_OF_WORLD_TEXTURES] = { "./wallTile.bmp",
												   "./floorTile.bmp" };
char* rockyTextureFiles[NUM_OF_BODY_TEXTURES] = { "./rockyHead.bmp",
												"./rockyBody.bmp",
												"./rockyHand.bmp",
												"./-.bmp",
												"./rockySkin.bmp",
												"./rockyShorts.bmp" };
char* clubberTextureFiles[NUM_OF_BODY_TEXTURES] = { "./clubberHead.bmp",
												"./clubberBody.bmp", 
												"./clubberHand.bmp",
												"./-.bmp",
												"./clubberSkin.bmp",
												"./clubberShorts.bmp" };
char* crowdTextureFiles[NUM_OF_BODY_TEXTURES] = { "./-.bmp",
												"./-.bmp",
												"./-.bmp",
												"./-.bmp",
												"./-.bmp",
												"./-.bmp" };

GLfloat crowdAnglesClapping[17] =
{
	0.0, 0.0, 0.0, // torso, neckX, neckY
	10.0, -30.0, // left upper/lower armX
	10.0, -30.0, // right upper/lower armX
	90.0, 90.0, // left upper/lower legX
	90.0, 90.0, // right upper/lower legX
	-55.0, 55.0, // left upper / right upper armZ
	0.0, 0.0, // left upper / right upper legZ
	20.0, 20.0 // left / right footX
};

GLfloat crowdAnglesUpArms[17] =
{
	0.0, 0.0, 0.0, // torso, neckX, neckY
	40.0, 0.0, // left upper/lower armX
	40.0, 0.0, // right upper/lower armX
	90.0, 90.0, // left upper/lower legX
	90.0, 90.0, // right upper/lower legX
	0.0, 0.0, // left upper / right upper armZ
	0.0, 0.0, // left upper / right upper legZ
	20.0, 20.0 // left / right footX
};

//--------------------------------Initialization function-------------------------
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

	// Initialize the bodies
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
//                DRAWING FUNCTIONS
//------------------------------------------------
// This method display rotating man
void my_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //DEPTH_BUFFER

	// Draw all objects
	draw_axes();
	draw_world();
	draw_lamp();
	draw_tribunes();
	draw_arena();
	draw_entrance();
	crowd.draw_crowds(crowdAnglesClapping, crowdAnglesUpArms);
	boxer1.draw_boxer(BOXER_RED_MOVING_X);
	boxer2.draw_boxer(BOXER_BLUE_MOVING_X);

	glutSwapBuffers(); // for animation
}

// This method load the textures from all files and updates the id of each texture
void readTextures(char** fileNames, GLuint* textures)
{
	for (int currTexture = 0; currTexture < NUM_OF_BODY_TEXTURES; currTexture++)
	{
		loadTextureFromFile(fileNames[currTexture], textures, currTexture);
	}
}

// This method handles the animations of the objects and the delay of movement
void make_delay(int)
{
	my_idle();
	glutTimerFunc(TIMERMSECS, make_delay, 1);
}

// This method change the angles for each draw
void my_idle(void)
{
	// If the red boxer is inside the arena - move it
	if ((ARENA_SIZE / 2) >= abs(BOXER_RED_MOVING_X + BOXER_RED_MOVING_SPEED) + TORSO_RADIUS)
	{
		//BOXER_RED_MOVING_X += BOXER_RED_MOVING_SPEED;
	}
	else
	{
		// Change red boxer moving direction
		BOXER_RED_MOVING_SPEED *= -1;
	}

	// If the blue boxer is inside the arena - move it
	if ((ARENA_SIZE / 2) >= abs(BOXER_BLUE_MOVING_X + BOXER_BLUE_MOVING_SPEED) + TORSO_RADIUS)
	{
		//BOXER_BLUE_MOVING_X += BOXER_BLUE_MOVING_SPEED;
	}
	else
	{
		// Change blue boxer moving direction
		BOXER_BLUE_MOVING_SPEED *= -1;
	}

	// Move the boxer legs infinity
	boxer1.animate_boxer_walk();
	boxer2.animate_boxer_walk();
	//boxer1.animate_boxer_fight();
	//boxer2.animate_boxer_fight();

	// Move clapping hands
	clapHands();

	// Move hands up and down
	moveHandsUp();

	// Call redisplay again
	glutPostRedisplay();
}

void clapHands()
{
	// Move clapping hands
	if ((crowdAnglesClapping[4] < -30) || (crowdAnglesClapping[4] > 0)) {
		CLAPPING_SPEED *= -1;
	}

	crowdAnglesClapping[4] += CLAPPING_SPEED;
	crowdAnglesClapping[6] += CLAPPING_SPEED; 
}

void moveHandsUp()
{
	// Move clapping hands
	if ((crowdAnglesUpArms[3] > 40) || (crowdAnglesUpArms[3] < -100)) {
		HANDS_UP_SPEED *= -1;
	}

	crowdAnglesUpArms[3] += HANDS_UP_SPEED;
	crowdAnglesUpArms[5] += HANDS_UP_SPEED;
}

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

// This method read a texture map from a BMP bitmap file and insert the id into the textures list
void loadTextureFromFile(char *filename, GLuint* textures, GLuint index)
{
	RgbImage theTexMap(filename);

	// Pixel alignment: each row is word aligned (aligned to a 4 byte boundary)
	// Therefore, no need to call glPixelStore( GL_UNPACK_ALIGNMENT, ... )
	
	// Create The Texture
	glGenTextures(1, &textures[index]);					
	glBindTexture(GL_TEXTURE_2D, textures[index]);

	// Set textures parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Typical Texture Generation Using Data From The Bitmap
	glTexImage2D(GL_TEXTURE_2D, 
				 0, 
				 GL_RGB,
				 theTexMap.GetNumCols(), 
				 theTexMap.GetNumRows(), 
				 0, 
				 GL_RGB, 
				 GL_UNSIGNED_BYTE, 
				 theTexMap.ImageData());
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

	// Set display function and timer function (the changes every loop)
	glutDisplayFunc(my_display);
	glutTimerFunc(TIMERMSECS, make_delay, 1);

	//// Define mouse input
	//glutMotionFunc(pressed_mouse);
	//glutMouseFunc(mouse);

	// Define keyboard input
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_key_input);
	glutReshapeFunc(change_size);

	// Infinite loop
	glutMainLoop();
}