#include "Boxers.h"

const GLdouble BoxersDistance = 80.0;

// Draw red boxer
void Boxers::draw_boxer1(GLfloat movingX)
{
	GLfloat BoxerAngles1[17] =
	{
		0.0, 0.0, 0.0, 30.0,
		-120.0, 40.0, -80.0, 180.0,
		10.0, 180.0, 40.0, 5.0,
		0.0, 0.0, 0.0, 20.0, 0.0
	};

	glPushMatrix();
		glTranslatef(movingX, FLOOR_Y_B, -BoxersDistance);
		glColor3f(0.7, 0., 0.);
		draw_body(BoxerAngles1);
	glPopMatrix();

	// Draw the four sides of ropes, every time rotate by 90 degrees
	//glPushMatrix();
		//glCallList(BOXER_LIST);
		//glTranslatef(0., 0., 80.);
		//glRotatef(-180., 0., 1., 0.);
		//draw one more boxer.
		//glCallList(BOXER_LIST);
	//glPopMatrix();

	//glNewList(BOXER_LIST, GL_COMPILE);
		//glPushMatrix();
		//glClearColor(1, 1, 0.5, 0.0);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glLoadIdentity();
		//glColor3f(0.0, 0.0, 0.0);
		//glColor3ub(0, 0, 0);
		//BoxerBody.drawBody();
		//glFlush();
		//glutSwapBuffers();
		//glPopMatrix();
	//glEndList();
}

// Draw blue boxer
void Boxers::draw_boxer2(GLfloat movingX)
{
	GLfloat BoxerAngles2[17] =
	{
		52.0, 0.0, 0.0, 10.0,
		-80.0, 40.0, -30.0, 180.0,
		10.0, 180.0, 30.0, 5.0,
		30.0, 0.0, 0.0, 20.0, 0.0
	};

	glPushMatrix();		
		glTranslatef(movingX, FLOOR_Y_B, BoxersDistance);
		glRotatef(-180., 0., 1., 0.);
		glColor3f(0., 0.3, 1.0);
		draw_body(BoxerAngles2);
	glPopMatrix();
}

//void Boxers::animate_boxers_walk(void)
//{
//	
//
//}
//
//void Boxers::animate_boxers_fight(void) 
//{
//
//
//}