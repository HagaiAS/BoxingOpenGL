#include "Crowd.h"

GLdouble CrowdDistance = 50.0;

/*
Boxer 1 angles body parts' angles
*/
GLfloat crowdAngles[17] =
{
	0.0, 0.0, 0.0, -30.0,
	-20.0, -38.0, -20.0, 90.0,
	90.0, 90.0, 90.0, 25.0,
	0.0, 0.0, 0.0, 20.0, 0.0
};

GLfloat crowdRandomColors[NUMBER_OF_CROWD_COLORS * 3] =
{
	0.8, 0.0, 0.1,
	0.2, 0.4, 0.5,
	0.1, 0.0, 1.0,
	0.9, 0.2, 0.4
};

// Default Ctor
Crowd::Crowd()
{
	crowdColors = crowdRandomColors;
}

void Crowd::draw_crowds()
{
	//glNewList(CROWD_LIST, GL_COMPILE);
	//	glPushMatrix();		
	//		glTranslatef(0., FLOOR_Y_B, -CrowdDistance);
	//		//glClearColor(1, 1, 0.5, 0.0);
	//		glColor3ub(0, 0, 0);
	//		glColor3f(1, 0.5, 0.5);
	//		draw_body(crowdAngles);
	//	glPopMatrix();
	//glEndList();

	//glPushMatrix();
	//	glCallList(CROWD_LIST);
	//	glTranslatef(0., FLOOR_Y_B, CrowdDistance);
	//	glCallList(CROWD_LIST);
	//glPopMatrix();

	// Create new display list for crowd man
	glNewList(CROWD_LIST, GL_COMPILE);
		glPushMatrix();
			draw_body(crowdAngles);
		glPopMatrix();
	glEndList();

	// Create new display list for crowd row
	glNewList(CROWD_ROW_LIST, GL_COMPILE);
		GLdouble deltaTribuneX = (TRIBUNES_SIZE * TRIBUNES_Z_SCALE) / NUMBER_OF_STAIRS;
		GLdouble deltaTribuneY = TRIBUNES_SIZE * TRIBUNES_Y_SCALE;
		GLdouble deltaScaleZ = 1 - 1.0 / NUMBER_OF_STAIRS;
		GLdouble deltaTribuneZ = (TRIBUNES_SIZE * TRIBUNES_Z_SCALE) / NUMBER_OF_STAIRS;

		glPushMatrix();
			glTranslatef((-TRIBUNES_SIZE / 2) -25,
						 FLOOR_Y_T + ((TRIBUNES_SIZE / 2) * TRIBUNES_Y_SCALE) + 40,
						 FRONT_Z_WALL_T - ((TRIBUNES_SIZE / 2) * TRIBUNES_Z_SCALE) - 80);

			glRotatef(180., 0., 1., 0.);
			int currColor = 0;

			// Draw next stairs
			for (int currStair = 1; currStair < NUMBER_OF_STAIRS + 1; currStair++) {
				
				glScalef(1., 1., deltaScaleZ);

				// Draw row of crowd
				for (int i = 1; i <= NUMBER_OF_CROWD_IN_ROW; i++)
				{
					glTranslatef(-CrowdDistance , 0., 0.);
					
					// Draw the current crowd man with random color
					glPushMatrix();
						
						if (currColor + 2 >= (NUMBER_OF_CROWD_COLORS * 3)) {
							currColor = 0;
						}

						glColor3f(crowdColors[currColor], crowdColors[currColor + 1], crowdColors[currColor+2]);
						currColor++;

						glCallList(CROWD_LIST);
					glPopMatrix();
				}

				glTranslatef(NUMBER_OF_CROWD_IN_ROW * CrowdDistance, deltaTribuneY, -30 * currStair);
			}

		glPopMatrix();
	glEndList();

	// Draw the four tribunes with crowds, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(CROWD_ROW_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(CROWD_ROW_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(CROWD_ROW_LIST);
		glRotatef(90., 0., 1., 0.);
		glCallList(CROWD_ROW_LIST);
	glPopMatrix();
}

// This function flickering the color because of the display infinity calls
void Crowd::fillRandomColor() {

	// Define random color
	//srand(time(NULL));
	//red = (double)(rand() % 1000) / 1000;
	//green = (double)(rand() % 1000) / 1000;
	//blue = (double)(rand() % 1000) / 1000;
	//glColor3f(red, green, blue);
}