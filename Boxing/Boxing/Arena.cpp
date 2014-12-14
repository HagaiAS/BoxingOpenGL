#include "Arena.h"

void draw_arena() {
	glPushMatrix();
	glColor3f(0.2, 0.4, 0.5);
	//glRotatef(body_angle, 0., 1., 0.);

	glTranslatef(0., FLOOR_Y_A + ((ARENA_SIZE / 2) * ARENA_Y_SCALE), 0.);
	glScalef(1., ARENA_Y_SCALE, 1.);
	glShadeModel(GL_SMOOTH);
	glutWireCube(ARENA_SIZE);
	glPopMatrix();
	// Draw the ropes around the arena and the corners
	draw_corners();
	draw_ropes();
}


// Draw the corners around the arena
void draw_corners() {

	glPushMatrix();

	// Start with the arena floor height and side
	glTranslatef(ARENA_SIZE / 2, FLOOR_Y_A + (ARENA_SIZE * ARENA_Y_SCALE), -ARENA_SIZE / 2);

	// Draw the corners
	glTranslatef(-ARENA_CORNER_THICKNESS, 0., ARENA_CORNER_THICKNESS);
	glRotatef(-90., 1., 0., 0.);
	glColor3f(1., 1., 1.);

	gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);

	glTranslatef(-ARENA_SIZE + (ARENA_CORNER_THICKNESS * 2), 0., 0.);
	gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);

	glTranslatef(0., -ARENA_SIZE + (ARENA_CORNER_THICKNESS * 2), 0.);
	gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);

	glTranslatef(ARENA_SIZE - (ARENA_CORNER_THICKNESS * 2), 0., 0.);
	gluCylinder(gluNewQuadric(), ARENA_CORNER_THICKNESS, ARENA_CORNER_THICKNESS, ARENA_SIZE * ARENA_Y_SCALE, 30, 30);
	glPopMatrix();
}

// Draw the ropes around the arena
void draw_ropes() {

	glNewList(ROPES_LIST, GL_COMPILE);
	glPushMatrix();

	// Start with the arena floor height and side
	glTranslatef(ARENA_SIZE / 2, FLOOR_Y_A + (ARENA_SIZE * ARENA_Y_SCALE), -ARENA_SIZE / 2);

	// Draw the ropes with delta between them
	glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
	glColor3f(1., 0., 0.);
	gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
	glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
	glColor3f(1., 1., 1.);
	gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
	glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
	glColor3f(0., 0., 1.);
	gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);
	glTranslatef(0., ARENA_ROPE_Y_DELTA, 0.);
	glColor3f(1., 0., 0.);
	gluCylinder(gluNewQuadric(), ARENA_ROPE_THICKNESS, ARENA_ROPE_THICKNESS, ARENA_SIZE, 30, 30);

	glPopMatrix();
	glEndList();

	// Draw the four sides of ropes, every time rotate by 90 degrees
	glPushMatrix();
	glCallList(ROPES_LIST);
	glRotatef(90., 0., 1., 0.);
	glCallList(ROPES_LIST);
	glRotatef(90., 0., 1., 0.);
	glCallList(ROPES_LIST);
	glRotatef(90., 0., 1., 0.);
	glCallList(ROPES_LIST);
	glPopMatrix();
}

