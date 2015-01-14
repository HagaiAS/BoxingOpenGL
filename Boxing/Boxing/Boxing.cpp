//		  Boxing.cpp
// Harel Ezra , Hagai Asaban
//------------------------------------------------
#include "Entrance.h"
#include "Arena.h"
#include "Tribune.h"
#include "World.h"
#include "Boxers.h"
#include "Crowd.h"
#include "Camera.h"
#include "Globals.h"
#include "RgbImage.h"

void my_init(void);
void my_display(void);
void make_delay(int);
void my_idle(void);
void printInstructions(void);
void keyboard(unsigned char, int, int);
void special_key_input(int, int, int);
void change_size(int, int);
void my_menu(int);
void clapHands();
void moveHandsUp();
void loadTextureFromFile(char*, GLuint*, GLuint);
void readTextures(char**, GLuint*);
void showScene();

using std::cout;
using std::endl;

Boxers boxer1(BoxerAng1);
Boxers boxer2(BoxerAng2);
Crowd crowd;
Camera camera;

// Animation variables
GLfloat boxersDistance = ARENA_SIZE_B / 2;
GLfloat boxersAngleY = 45.;
GLfloat boxersAngleZ = 0.;
GLfloat boxersAngleDeltaZ = 7.5;

GLfloat BOXER_RED_X = 0.;
GLfloat BOXER_RED_Y = FLOOR_Y_B;
GLfloat BOXER_RED_Z = -boxersDistance;

GLfloat BOXER_BLUE_X = 0.;
GLfloat BOXER_BLUE_Y = FLOOR_Y_B;
GLfloat BOXER_BLUE_Z = boxersDistance;

GLfloat BOXER_RED_MOVING_SPEED = 3.0;
GLfloat BOXER_BLUE_MOVING_SPEED = -3.0;

int BOXER_RED_DIRECTION = 1;
int BOXER_BLUE_DIRECTION = -1;

GLfloat BOXERS_ANGLE_SPEED = 0.6;
GLfloat CLAPPING_SPEED = 10.0;
GLfloat HANDS_UP_SPEED = 5.0;

bool knockoutPart = false;
bool walkingPart = true;
bool fightingPart = false;
bool isAutoCameraOn = true; // whether to change camera views during the scene
float currTime = 0.0;

// For the camera and display
GLfloat	ratio = 1.0;
bool isTopViewActive = false;

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

// For the menu
bool lightsOn = true;
bool boxersAnimationOn = true;
bool crowdAnimationOn = true;
bool topViewOn = false;
bool slowMotionOn = false;
int timerSeconds = TIMERMSECS;

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
//                DRAWING FUNCTIONS
//------------------------------------------------

// This method display rotating man
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

//------------------------------------------------
//                TEXTURES FUNCTIONS
//------------------------------------------------

// This method load the textures from all files and updates the id of each texture
void readTextures(char** fileNames, GLuint* textures)
{
	for (int currTexture = 0; currTexture < NUM_OF_BODY_TEXTURES; currTexture++)
	{
		loadTextureFromFile(fileNames[currTexture], textures, currTexture);
	}
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

//------------------------------------------------
//                ANIMATION FUNCTIONS
//------------------------------------------------

// This method handles the animations of the objects and the delay of movement
void make_delay(int)
{
	my_idle();
	
	showScene();

	glutTimerFunc(timerSeconds, make_delay, 1);
}

// This method change the angles for each draw
void my_idle(void)
{
	// If need to animate the boxers
	if (boxersAnimationOn)
	{
		// If need to walk
		if (!knockoutPart) {
			
			// Move the boxer legs infinity
			boxer1.animate_boxer_walk();
			boxer2.animate_boxer_walk();
		}

		if (fightingPart) {			
			boxer1.animate_boxer_fight();
			boxer2.animate_boxer_fight();
		}
	}

	// If need to animate the crowd
	if (crowdAnimationOn)
	{
		// Move clapping hands
		clapHands();

		// Move hands up and down
		moveHandsUp();
	}

	// Call redisplay again
	glutPostRedisplay();
}

// This method show the scene by 3 parts, the last part of the scene is limitless
void showScene()
{
	GLfloat redBoxerZ = BOXER_RED_Z + BOXER_RED_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
	GLfloat redBoxerX = BOXER_RED_X + BOXER_RED_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
	GLfloat blueBoxerZ = BOXER_BLUE_Z + BOXER_BLUE_MOVING_SPEED + (BOXER_BLUE_DIRECTION * TORSO_RADIUS);
	GLfloat blueBoxerX = BOXER_BLUE_X + BOXER_BLUE_MOVING_SPEED + (BOXER_BLUE_DIRECTION * TORSO_RADIUS);

	// If its the first part of the scene - THE MATCH STARTS
	if (currTime <= TIME_PART * 1/3)
	{
		// If change camera automatically
		if (isAutoCameraOn) {
			
		}

		// If the boxers distance is above the minimal distance 
		if ( (abs(redBoxerZ-blueBoxerZ) >= BOXERS_MIN_DISTANCE) &&
			 (abs(redBoxerX-blueBoxerX) >= BOXERS_MIN_DISTANCE) )
		{
			// If the red boxer is inside the arena - move it
			if (((ARENA_SIZE / 2) >= abs(redBoxerZ)) &&
				((ARENA_SIZE / 2) >= abs(redBoxerX)))
			{
				BOXER_RED_Z += BOXER_RED_MOVING_SPEED;
			}
			else
			{
				// Change red boxer moving direction
				BOXER_RED_DIRECTION *= -1;
				BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;
			}

			// If the blue boxer is inside the arena - move it
			if (((ARENA_SIZE / 2) >= abs(blueBoxerZ)) &&
				((ARENA_SIZE / 2) >= abs(blueBoxerX)))
			{
				BOXER_BLUE_Z += BOXER_BLUE_MOVING_SPEED;
			}
			else
			{
				// Change blue boxer moving direction
				BOXER_BLUE_DIRECTION *= -1;
				BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
			}
		}
		else
		{
			// Turn the boxers a little bit
			boxersAngleY += BOXERS_ANGLE_SPEED;
			if ((boxersAngleY > 60.) || (boxersAngleY < 45.)) {
				BOXERS_ANGLE_SPEED *= -1;
			}
		}
	}
	else if (currTime <= TIME_PART * 2)
	{
		// This is the second part of the scene - THE FIGHT
		if (!fightingPart) {
			BOXER_RED_DIRECTION *= -1;
			BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;
			BOXER_BLUE_DIRECTION *= -1;
			BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
		}

		walkingPart = false;
		fightingPart = true;
		redBoxerZ = BOXER_RED_Z + BOXER_BLUE_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
		redBoxerX = BOXER_RED_X + BOXER_BLUE_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);

		// Move the boxers in the arena together

		// If the red and blue boxer are inside the arena - move them together
		if ( ((ARENA_SIZE / 2.4) >= abs(redBoxerZ)) &&
			 ((ARENA_SIZE / 2.4) >= abs(redBoxerX)) &&
			 ((ARENA_SIZE / 2.4) >= abs(blueBoxerZ)) &&
			 ((ARENA_SIZE / 2.4) >= abs(blueBoxerX)) )
		{
			BOXER_RED_Z += BOXER_BLUE_MOVING_SPEED;
			BOXER_BLUE_Z += BOXER_BLUE_MOVING_SPEED;

			// Turn the boxers a little bit
			
			if ((boxersAngleY >= 100.) || (boxersAngleY <= -60.)) {
				BOXERS_ANGLE_SPEED *= -1;
			}
			boxersAngleY += BOXERS_ANGLE_SPEED;
		}
		else
		{
			// Change red boxer moving direction
			BOXER_RED_DIRECTION *= -1;
			BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;

			// Change blue boxer moving direction
			BOXER_BLUE_DIRECTION *= -1;
			BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
		}
	}
	else 
	{
		// This is the third part of the scene - THE KNOCKOUT
		fightingPart = false;

		// Throw knockout punch
		//boxer1.animate_boxer_fight();

		// If rocky is inside the arena
		if (abs(BOXER_RED_Z) < ARENA_SIZE / 3)
		{
			knockoutPart = true;

			// Move away from falling clubber
			BOXER_RED_Z -= BOXER_BLUE_MOVING_SPEED;
		}

		// Knockdown clubber boxer
		if (boxersAngleZ > -90.)
		{
			boxersAngleZ -= boxersAngleDeltaZ;
		}
		else
		{
			BoxerAng1[3] = -30;
			BoxerAng1[4] = -30;
			BoxerAng1[5] = -30;
			BoxerAng1[6] = -30;
			boxer1.animate_boxer_winning();
		}
	}

	// If the scene is not over
	if (currTime < SCENE_TOTAL_SEC)
	{ 
		// Increment time and continue with scene
		currTime += TIME_DELTA;
	}
}

// This method clap the crowd hands
void clapHands()
{
	// Move clapping hands
	if ((crowdAnglesClapping[4] < -30) || (crowdAnglesClapping[4] > 0)) {
		CLAPPING_SPEED *= -1;
	}

	crowdAnglesClapping[4] += CLAPPING_SPEED;
	crowdAnglesClapping[6] += CLAPPING_SPEED; 
}

// This method move the crowd hands up and down
void moveHandsUp()
{
	// Move hands up and down
	if ((crowdAnglesUpArms[3] > 40) || (crowdAnglesUpArms[3] < -100)) {
		HANDS_UP_SPEED *= -1;
	}

	crowdAnglesUpArms[3] += HANDS_UP_SPEED;
	crowdAnglesUpArms[5] += HANDS_UP_SPEED;
}

//---------------------------------------------------------
//               INPUTS - KEYBOARD, MENU AND INSTRUCTIONS
//---------------------------------------------------------

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

//-------------------------------------
//               MAIN
//-------------------------------------

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

	// Infinite loop
	glutMainLoop();
}