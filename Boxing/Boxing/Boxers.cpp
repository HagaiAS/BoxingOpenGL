#include "Boxers.h"

/*
Define of body properties
*/
bool rightUpperLegFlag = true;
bool rightLowerLegFlag = true;
bool leftUpperLegFlag = true;
bool leftLowerLegFlag = true;
bool rightUpperArmFlag = true;
bool rightLowerArmFlag = true;
bool leftUpperArmFlag = true;
bool leftLowerArmFlag = true;
bool headFlag = true; // head moving

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
	0.0, 0.0, 0.0, 10.0,
	-80.0, 40.0, -30.0, 180.0,
	10.0, 180.0, 30.0, 5.0,
	30.0, 0.0, 0.0, 20.0, 0.0
};

// Default Ctor
Boxers::Boxers(GLfloat* boxerAng)
{
	BoxerAngles = boxerAng;
}

// Initialize the body of the boxer and his textures
void Boxers::init_body(GLuint* boxerTextures, bool opponent, GLfloat r, GLfloat g, GLfloat b)
{
	red = r;
	green = g;
	blue = b;
	isOpponent = opponent;
	
	Body::init_body(boxerTextures, true);
}

// Draw boxer
void Boxers::draw_boxer(GLfloat movingX)
{
	glPushMatrix();
		
		// If the boxer is the opponent - rotate him
		if (isOpponent)
		{
			glTranslatef(movingX, FLOOR_Y_B, BoxersDistance);
			glRotatef(-180., 0., 1., 0.);
		}
		else
		{
			glTranslatef(movingX, FLOOR_Y_B, -BoxersDistance);
		}
		
		glColor3f(red, green, blue);
		draw_body(BoxerAngles);
	glPopMatrix();
}

//--------------------------------Animation functions-----------------------
void Boxers::animate_boxer_walk()
{
	//7 left upper legX
	if (BoxerAngles[7] >= 180.0) leftUpperLegFlag = false;
	if (BoxerAngles[7] <= 150.0)  leftUpperLegFlag = true;

	if (leftUpperLegFlag) {
		BoxerAngles[7] += BoxersMoveLegs;
	}
	else {
		BoxerAngles[7] -= BoxersMoveLegs;
	}

	//8 left lower legX
	if (BoxerAngles[8] >= 80.0) leftLowerLegFlag = false;
	if (BoxerAngles[8] <= 0.0)  leftLowerLegFlag = true;

	if (leftLowerLegFlag) {
		BoxerAngles[8] += BoxersMoveLowLegs;
	}
	else {
		BoxerAngles[8] -= BoxersMoveLowLegs;
	}

	//9 right upper legX
	if (BoxerAngles[9] >= 180.0) rightUpperLegFlag = false;
	if (BoxerAngles[9] <= 160.0)  rightUpperLegFlag = true;

	if (rightUpperLegFlag) {
		BoxerAngles[9] += BoxersMoveLegs;
	}
	else {
		BoxerAngles[9] -= BoxersMoveLegs;
	}

	//10 right lower legX
	if (BoxerAngles[10] >= 80.0) rightLowerLegFlag = false;
	if (BoxerAngles[10] <= 0.0)  rightLowerLegFlag = true;

	if (rightLowerLegFlag) {
		BoxerAngles[10] += BoxersMoveLowLegs;
	}
	else {
		BoxerAngles[10] -= BoxersMoveLowLegs;
	}

	glutPostRedisplay();
}

void Boxers::animate_boxer_fight()
{
	//3 left upper armX
	if (BoxerAngles[3] >= 80.0) leftUpperArmFlag = false;
	if (BoxerAngles[3] <= 0.0)  leftUpperArmFlag = true;

	if (leftUpperArmFlag) {
		BoxerAngles[3] += BoxersMoveHands;
	}
	else {
		BoxerAngles[3] -= BoxersMoveHands;
	}

	//4 left lower armX
	if (BoxerAngles[4] >= 0.0) leftLowerArmFlag = false;
	if (BoxerAngles[4] <= -120.0)  leftLowerArmFlag = true;

	if (leftLowerArmFlag) {
		BoxerAngles[4] += BoxersMoveHands;
	}
	else {
		BoxerAngles[4] -= BoxersMoveHands;
	}

	//5 right upper armX
	if (BoxerAngles[5] >= 40.0) rightUpperArmFlag = false;
	if (BoxerAngles[5] <= 0.0)  rightUpperArmFlag = true;

	if (rightUpperArmFlag) {
		BoxerAngles[5] += BoxersMoveHands;
	}
	else {
		BoxerAngles[5] -= BoxersMoveHands;
	}

	//6 right lower armX
	if (BoxerAngles[6] >= 0.0) rightLowerArmFlag = false;
	if (BoxerAngles[6] <= -100.0)  rightLowerArmFlag = true;

	if (rightLowerArmFlag) {
		BoxerAngles[6] += BoxersMoveHands;
	}
	else {
		BoxerAngles[6] -= BoxersMoveHands;
	}

	glutPostRedisplay();
}