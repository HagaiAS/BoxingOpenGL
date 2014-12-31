#include "Camera.h"

// Camera constructor.
Camera::Camera()
{
	isTopView = 0;

	initCameraPosition();

	angle = 0.0;
	rotatingSpeed = 0.04;
	movingSpeed = 12.0;
}

void Camera::initCameraPosition()
{
	x = RIGHT_X_WALL_T;
	y = FLOOR_Y_T + 150 / 2;
	z = FRONT_Z_WALL_T * 2;

	centerX = 0;
	centerY = 0;
	centerZ = -1;
}

void Camera::moveUp()
{
	y += movingSpeed;
	updateView();
}

void Camera::moveDown()
{
	y -= movingSpeed;
	updateView();
}

void Camera::moveLeft()
{
	move(-1, 1);
}

void Camera::moveRight()
{
	move(1, 1);
}

void Camera::moveForward()
{
	move(1, 0);
}

void Camera::moveBackward()
{
	move(-1, 0);
}

void Camera::move(GLdouble direction, int isHorizontal)
{
	// If the moving is horizontal
	if (isHorizontal) {
		x += direction * movingSpeed;
	}
	else {
		x += direction * centerX * movingSpeed;
		z += direction * centerZ * movingSpeed;
	}

	updateView();
}

void Camera::lookUp()
{
	look(rotatingSpeed, 0);
}

void Camera::lookDown()
{
	look(-rotatingSpeed, 0);
}

void Camera::lookLeft()
{
	look(-rotatingSpeed, 1);
}

void Camera::lookRight()
{
	look(rotatingSpeed, 1);
}

void Camera::look(GLdouble direction, int isHorizontal)
{
	angle += direction;

	// If the looking is horizontal
	if (isHorizontal) {
		centerX = sin(angle); 
	}
	else {
		centerY = sin(angle);
	}

	centerZ = -cos(angle);
	
	updateView();
}

void Camera::topView()
{
	angle = 0.0;
	x = 0;
	z = 0;
	y = WORLD_HEIGHT;
	centerX = 0;
	centerZ = -1;
	centerY = 0;
	
	isTopView = 1;
	updateView();
}

void Camera::topViewDisable()
{
	isTopView = 0;
	initCameraPosition();
	updateView();
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

// This method load the identity and calls the lookat method
void Camera::updateView() {
	glLoadIdentity();
	
	// If it is top view
	if (isTopView) 
	{
		gluLookAt(	getX(),
					getY(),
					getZ(),
					getCenterX(),
					getCenterY(),
					getCenterZ(),
					0.0,
					1.0,
					0.0);
	}
	else 
	{
		gluLookAt(	getX(),
					getY(),
					getZ(),
					getX() + getCenterX(),
					getY() + getCenterY(),
					getZ() + getCenterZ(),
					0.0,
					1.0,
					0.0);
	}
}