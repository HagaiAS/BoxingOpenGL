#include "World.h"

void draw_axes() 
{
	glPushMatrix();
		glColor3f(1., 1., 1.);
		glBegin(GL_LINES);
		glVertex3f(LEFT_EDGE, 0., 0.);
		glVertex3f(RIGHT_EDGE, 0., 0.);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(0., TOP_EDGE, 0.);
		glVertex3f(0., BOTTOM_EDGE, 0.);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(0., 0., INSIDE_EDGE);
		glVertex3f(0., 0., OUTSIDE_EDGE);
		glEnd();
	glPopMatrix();
}

void draw_lamp() 
{
	glPushMatrix();
		glColor3f(1., 1., 0.);
		glTranslatef(LIGHT_POS_X, LIGHT_POS_Y, LIGHT_POS_Z);
		glRotatef(90., 1., 0., 0.);
		glutWireSphere(10, 10, 10);
	glPopMatrix();

	// TODO: REMOVE THAT
	//x - blue
	glPushMatrix();
		glTranslatef(100, 0., 0.);
		glColor3f(0., 0., 0.8);
		glutWireSphere(10, 10, 10);
	glPopMatrix();
	//y - purple
	glPushMatrix();
		glTranslatef(0., 200., 0.);
		glColor3f(0.6, 0., 0.6);
		glutWireSphere(10, 10, 10);
	glPopMatrix();
	//z - green
	glPushMatrix();
		glTranslatef(0., 0., 100.);
		glColor3f(0., 0.9, 0.0);
		glutWireSphere(10, 10, 10);
	glPopMatrix();
}

void draw_world() {
	glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glScalef(1., WORLD_HEIGHT / WORLD_WIDTH, 1.);
		glutSolidCube(WORLD_WIDTH);
	glPopMatrix();
}
