#include "Camera.h"

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
	}
	else {
		direction = 1;
	}

	lasty = y;

	if (direction > 0) {
		x += x*zoomSpeed;
		y += y*zoomSpeed;
		z += z*zoomSpeed;
	}
	else {
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
