#include "World.h"

void draw_axes() {

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

void draw_ball() {
	glPushMatrix();
	glTranslatef(0., 200, 0.);

	glutWireSphere(50, 10, 10);
	glPopMatrix();
}




void draw_world() {
	glPushMatrix();
	//glTranslatef(0., -WINDOW_HEIGHT, 0.);
	glScalef(1., WORLD_HEIGHT / WORLD_WIDTH, 1.);

	glutWireCube(WORLD_WIDTH);
	glPopMatrix();
}
