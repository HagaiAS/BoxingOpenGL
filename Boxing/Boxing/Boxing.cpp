// Boxing.cpp
// Harel Ezra and Hagai Asaban
//------------------------------------------------
#include "Entrance.h"
#include "Arena.h"
#include "Tribune.h"
#include "Boxer.h"
#include "World.h"

void my_init(void);
void my_display(void);
void my_idle(void);
void printInstructions(void);

// Camera class.
class Camera
{
public:
	Camera();
	GLdouble getX();
	GLdouble getY();
	GLdouble getZ();
	GLdouble getCenterX();
	GLdouble getCenterY();
	GLdouble getCenterZ();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBackward();
	void move(GLdouble);
	void moveLeftRight(GLdouble);
	void turn(GLdouble);
	void turnUpDown(GLdouble);
	void moveLeft();
	void moveRight();
	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();
	void incrementViewDirection();
	void decrementViewDirection();
	void incrementZoomDistance() { zoomDistance += 1.0; }
	void decrementZoomDistance() { zoomDistance -= 1.0; }

	float getViewDirection() const { return viewDirection; }
	float getZoomDistance() const { return zoomDistance; }

private:
	//TODO:
	GLfloat	yrot;				// Y Rotation
	GLfloat walkbias = 0;
	GLfloat walkbiasangle = 0;
	GLfloat lookupdown = 0.0f;
	GLfloat	zm = 0.0f;				// Depth Into The Screen



	float viewDirection;
	float zoomDistance;
	GLdouble x, y, z, lasty, lastx;
	GLdouble centerX, centerY, centerZ;
	GLdouble angle, angleUpDown;
	GLdouble zoomSpeed;
	GLdouble rotatingSpeed;
	GLdouble movingSpeed;
	GLdouble movingUpDownSpeed;
};

// Global camera.
Camera camera;

// Camera constructor.
Camera::Camera()
{
	viewDirection = 0.0;
	zoomDistance = 30.0;
	zoomSpeed = 0.15;

	x = 0;
	y = 102;
	z = 0;
	
	centerX = 30;
	centerY = 0;
	centerZ = 100;

	angle = 0.0;
	angleUpDown = 0.0;
	rotatingSpeed = 0.08;
	movingSpeed = 1.15;
	movingUpDownSpeed = 1.1;
}

// Function to increment camera viewing angle.
void Camera::incrementViewDirection()
{

	float direction = 1;
	float ydelta = lasty - y;
	
	if (ydelta > 0) {
		direction = -1;
	} else {
		direction = 1;
	}

	lasty = y;

	if (direction > 0) {
		x += x*zoomSpeed;
		y += y*zoomSpeed;
		z += z*zoomSpeed;
	} else {
		x -= x*zoomSpeed;
		y -= y*zoomSpeed;
		z -= z*zoomSpeed;
	}

	lasty = y;
	lastx = x;

	//viewDirection += 5.0;
	//if (viewDirection > 360.0) viewDirection -= 360.0;
}

// Function to decrement camera viewing angle.
void Camera::decrementViewDirection()
{
	viewDirection -= 5.0;
	if (viewDirection < 0.0) viewDirection += 360.0;
}

void Camera::moveUp()
{
	y += movingUpDownSpeed;
}

void Camera::moveDown()
{
	y -= movingUpDownSpeed;
}

void Camera::moveLeft()
{
	moveLeftRight(3);
}

void Camera::moveRight()
{
	moveLeftRight(-3);
}

void Camera::moveForward()
{
	move(1);
}

void Camera::moveBackward()
{
	move(-1);
}

void Camera::move(GLdouble direction)
{
	x += direction * centerX * movingSpeed;
	z += direction * centerZ * movingSpeed;
}

void Camera::moveLeftRight(GLdouble direction)
{
	x += direction * movingSpeed;
}

void Camera::turnUp()
{
	turnUpDown(rotatingSpeed);
}

void Camera::turnDown()
{
	turnUpDown(-rotatingSpeed);
}

void Camera::turnRight()
{
	turn(rotatingSpeed);
}

void Camera::turnLeft()
{
	turn(-rotatingSpeed);
}

void Camera::turn(GLdouble direction)
{
	angle += direction;
	centerX = sin(angle);
	centerZ = -cos(angle);
}

void Camera::turnUpDown(GLdouble direction)
{
	angle += direction;
	centerY = sin(angle);
	centerZ = -cos(angle);
}

GLdouble Camera::getX()
{
	return x;
}

GLdouble Camera::getY()
{
	return y;
}

GLdouble Camera::getZ()
{
	return z;
}

GLdouble Camera::getCenterX()
{
	return centerX;
}

GLdouble Camera::getCenterY()
{
	return centerY;
}

GLdouble Camera::getCenterZ()
{
	return centerZ;
}

using std::cout;
using std::endl;

// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------

GLfloat	yrot;				// Y Rotation
GLfloat walkbias = 0;
GLfloat walkbiasangle = 0;
GLfloat lookupdown = 0.0f;
const float piover180 = 0.0174532925f;
float heading;
float xpos;
float zpos;
GLfloat ratio = 1.0;

// This method initialize matrix and colors
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

	// Place camera
	// 1. camera position vector
	// 2. point of look vector
	// 3. up vector (tilt of camera)
	gluLookAt(	camera.getX(), camera.getY(), camera.getZ(),
				//camera.getZoomDistance() * cos(camera.getViewDirection()*Pi / 180.0),
				camera.getX() + camera.getCenterX(), 
				camera.getY() + camera.getCenterY(),
				camera.getZ() + camera.getCenterZ(),
				0.0, 1.0, 0.0);

	GLfloat x_m, y_m, z_m, u_m, v_m;
	GLfloat xtrans = -xpos;
	GLfloat ztrans = -zpos;
	GLfloat ytrans = -walkbias - 0.25f;
	GLfloat sceneroty = 360.0f - yrot;
	glRotatef(lookupdown, 1.0f, 0, 0);
	glRotatef(sceneroty, 0, 1.0f, 0);

	glTranslatef(xtrans, ytrans, ztrans);
	// Rotate the whole man parts together anticlockwise
	//glRotatef(body_angle, 0., 1., 0.);

	draw_axes();

	glColor3ub(255, 255, 0);
	draw_world();
	draw_lamp();
	draw_tribunes();
	draw_arena();
	draw_entrance();
	//draw_boxer();

	glutSwapBuffers(); // for animation
}

// This method change the angles for each draw
void my_idle(void)
{
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
	case 'w': // move forward.
		camera.moveForward();
		break;
	case 's': // move backward.
		camera.moveBackward();
		break;
	case 'a': // move left.
		camera.moveLeft();
		break;
	case 'd': // move right.
		camera.moveRight();
		break;


		// TODO: check this
	case 'c':
		{

			xpos -= (float)sin(heading*piover180) * 5.5f;
			zpos -= (float)cos(heading*piover180) * 5.5f;
			if (walkbiasangle >= 359.0f)
			{
				walkbiasangle = 0.0f;
			}
			else
			{
				walkbiasangle += 10;
			}
			walkbias = (float)sin(walkbiasangle * piover180) / 20.0f;
			break;
		}

	case 'v':
		{
			xpos += (float)sin(heading*piover180) * 5.5f;
			zpos += (float)cos(heading*piover180) * 5.5f;
			if (walkbiasangle <= 1.0f)
			{
				walkbiasangle = 359.0f;
			}
			else
			{
				walkbiasangle -= 10;
			}
			walkbias = (float)sin(walkbiasangle * piover180) / 20.0f;
			break;
		}

	case 'b': // turn left
		{
			heading -= 1.0f;
			yrot = heading;
			break;
		}

	case 'n': // turn right
		{
			heading += 1.0f;
			yrot = heading;
			break;
		}

	case 'm': // look up
		{
			lookupdown -= 1.0f;
			break;
		}

	case ',': // look down
		{
			lookupdown += 1.0f;
			break;
		}

	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT) 
	{
		camera.turnLeft();
		glLoadIdentity();
	}

	if (key == GLUT_KEY_RIGHT) 
	{
		camera.turnRight();
		glLoadIdentity();
	}

	if (key == GLUT_KEY_DOWN)
	{
		camera.turnDown();
		glLoadIdentity();
	}

	if (key == GLUT_KEY_UP)
	{
		camera.turnUp();
		glLoadIdentity();
	}

	glutPostRedisplay();
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

void changeSize(int w, int h)	{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); // Load the matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the clipping volume
	gluPerspective(45, ratio, INSIDE_EDGE, OUTSIDE_EDGE);
	glTranslatef(0., 0., OUTSIDE_EDGE * 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);*/
}

void main(int argc, char **argv)
{
	printInstructions();

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
	glutSpecialFunc(specialKeyInput);
	glutReshapeFunc(changeSize);

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
