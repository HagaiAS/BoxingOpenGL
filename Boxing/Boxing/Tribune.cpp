#include "Tribune.h"

void draw_tribunes() {

	// Create new display list for tribunes
	glNewList(TRIBUNE_LIST, GL_COMPILE);
		GLdouble deltaTribuneY = TRIBUNES_SIZE * TRIBUNES_Y_SCALE;
		GLdouble deltaScaleZ = 1 - 1.0 / NUMBER_OF_STAIRS;
		GLdouble deltaTribuneZ = (TRIBUNES_SIZE * TRIBUNES_Z_SCALE) / NUMBER_OF_STAIRS;

		glPushMatrix();

			GLdouble eqn[4] = { 0.0, 0.0, -1.0, FRONT_Z_WALL_T }; /* z < 0 */
			glClipPlane(GL_CLIP_PLANE0, eqn);
			glEnable(GL_CLIP_PLANE0);

			// Draw first stair
			glTranslatef(0.,
				FLOOR_Y_T + ((TRIBUNES_SIZE / 2) * TRIBUNES_Y_SCALE),
				FRONT_Z_WALL_T - ((TRIBUNES_SIZE / 2) * TRIBUNES_Z_SCALE));
			draw_tribune();

			// Draw next stairs
			for (int currStair = 2; currStair <= NUMBER_OF_STAIRS; currStair++) {
				//deltaTribuneZ = ;
				glScalef(1., 1., deltaScaleZ);
				glTranslatef(0., deltaTribuneY, deltaTribuneZ);

				draw_tribune();
			}

			glDisable(GL_CLIP_PLANE0);

		glPopMatrix();
	glEndList();

	// Draw the four tribunes, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(TRIBUNE_LIST);
	glPopMatrix();
}

void draw_tribune() {
	glPushMatrix();
		//glRotatef(body_angle, 0., 1., 0.);
		glColor3f(0.03, 0.03, 0.03);
		glScalef(1., TRIBUNES_Y_SCALE, TRIBUNES_Z_SCALE);
		//setTribuneMaterial();
		
		glutSolidCube(TRIBUNES_SIZE);
	glPopMatrix();
}

void setTribuneMaterial() {
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, TRIBUNE_AMBIENT_DIFFUSE);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, TRIBUNE_SPECULAR); //reflect
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, TRIBUNE_SHININESS);
}