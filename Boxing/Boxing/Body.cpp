#include "Body.h"

/*
Initialization of body parts' angles
*/
GLfloat *theta;

/*
Body parts
*/
GLUquadricObj	*torsoObj, *headObj, *n, *lh,
				*rh, *lf, *rf, *jp,
				*lhnd, *lft, *lua, *lla,
				*rua, *rla, *lll, *rll,
				*rul, *lul, *rhnd, *rft;

/*
Animation variables and angles
*/
GLuint texture1 = 0;
GLuint texture2 = 0;
GLuint texture3 = 0;
GLuint texture4 = 0;

//--------------------------------draw body functions-------------------------------

void Body::torso()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(torsoObj, TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
	glPopMatrix();
}

void Body::head()
{
	glPushMatrix();		
		
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glRotatef(15.0, 0.0, 0.0, 1.0);
		glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);

		// TODO: check the textures
		glBindTexture(GL_TEXTURE_2D, 2);
		gluQuadricTexture(headObj, 1);

		gluSphere(headObj, 1.0, 10, 10);
	glPopMatrix();
}

void Body::neck()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
	glPopMatrix();
}

void Body::joint_point()
{
	glPushMatrix();
		glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, JOINT_POINT_RADIUS);
		gluSphere(jp,1.0,10,10);
	glPopMatrix();
}

void Body::left_upper_arm()
{
	glPushMatrix();
		gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
    glPopMatrix();
}

void Body::left_lower_arm()
{
	glPushMatrix();
		glRotatef(0.0, 1.0, 0.0, 0.0);
		gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void Body::left_hand()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
		gluSphere(lhnd,1.0,10,10);
	glPopMatrix();
}

void Body::right_upper_arm()
{
	glPushMatrix();
		gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void Body::right_lower_arm()
{
	glPushMatrix();
		gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void Body::right_hand()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
		gluSphere(rhnd,1.0,10,10);
	glPopMatrix();
}

void Body::left_upper_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		
		// TODO: check the textures
		glBindTexture(GL_TEXTURE_2D, 1);
		gluQuadricTexture(lul, 1);

		gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Body::left_lower_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Body::left_foot()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
		gluSphere(lft,1.0,10,10);
	glPopMatrix();
}

void Body::right_upper_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Body::right_lower_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Body::right_foot()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
		gluSphere(rft,1.0,10,10);
	glPopMatrix();
}

void Body::draw_body(GLfloat *init_theta)
{
	theta = init_theta;

	glPushMatrix();
		glRotatef(theta[0], 0.0, 1.0, 0.0);
		torso();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0,TORSO_HEIGHT, 0.0);
		neck();
		glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
		glRotatef(theta[1], 1.0, 0.0, 0.0);
		glRotatef(theta[2], 0.0, 1.0, 0.0);
		head();
	glPopMatrix();//add JOINT_POINT_

	glPushMatrix();//add JOINT_POINT_
		glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(theta[3], 1.0, 0.0, 0.0);
		glRotatef(theta[11], 0.0, 0.0, 1.0);
		left_upper_arm();
		glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
		joint_point();
		glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[4], 1.0, 0.0, 0.0);
		left_lower_arm();
		glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
		left_hand();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(theta[5], 1.0, 0.0, 0.0);
		glRotatef(theta[12], 0.0, 0.0, 1.0);
		right_upper_arm();
		glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
		joint_point();

		// TODO: check the textures
		glBindTexture(GL_TEXTURE_2D, texture4);

		glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[6], 1.0, 0.0, 0.0);
		right_lower_arm();
		glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
		right_hand();
	glPopMatrix();

	glPushMatrix();	
		glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), -0.15*JOINT_POINT_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[7], 1.0, 0.0, 0.0);
		glRotatef(theta[13], 0.0, 0.0, 1.0);
		left_upper_leg();
		glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[8], 1.0, 0.0, 0.0);
		left_lower_leg();
		glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
		glRotatef(theta[15], 1.0, 0.0, 0.0);
		left_foot();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, -0.15*JOINT_POINT_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[9], 1.0, 0.0, 0.0);
		glRotatef(theta[14], 0.0, 0.0, 1.0);
		right_upper_leg();
		glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[10], 1.0, 0.0, 0.0);
		right_lower_leg();	
		glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
		glRotatef(theta[16], 1.0, 0.0, 0.0);
		right_foot();    
	glPopMatrix();

}

//--------------------------------Initialization function-------------------------
void Body::init_body()
{	
	//GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat mat_shininess = { 100.0 };
	//GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	//GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	//glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glDepthFunc(GL_LEQUAL);

	/* allocate quadrics with filled drawing style */


	n = gluNewQuadric();
	gluQuadricDrawStyle(n, GLU_FILL);

	torsoObj = gluNewQuadric();
	gluQuadricDrawStyle(torsoObj, GLU_FILL);

	headObj = gluNewQuadric();
	gluQuadricDrawStyle(headObj, GLU_FILL);

	jp = gluNewQuadric();
	gluQuadricDrawStyle(jp, GLU_FILL);

	lua = gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);

	lla = gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);

	lhnd = gluNewQuadric();
	gluQuadricDrawStyle(lhnd, GLU_FILL);

	rhnd = gluNewQuadric();
	gluQuadricDrawStyle(rhnd, GLU_FILL);

	rft = gluNewQuadric();
	gluQuadricDrawStyle(rft, GLU_FILL);

	lft = gluNewQuadric();
	gluQuadricDrawStyle(lft, GLU_FILL);

	rua = gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);

	rla = gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);

	lul = gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);

	lll = gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);

	rul = gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);

	rll = gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
}