#include "Globals.h"

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