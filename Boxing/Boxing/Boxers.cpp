#include "Boxers.h"

const GLdouble BoxersDistance = 80.0;

/*
Define of body properties
*/
bool flag1 = true;
bool flag2 = false;
bool flag3 = true;
bool flag4 = false;
bool flag5 = true;
bool flag6 = false;
bool hflag = true;

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
GLfloat BoxerAng1[17] =
{
	0.0, 0.0, 0.0, 30.0,
	-120.0, 40.0, -80.0, 180.0,
	10.0, 180.0, 40.0, 5.0,
	0.0, 0.0, 0.0, 20.0, 0.0
};

GLfloat BoxerAng2[17] =
{
	52.0, 0.0, 0.0, 10.0,
	-80.0, 40.0, -30.0, 180.0,
	10.0, 180.0, 30.0, 5.0,
	30.0, 0.0, 0.0, 20.0, 0.0
};

// Default Ctor
Boxers::Boxers()
{
	BoxerAngles1 = BoxerAng1;
	BoxerAngles2 = BoxerAng2;
}

// Draw red boxer
void Boxers::draw_boxer1(GLfloat movingX)
{
	glPushMatrix();
		glTranslatef(movingX, FLOOR_Y_B, -BoxersDistance);
		glColor3f(0.7, 0., 0.);
		draw_body(BoxerAngles1);
	glPopMatrix();
}

// Draw blue boxer
void Boxers::draw_boxer2(GLfloat movingX)
{
	glPushMatrix();		
		glTranslatef(movingX, FLOOR_Y_B, BoxersDistance);
		glRotatef(-180., 0., 1., 0.);
		glColor3f(0., 0.3, 1.0);
		draw_body(BoxerAngles2);
	glPopMatrix();
}

//--------------------------------Animation functions-----------------------
void Boxers::animate_boxers_walk(GLfloat* BoxerAngles)
{
	if (flag1) {
		BoxerAngles[3] += 5.0;
	}
	else {
		BoxerAngles[3] -= 5.0;
	}
	if (BoxerAngles[3] >= 110.0) flag1 = false;
	if (BoxerAngles[3] <= 70.0)  flag1 = true;

	if (flag2) {
		BoxerAngles[5] += 5.0;
	}
	else {
		BoxerAngles[5] -= 5.0;
	}
	if (BoxerAngles[5] >= 110.0) flag2 = false;
	if (BoxerAngles[5] <= 70.0)  flag2 = true;

	if (flag3) {
		BoxerAngles[9] += 5.0;
	}
	else {
		BoxerAngles[9] -= 5.0;
	}
	if (BoxerAngles[9] >= 200.0) flag3 = false;
	if (BoxerAngles[9] <= 160.0)  flag3 = true;

	if (flag4) {
		BoxerAngles[7] += 5.0;
	}
	else {
		BoxerAngles[7] -= 5.0;
	}
	if (BoxerAngles[7] >= 200.0) flag4 = false;
	if (BoxerAngles[7] <= 160.0)  flag4 = true;

	if (hflag) {
		BoxerAngles[2] += 5.0;
	}
	else {
		BoxerAngles[2] -= 5.0;
	}
	if (BoxerAngles[2] >= 30.0) hflag = false;
	if (BoxerAngles[2] <= -30.0) hflag = true;

	glutPostRedisplay();
}

void Boxers::animate_boxers_fight(GLfloat* BoxerAngles)
{
	if (flag1) {
		BoxerAngles[3] -= 15.0;
	}
	else {
		BoxerAngles[3] += 15.0;
	}
	if (BoxerAngles[3] >= 60) flag1 = true;
	if (BoxerAngles[3] <= 0)  flag1 = false;	// 0-45

	if (flag2) {
		BoxerAngles[4] -= 30;
	}
	else {
		BoxerAngles[4] += 30;
	}
	if (BoxerAngles[4] >= 0) flag2 = true;
	if (BoxerAngles[4] <= -120)  flag2 = false;
	BoxerAngles[11] = -15;	// 0

	if (flag3) {
		BoxerAngles[5] -= 15.0;
	}
	else {
		BoxerAngles[5] += 15.0;
	}
	if (BoxerAngles[5] >= 60) flag3 = true;
	if (BoxerAngles[5] <= 0)  flag3 = false;	// 0-45

	if (flag4) {
		BoxerAngles[6] -= 30;
	}
	else {
		BoxerAngles[6] += 30;
	}
	if (BoxerAngles[6] >= 0) flag4 = true;
	if (BoxerAngles[6] <= -120)  flag4 = false;

	if (flag5) {
		BoxerAngles[9] += 10.0;
	}
	else {
		BoxerAngles[9] -= 10.0;
	}
	if (BoxerAngles[9] >= 200.0) flag5 = false;
	if (BoxerAngles[9] <= 160.0)  flag5 = true;

	if (flag6) {
		BoxerAngles[7] += 10.0;
	}
	else {
		BoxerAngles[7] -= 10.0;
	}
	if (BoxerAngles[7] >= 200.0) flag6 = false;
	if (BoxerAngles[7] <= 160.0)  flag6 = true;

	glutPostRedisplay();
}