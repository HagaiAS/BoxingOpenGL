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
void Boxers::draw_boxer(GLfloat angleY, GLfloat angleZ, GLfloat movingX, GLfloat movingY, GLfloat movingZ)
{
	glPushMatrix();
		float y = movingY;

		// If need to rotate around z - knockout
		if (angleZ != 0)
		{
			glTranslatef(0., y, 0.);
			y = 0;
			glRotatef(angleZ, 0., 0., 1.);
			glRotatef(-angleZ, 0.2, 0., 0.);
		}

		glPushMatrix();
			glRotatef(angleY, 0., 1., 0.);

			// If the boxer is the opponent - rotate him
			if (isOpponent)
			{
				glTranslatef(movingX, y, movingZ);
				glRotatef(-180., 0., 1., 0.);
			}
			else
			{
				glTranslatef(movingX, movingY, movingZ);
			}
			
			glColor3f(red, green, blue);
			draw_body(BoxerAngles);
		glPopMatrix();
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
		BoxerAngles[3] += BoxersPunchHands;
	}
	else {
		BoxerAngles[3] -= BoxersPunchHands;
	}

	//4 left lower armX
	if (BoxerAngles[4] >= 0.0) leftLowerArmFlag = false;
	if (BoxerAngles[4] <= -120.0)  leftLowerArmFlag = true;

	if (leftLowerArmFlag) {
		BoxerAngles[4] += BoxersPunchHands;
	}
	else {
		BoxerAngles[4] -= BoxersPunchHands;
	}

	//5 right upper armX
	if (BoxerAngles[5] >= 40.0) rightUpperArmFlag = false;
	if (BoxerAngles[5] <= 0.0)  rightUpperArmFlag = true;

	if (rightUpperArmFlag) {
		BoxerAngles[5] += BoxersPunchHands;
	}
	else {
		BoxerAngles[5] -= BoxersPunchHands;
	}

	//6 right lower armX
	if (BoxerAngles[6] >= 0.0) rightLowerArmFlag = false;
	if (BoxerAngles[6] <= -100.0)  rightLowerArmFlag = true;

	if (rightLowerArmFlag) {
		BoxerAngles[6] += BoxersPunchHands;
	}
	else {
		BoxerAngles[6] -= BoxersPunchHands;
	}

	glutPostRedisplay();
}

void Boxers::animate_boxer_winning()
{
	//7 left upper legX
	if (BoxerAngles[7] >= 150.0) leftUpperLegFlag = false;
	if (BoxerAngles[7] <= 100.0)  leftUpperLegFlag = true;

	if (leftUpperLegFlag) {
		BoxerAngles[7] += BoxersMoveLegs;
	}
	else {
		BoxerAngles[7] -= BoxersMoveLegs;
	}

	//8 left lower legX
	if (BoxerAngles[8] >= 100.0) leftLowerLegFlag = false;
	if (BoxerAngles[8] <= 50.0)  leftLowerLegFlag = true;

	if (leftLowerLegFlag) {
		BoxerAngles[8] += BoxersMoveLowLegs;
	}
	else {
		BoxerAngles[8] -= BoxersMoveLowLegs;
	}

	//9 right upper legX
	if (BoxerAngles[9] >= 150.0) rightUpperLegFlag = false;
	if (BoxerAngles[9] <= 100.0)  rightUpperLegFlag = true;

	if (rightUpperLegFlag) {
		BoxerAngles[9] += BoxersMoveLegs;
	}
	else {
		BoxerAngles[9] -= BoxersMoveLegs;
	}

	//10 right lower legX
	if (BoxerAngles[10] >= 100.0) rightLowerLegFlag = false;
	if (BoxerAngles[10] <= 50.0)  rightLowerLegFlag = true;

	if (rightLowerLegFlag) {
		BoxerAngles[10] += BoxersMoveLowLegs;
	}
	else {
		BoxerAngles[10] -= BoxersMoveLowLegs;
	}

	//11 left upper armZ
	if (BoxerAngles[11] >= 40.0) leftUpperArmFlag = false;
	if (BoxerAngles[11] <= -40.0)  leftUpperArmFlag = true;

	if (leftUpperArmFlag) {
		BoxerAngles[11] += BoxersMoveHands;
	}
	else {
		BoxerAngles[11] -= BoxersMoveHands;
	}

	//12 right upper armZ
	if (BoxerAngles[12] >= 40.0) rightUpperArmFlag = false;
	if (BoxerAngles[12] <= -40.0)  rightUpperArmFlag = true;

	if (rightUpperArmFlag) {
		BoxerAngles[12] += BoxersMoveHands;
	}
	else {
		BoxerAngles[12] -= BoxersMoveHands;
	}

	//2 head 
	if (BoxerAngles[2] >= 20.0) headFlag = false;
	if (BoxerAngles[2] <= -20.0)  headFlag = true;

	if (headFlag) {
		BoxerAngles[2] += BoxersMoveHead;
	}
	else {
		BoxerAngles[2] -= BoxersMoveHead;
	}

	glutPostRedisplay();
}