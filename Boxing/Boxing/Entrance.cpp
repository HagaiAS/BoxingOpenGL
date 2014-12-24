#include "Entrance.h"

// Draw the entrance on both sides of the arena
void draw_entrance() {

	glPushMatrix();
		glColor3f(0., 0., 0.8); // in order to color only the next and not the whole list
	
		glNewList(ENTRANCE_LIST, GL_COMPILE);
			glPushMatrix();

				// Start with the world floor height and side
				glTranslatef(RIGHT_X_WALL_E, FLOOR_Y_E, FRONT_Z_WALL_E);

				// Draw the top lintel in the specific height
				glTranslatef(RIGHT_X_WALL_E_DELTA, ENTRANCE_HEIGHT, 0.);
				glTranslatef(-ENTRANCE_TOP_THICKNESS, 0., -ENTRANCE_TOP_THICKNESS); // Insert to the world
				glRotatef(90., 0., 1., 0.);
				gluCylinder(gluNewQuadric(), ENTRANCE_TOP_THICKNESS, ENTRANCE_TOP_THICKNESS, ENTRANCE_WIDTH, 30, 30);
			
				// Draw the side lintels with delta between them
				glTranslatef(0., 0., ENTRANCE_SIDES_THICKNESS / 2);
				glRotatef(90., 1., 0., 0.);
				gluCylinder(gluNewQuadric(), ENTRANCE_SIDES_THICKNESS, ENTRANCE_SIDES_THICKNESS, ENTRANCE_HEIGHT, 30, 30);
			
				glTranslatef(0., ENTRANCE_WIDTH - (ENTRANCE_SIDES_THICKNESS / 2), 0.);
				gluCylinder(gluNewQuadric(), ENTRANCE_SIDES_THICKNESS, ENTRANCE_SIDES_THICKNESS, ENTRANCE_HEIGHT, 30, 30);

			glPopMatrix();
		glEndList();

	glPopMatrix();

	// Draw the four sides of ropes, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(ENTRANCE_LIST);
		
		glColor3f(1., 0., 0.);
		glRotatef(180., 0., 1., 0.);
		glCallList(ENTRANCE_LIST);
	glPopMatrix();
}