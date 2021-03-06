#include "Body.h"

// Initialization of body parts' angles
GLfloat *theta;

// Body parts
GLUquadricObj	*torsoObj, *headObj, *n, *lh,
				*rh, *lf, *rf, *jp,
				*lhnd, *lft, *lua, *lla,
				*rua, *rla, *lll, *rll,
				*rul, *lul, *rhnd, *rft;

//--------------------------------draw body functions-------------------------------

void Body::torso()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glScalef(1., TORSO_TOP_RADIUS_SCALE, 1.);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[BODY_TEXTURE_ID]);
			gluQuadricTexture(torsoObj, 1);
			gluCylinder(torsoObj, TORSO_RADIUS, torsoTopRadius, TORSO_HEIGHT, 20, 20);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::head()
{
	glPushMatrix();		
		
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glRotatef(15.0, 0.0, 0.0, 1.0);
		glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[HEAD_TEXTURE_ID]);
			gluQuadricTexture(headObj, 1);
			gluSphere(headObj, 1.0, 20, 20);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::neck()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(n, 1);
			gluCylinder(n, NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::joint_point()
{
	glPushMatrix();
		glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, JOINT_POINT_RADIUS);
		
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(jp, 1);
			gluSphere(jp, 1.0, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::left_upper_arm()
{
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(lua, 1);
			gluCylinder(lua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Body::left_lower_arm()
{
	glPushMatrix();
		glRotatef(0.0, 1.0, 0.0, 0.0);
		
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[HAND_TEXTURE_ID]);
			gluQuadricTexture(lla, 1);
			gluCylinder(lla, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::left_hand()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(handRadius, HAND_HEIGHT, handRadius);
		
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[GLOVE_TEXTURE_ID]);
			gluQuadricTexture(lhnd, 1);
			gluSphere(lhnd, 1.0, 10, 10);
			
			// If should draw a glove
			if (boxer)
			{
				glTranslatef(handRadius / 5, 0., 0.);
				glutSolidSphere(0.4, 10, 10);
			}

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::right_upper_arm()
{
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(rua, 1);
			gluCylinder(rua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::right_lower_arm()
{
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[HAND_TEXTURE_ID]);
			gluQuadricTexture(rla, 1);
			gluCylinder(rla, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::right_hand()
{
	glPushMatrix();
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(handRadius, HAND_HEIGHT, handRadius);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[GLOVE_TEXTURE_ID]);
			gluQuadricTexture(rhnd, 1);
			gluSphere(rhnd, 1.0, 10, 10);
			
			// If should draw a glove
			if (boxer)
			{
				glTranslatef(-handRadius / 5, 0., 0.);
				glutSolidSphere(0.4, 10, 10);
			}

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::left_upper_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SHORTS_TEXTURE_ID]);
			gluQuadricTexture(lul, 1);
			gluCylinder(lul, upperLegRadius, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::left_lower_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(lll, 1);
			gluCylinder(lll, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);
		
		glDisable(GL_TEXTURE_2D);
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

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SHORTS_TEXTURE_ID]);
			gluQuadricTexture(rul, 1);
			gluCylinder(rul, upperLegRadius, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Body::right_lower_leg()
{
	glPushMatrix();
		glRotatef(-90.0, 1.0, 0.0, 0.0);

		glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textures[SKIN_TEXTURE_ID]);
			gluQuadricTexture(rll, 1);
			gluCylinder(rll, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);

		glDisable(GL_TEXTURE_2D);
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
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.85*(torsoTopRadius + JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
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
		glTranslatef(0.85*(torsoTopRadius + JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
		joint_point();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(theta[5], 1.0, 0.0, 0.0);
		glRotatef(theta[12], 0.0, 0.0, 1.0);
		right_upper_arm();
		glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
		joint_point();
		glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
		glRotatef(theta[6], 1.0, 0.0, 0.0);
		right_lower_arm();
		glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
		right_hand();
	glPopMatrix();

	glPushMatrix();	
		glTranslatef(-(TORSO_RADIUS - JOINT_POINT_RADIUS), -0.15*JOINT_POINT_HEIGHT, 0.0);
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
		glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS , -0.15*JOINT_POINT_HEIGHT, 0.0);
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
void Body::init_body(GLuint* bodyTextures, bool isBoxer)
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

	// Define this body textures
	textures = bodyTextures;

	// If it is a boxer body - increase the torso top radius
	if (isBoxer)
	{
		boxer = isBoxer;
		torsoTopRadius = TORSO_TOP_RADIUS;
		handRadius = GLOVE_RADIUS;
		upperLegRadius = UPPER_LEG_TOP_RADIUS;
	}

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