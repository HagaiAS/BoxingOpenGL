#include "Crowd.h"

GLdouble CrowdDistance = 50.0;

//0 torso
//1 neckX
//2 neckY

//3 left upper armX
//4 left lower armX
//5 right upper armX
//6 right lower armX
//7 left upper legX
//8 left lower legX
//9 right upper legX
//10 right lower legX

//11 left upper armZ
//12 right upper armZ
//13 left upper legZ
//14 right upper legZ

//15 left footX
//16 right footX
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
	0.9, 0.2, 0.4,
	0.4, 0.1, 0.3
};

// Default Ctor
Crowd::Crowd()
{
	crowdColors = crowdRandomColors;
}

void Crowd::draw_crowds(GLfloat* crowdAnglesClapping, GLfloat* crowdAnglesUpHands)
{
	int crowdType;

	// Create new display list for crowd clapping man
	glNewList(CROWD_CLAPPING_LIST, GL_COMPILE);
		glPushMatrix();
			draw_body(crowdAnglesClapping);
		glPopMatrix();
	glEndList();

	// Create new display list for crowd man
	glNewList(CROWD_HANDS_UP_LIST, GL_COMPILE);
		glPushMatrix();
			draw_body(crowdAnglesUpHands);
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
				crowdType = CROWD_CLAPPING_LIST;
				glScalef(1., 1., deltaScaleZ);

				// Draw row of crowd
				for (int i = 1; i <= NUMBER_OF_CROWD_IN_ROW; i++)
				{
					glTranslatef(-CrowdDistance , 0., 0.);
					
					// Draw the current crowd man with random color
					glPushMatrix();
						
						// Draw the hands up crowd randomaly
						if (currColor + NUMBER_OF_CROWD_COLORS/3 >= (NUMBER_OF_CROWD_COLORS * 3)) {
							currColor = 0;
							crowdType = CROWD_HANDS_UP_LIST;
						}

						glColor3f(crowdColors[currColor], crowdColors[currColor + 1], crowdColors[currColor+2]);
						currColor++;

						glCallList(crowdType);
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
