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
		glutSolidSphere(10, 30, 30);
	glPopMatrix();

	// TODO: REMOVE THAT
	//x - blue
	//glPushMatrix();
	//	glTranslatef(100, 0., 0.);
	//	glColor3f(0., 0., 0.8);
	//	glutWireSphere(10, 10, 10);
	//glPopMatrix();
	////y - purple
	//glPushMatrix();
	//	glTranslatef(0., 200., 0.);
	//	glColor3f(0.6, 0., 0.6);
	//	glutWireSphere(10, 10, 10);
	//glPopMatrix();
	////z - green
	//glPushMatrix();
	//	glTranslatef(0., 0., 100.);
	//	glColor3f(0., 0.9, 0.0);
	//	glutWireSphere(10, 10, 10);
	//glPopMatrix();
}

// This method draws the world cube
void draw_world() {
	glPushMatrix();

		glEnable(GL_TEXTURE_2D);
			glScalef(WORLD_WIDTH / 2, WORLD_HEIGHT / 2, WORLD_WIDTH / 2);
			glBindTexture(GL_TEXTURE_2D, worldTextures[WALL_TEXTURE_ID]);
			
			glBegin(GL_QUADS);

				// Front wall
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
				// Back wall
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
				// Top wall - roof
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
				// Right wall
				glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
				// Left wall
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
			glEnd();

			glBindTexture(GL_TEXTURE_2D, worldTextures[FLOOR_TEXTURE_ID]);

			glBegin(GL_QUADS);
				// Bottom Face - floor
				glTexCoord2f(NUM_OF_FLOOR_TILES, NUM_OF_FLOOR_TILES);
				glVertex3f(-1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, NUM_OF_FLOOR_TILES);
				glVertex3f(1.0f, -1.0f, -1.0f);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(1.0f, -1.0f, 1.0f);
				glTexCoord2f(NUM_OF_FLOOR_TILES, 0.0f);
				glVertex3f(-1.0f, -1.0f, 1.0f);
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
