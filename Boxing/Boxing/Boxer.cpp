#include "Boxer.h"

double red;
double green;
double blue;
float headPos;
float neckPos;
float bodyPos;
bool rotateArms = false;
bool rotateAll = false;

void draw_boxer() {

	glNewList(BOXER_LIST, GL_COMPILE);
	glPushMatrix();
		glTranslatef(0., FLOOR_Y_B, 0.);
		glColor3ub(100, 0.5, 0.5);
		draw_head();
		glColor3f(1, 0.5, 0.5);
		draw_neck();
		glColor3f(0.3, 1., 0.62);
		draw_body();
		glColor3f(1, 0.5, 0.5);
		draw_hands();
		glColor3f(1, 0.5, 0.5);
		draw_legs();
	glPopMatrix();
	glEndList();

	// Draw the four sides of ropes, every time rotate by 90 degrees
	glPushMatrix();
		glCallList(BOXER_LIST);
		glTranslatef(0., 0., 80.);
		glRotatef(-180., 0., 1., 0.);
		glCallList(BOXER_LIST);
		
	glPopMatrix();
}

// This method draws man head
void draw_head() {
	headPos = TOP_EDGE_B - HEAD_RADIUS * 2;

	glPushMatrix();
		glTranslatef(0., headPos, 0.);
		rotateToFixZ();
		glScalef(HEAD_RADIUS_WIDTH_SCALE, HEAD_RADIUS_WIDTH_SCALE, 1.);

		glutWireSphere(HEAD_RADIUS, 10, 10);
	glPopMatrix();

	glColor3f(0.3, 0.62, 1.);
	draw_face();
}

// This method draws man face
void draw_face() {
	float rightEyePosX = ((HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) / 2) - EYE_RADIUS;
	float rightEyePosY = headPos + ((HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) / 2) - EYE_RADIUS;
	float rightEyePosZ = (HEAD_RADIUS * HEAD_RADIUS_WIDTH_SCALE) - EYE_RADIUS;
	float leftEyePosX = -rightEyePosX;
	float leftEyePosY = rightEyePosY;
	float leftEyePosZ = rightEyePosZ;

	glPushMatrix();
	glTranslatef(rightEyePosX, rightEyePosY, rightEyePosZ);
	rotateToFixZ();

	glutWireSphere(EYE_RADIUS, 4, 4); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftEyePosX, leftEyePosY, leftEyePosZ);
	rotateToFixZ();

	glutWireSphere(EYE_RADIUS, 4, 4); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw nose
	float nosePosX = (rightEyePosX + leftEyePosX) / 2;
	float nosePosY = headPos;
	float nosePosZ = rightEyePosZ + (NOSE_RADIUS * NOSE_RADIUS_WIDTH_SCALE);

	glPushMatrix();
	glTranslatef(nosePosX, nosePosY, nosePosZ);
	glRotatef(90, 0.1, 1., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(angle, 1., 0., 0.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	glScalef(NOSE_RADIUS_WIDTH_SCALE, 1.0, 1.0);

	glutWireSphere(NOSE_RADIUS, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man neck
void draw_neck() {
	neckPos = headPos - HEAD_RADIUS - (NECK_RADIUS * NECK_RADIUS_WIDTH_SCALE);

	glPushMatrix();
	glTranslatef(0., neckPos, 0.);
	rotateToFixZ();
	glScalef(1., 1., NECK_RADIUS_WIDTH_SCALE);

	glutWireSphere(NECK_RADIUS, 6, 6); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man body
void draw_body() {
	bodyPos = neckPos - (NECK_RADIUS * NECK_RADIUS_WIDTH_SCALE) - BODY_HEIGHT;

	glPushMatrix();
		glTranslatef(0., bodyPos, 0.);
		glScalef(1., 1., 0.65);
		glRotatef(-90., 1., 0., 0.);
		
		GLfloat mat_amb_dif1[] = { 0.0, 1.0, 0.0, 1.0 }; //color of material: green
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_dif1);//function specified the material properties 

		GLUquadricObj *myCylinder;
		myCylinder = gluNewQuadric();
		gluQuadricDrawStyle(myCylinder, GLU_FILL); //try: gluQuadricDrawStyle(quadObj, GLU_LINE);
		gluCylinder(myCylinder, BODY_RADIUS_WIDTH, BODY_RADIUS_WIDTH_TOP, BODY_HEIGHT, 16, 16);

		gluDeleteQuadric(myCylinder);
	glPopMatrix();
}

// This method draws man hands
void draw_hands() {
	float rightArmX = BODY_RADIUS_HEIGHT * BODY_RADIUS_WIDTH_SCALE * 2;
	float rightArmY = bodyPos + BODY_HEIGHT;
	float leftArmX = -rightArmX;
	float leftArmY = rightArmY;

	glPushMatrix();
	glTranslatef(rightArmX, rightArmY, 0.);
	//glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(150, 0., 1., 0.);


	glScalef(HAND_RADIUS_WIDTH_SCALE, HAND_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftArmX, leftArmY, 0.);
	//glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	glRotatef(-150, 0., 1., 0.);

	glScalef(HAND_RADIUS_WIDTH_SCALE, HAND_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw the forearms
	float rightForearmX = rightArmX - rightArmX*sin(150.);
	float rightForearmY = rightArmY - HAND_RADIUS_HEIGHT - HAND_RADIUS_HEIGHT / 2 + HAND_RADIUS_HEIGHT;
	float leftForearmX = -rightForearmX - HAND_RADIUS_HEIGHT;
	float leftForearmY = rightForearmY - HAND_RADIUS_HEIGHT;

	glPushMatrix();
	glTranslatef(rightForearmX, rightForearmY, 0.);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	//glRotatef(70, 0., 1., 0.2);


	glScalef(HAND_RADIUS_WIDTH_SCALE / 1.5, HAND_RADIUS_WIDTH_SCALE / 1.5, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftForearmX, leftForearmY, 0);
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          
	//glRotatef(165, 0., 1., 0.);

	glScalef(HAND_RADIUS_WIDTH_SCALE / 1.5, HAND_RADIUS_WIDTH_SCALE / 1.5, 1.0);

	glutWireSphere(HAND_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method draws man legs
void draw_legs() {
	float rightThighX = BODY_RADIUS_HEIGHT * BODY_RADIUS_WIDTH_SCALE * 2;
		//bodyPos - (BODY_RADIUS_HEIGHT * BODY_RADIUS_WIDTH_SCALE*1.8 / 1.2);
	float rightThighY = bodyPos - BODY_RADIUS_HEIGHT - LEGS_RADIUS_HEIGHT + (LEGS_RADIUS_HEIGHT / 2);
	float leftThighX = -rightThighX;
	float leftThighY = rightThighY;

	glPushMatrix();
	glTranslatef(rightThighX, rightThighY, 0.);
	glRotatef(77, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE, LEGS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftThighX, leftThighY, 0.);
	glRotatef(77, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)                                          

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE, LEGS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw calfs
	float rightCalfX = rightThighX;
	float rightCalfY = rightThighY - LEGS_RADIUS_HEIGHT - LEGS_RADIUS_HEIGHT + sin(77.);
	float leftCalfX = -rightCalfX;
	float leftCalfY = rightCalfY;

	glPushMatrix();
	glTranslatef(rightCalfX, rightCalfY, 0.);
	glRotatef(-77, 1., 0., 0.);

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE / 1.3, LEGS_RADIUS_WIDTH_SCALE / 1.3, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftCalfX, leftCalfY, 0.);
	glRotatef(-77, 1., 0., 0.);

	// If need to rotate
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.);
	}

	glScalef(LEGS_RADIUS_WIDTH_SCALE / 1.3, LEGS_RADIUS_WIDTH_SCALE / 1.3, 1.0);

	glutWireSphere(LEGS_RADIUS_HEIGHT, 8, 8); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();

	// Draw calfs
	float rightFootX = rightCalfX;
	float rightFootY =
		rightCalfY - LEGS_RADIUS_HEIGHT - ((FOOTS_RADIUS_HEIGHT / 2)*FOOTS_RADIUS_WIDTH_SCALE);
	float rightFootZ = FOOTS_RADIUS_HEIGHT*FOOTS_RADIUS_WIDTH_SCALE;
	float leftFootX = -rightFootX;
	float leftFootY = rightFootY;
	float leftFootZ = rightFootZ;

	glColor3f(0.5, 0.62, 0.4);

	glPushMatrix();
	glTranslatef(rightFootX, rightFootY, rightFootZ);
	glScalef(FOOTS_RADIUS_WIDTH_SCALE + 0.5, FOOTS_RADIUS_WIDTH_SCALE, 1.0);
	glRotatef(117, 1., 0., 0.);
	glutWireSphere(FOOTS_RADIUS_HEIGHT, 5, 5); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(leftFootX, leftFootY, leftFootZ);
	glScalef(FOOTS_RADIUS_WIDTH_SCALE + 0.5, FOOTS_RADIUS_WIDTH_SCALE, 1.0);

	glutWireSphere(FOOTS_RADIUS_HEIGHT, 6, 6); //(radius, slices-vertical[פרוסות], stacks-horizontal);
	glPopMatrix();
}

// This method fix the z axis to be up and rotate the object around the new z
void rotateToFixZ() {
	glRotatef(90, 1., 0., 0.); // Put axis Z up (by rotating the sphere around axes X to 90 degrees)   

	// If need to rotate all
	if (rotateAll) {
		glRotatef(angle, 0., 0., 1.); // Rotate around new position of axis Z - here new! angle every time (angle grows)
	}
}

