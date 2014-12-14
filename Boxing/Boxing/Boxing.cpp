// Boxing.cpp
// Harel Ezra and Hagai Asaban
//------------------------------------------------
#include "Arena.h"
#include "Tribune.h"
#include "Boxer.h"
#include "World.h"

void my_init(void);
void my_display(void);
void my_idle(void);
void keyInput(void);

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

	draw_boxer();
	
	//draw_axes();

	glColor3ub(255, 255, 0);
	draw_world();
	//draw_ball();
	draw_tribunes();
	draw_arena();

	glutSwapBuffers(); // for animation
}

// This method change the angles for each draw
void my_idle(void)
{
	//angle = angle + angle_delta;
	//body_angle = body_angle + body_angle_delta;
	//arm_angle = arm_angle + arm_angle_delta;

	//// Keep moving if exceeds the max angle
	//if (angle > 360.) {
	//	angle -= 360.;
	//}
	//if (body_angle > 360.) {
	//	body_angle -= 360.;
	//}
	//if ((arm_angle < 0.) || (arm_angle > 60.)) {
	//	arm_angle_delta = -arm_angle_delta;
	//}

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




//void fillRandomColor() {
//
//	// Define random color
//	srand(time(NULL));
//	red = (double)(rand() % 1000) / 1000;
//	green = (double)(rand() % 1000) / 1000;
//	blue = (double)(rand() % 1000) / 1000;
//	glColor3f(red, green, blue);
//}
