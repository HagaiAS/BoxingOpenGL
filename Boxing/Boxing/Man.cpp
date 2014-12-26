//#pragma once
//#include <iostream>
//#include "time.h"
//#include "cstdlib"
//#include <glut.h> 
//#include <math.h> 
//#include <stdio.h>
//#include <string.h>
//#include <stdarg.h>
//#include <stdlib.h>
//
////================================Humanoid Robot====================================
//const GLfloat BODY_SCALE = 12;
//const GLfloat TORSO_HEIGHT = 5.0 * BODY_SCALE;
//const GLfloat TORSO_RADIUS = 1.3 * BODY_SCALE;
//const GLfloat UPPER_ARM_HEIGHT = 2.5 * BODY_SCALE;
//const GLfloat LOWER_ARM_HEIGHT = 2.3 * BODY_SCALE;
//const GLfloat UPPER_ARM_RADIUS = 0.5 * BODY_SCALE;
//const GLfloat LOWER_ARM_RADIUS = 0.5 * BODY_SCALE;
//const GLfloat UPPER_LEG_RADIUS = 0.5 * BODY_SCALE;
//const GLfloat LOWER_LEG_RADIUS = 0.5 * BODY_SCALE;
//const GLfloat LOWER_LEG_HEIGHT = 3.1 * BODY_SCALE;
//const GLfloat UPPER_LEG_HEIGHT = 3.3 * BODY_SCALE;
//const GLfloat HEAD_HEIGHT = 1.2 * BODY_SCALE;
//const GLfloat HEAD_RADIUS = 1.4	* BODY_SCALE;
//const GLfloat HAND_RADIUS = 0.6	* BODY_SCALE;
//const GLfloat HAND_HEIGHT = 0.9	* BODY_SCALE;
//const GLfloat FOOT_RADIUS = 0.7	* BODY_SCALE;
//const GLfloat FOOT_HEIGHT = 1.1	* BODY_SCALE;
//const GLfloat NECK_RADIUS = 0.5	* BODY_SCALE;
//const GLfloat NECK_HEIGHT = 1.0	* BODY_SCALE;
//const GLfloat JOINT_POINT_RADIUS = 0.5 * BODY_SCALE;
//const GLfloat JOINT_POINT_HEIGHT = 0.5 * BODY_SCALE;
//const int WIN_HEIGHT = 1280;
//const int WIN_WIDTH = 768;
//
///*
//Define of body properties
//*/
//bool flag1 = true, flag2 = false,
//flag3 = true, flag4 = false,
//flag5 = true, flag6 = false,
//hflag = true;
//
///*
//Body parts
//*/
//GLUquadricObj *t, *h, *n, *lh,
//*rh, *lf, *rf, *jp,
//*lhnd, *lft, *lua, *lla,
//*rua, *rla, *lll, *rll,
//*rul, *lul, *rhnd, *rft;
//
///*
//Animation variables and angles
//*/
//GLuint texture1 = 0;
//GLuint texture2 = 0;
//GLuint texture3 = 0;
//GLuint texture4 = 0;
//
//
//GLfloat theta[17] =
//{
//	0.0, 0.0, 0.0, 30.0,
//	-120.0, 40.0, -80.0, 180.0,
//	10.0, 180.0, 40.0, 5.0,
//	0.0, 0.0, 0.0, 20.0, 0.0
//};
//
///*
//Mouse and Keyboard control area & view point translation initialization
//*/
//typedef struct _area {
//	int id;
//	int x, y;
//	float min, max;
//	float value;
//	float step;
//} area;
//
//area translation[5] = {
//	{ 0, 120, 40, -30.0, 30.0, 0.0, 0.05 },
//	{ 1, 180, 40, -30.0, 30.0, 0.0, 0.05 },
//	{ 2, 180, 40, -200.0, 200.0, 0.0, 0.1 },
//	{ 3, 180, 120, -100, 100, 0.0, 0.5 },
//	{ 4, 240, 120, -100, 100, 0.0, 0.5 }
//};
//
///*
//gluLookAt initial values, view point rotation
//*/
//GLfloat eye[3] = { 0.0, 0.0, 60.0 };
//GLfloat at[3] = { 0.0, 0.0, 0.0 };
//GLfloat up[3] = { 0.0, 1.0, 0.0 };
//
//GLuint old_thetaW3 = 0;
//GLuint old_thetaX4 = 0;
//GLuint old_thetaE5 = 0;
//GLuint old_thetaC6 = 0;
//GLuint old_thetaS11 = 0;
//GLuint old_thetaD12 = 0;
//GLint selection = 0;
//
//static GLint choise = 2;
//static GLint m_choise = 0;
//
//
//class Body
//{
//public:
//	Body(){};
//	~Body(){};
//	void drawCyborg();
//	void head();
//	void neck();
//	void torso();
//	void joint_point();
//	void left_upper_arm();
//	void left_lower_arm();
//	void left_hand();
//	void right_upper_arm();
//	void right_lower_arm();
//	void right_hand();
//	void left_upper_leg();
//	void left_lower_leg();
//	void left_foot();
//	void right_upper_leg();
//	void right_lower_leg();
//	void right_foot();
//};
//
//void timer_walk(int);
//void timer_kick(int);
//
////--------------------------------draw body functions-------------------------------
//void Body::head(){
//   glPushMatrix();
//   glColor3f (1.0, 0.0, 5.0);
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   glRotatef(15.0, 0.0, 0.0, 1.0);
//   glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);
//   gluSphere(h,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::neck(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::torso(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::joint_point(){
//   glPushMatrix();
//   glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, 
//								JOINT_POINT_RADIUS);
//   gluSphere(jp,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::left_upper_arm(){
//   glPushMatrix();
//   gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
//									UPPER_ARM_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::left_lower_arm(){
//   glPushMatrix();
//   glRotatef(0.0, 1.0, 0.0, 0.0);
//   gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
//									LOWER_ARM_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::left_hand(){
//   glPushMatrix();
//   glRotatef(90.0, 1.0, 0.0, 0.0);
//   glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
//   gluSphere(lhnd,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::right_upper_arm(){
//   glPushMatrix();
//   gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, 
//									UPPER_ARM_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::right_lower_arm(){
//   glPushMatrix();
//   gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, 
//									LOWER_ARM_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::right_hand(){
//   glPushMatrix();
//   glRotatef(90.0, 1.0, 0.0, 0.0);
//   glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
//   gluSphere(rhnd,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::left_upper_leg(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
//									UPPER_LEG_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::left_lower_leg(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
//									LOWER_LEG_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::left_foot(){
//   glPushMatrix();
//   glRotatef(90.0, 1.0, 0.0, 0.0);
//   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
//   gluSphere(lft,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::right_upper_leg(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, 
//									UPPER_LEG_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::right_lower_leg(){
//   glPushMatrix();
//   glRotatef(-90.0, 1.0, 0.0, 0.0);
//   gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, 
//									LOWER_LEG_HEIGHT,10,10);
//   glPopMatrix();
//}
//
//void Body::right_foot(){
//   glPushMatrix();
//   glRotatef(90.0, 1.0, 0.0, 0.0);
//   glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
//   gluSphere(rft,1.0,10,10);
//   glPopMatrix();
//}
//
//void Body::drawCyborg() {
//
//	glRotatef(theta[0], 0.0, 1.0, 0.0);
//    torso();
//	glPushMatrix();
//
//	glTranslatef(0,TORSO_HEIGHT, 0.0);
//	neck();
//
//	glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
//	glRotatef(theta[1], 1.0, 0.0, 0.0);
//    glRotatef(theta[2], 0.0, 1.0, 0.0);
//    head();
//
//	glPopMatrix();//add JOINT_POINT_
//    glPushMatrix();//add JOINT_POINT_
//
//	glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
//									0.9*TORSO_HEIGHT, 0.0);
//	joint_point();
//
//	glTranslatef(0.0, 0.0, 0.0);
//	glRotatef(theta[3], 1.0, 0.0, 0.0);
//	glRotatef(theta[11], 0.0, 0.0, 1.0);
//    left_upper_arm();
//
//	glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
//	joint_point();
//
//    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[4], 1.0, 0.0, 0.0);
//    left_lower_arm();
//
//	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
//	left_hand();
//
//    glPopMatrix();
//    glPushMatrix();
//
//	glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 
//									0.9*TORSO_HEIGHT, 0.0);
//	joint_point();
//
//    glTranslatef(0.0, 0.0, 0.0);
//    glRotatef(theta[5], 1.0, 0.0, 0.0);
//	glRotatef(theta[12], 0.0, 0.0, 1.0);
//    right_upper_arm();
//
//    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
//	joint_point();
//
//	glBindTexture(GL_TEXTURE_2D, texture4);
//    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[6], 1.0, 0.0, 0.0);
//    right_lower_arm();
//
//	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
//	right_hand();
//
//    glPopMatrix();
//    glPushMatrix();
//	
//	glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), 
//							-0.15*JOINT_POINT_HEIGHT, 0.0);
//	joint_point();
//
//	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[7], 1.0, 0.0, 0.0);
//	glRotatef(theta[13], 0.0, 0.0, 1.0);
//    left_upper_leg();
//
//	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
//	joint_point();
//
//    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[8], 1.0, 0.0, 0.0);
//    left_lower_leg();
//
//    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
//	glRotatef(theta[15], 1.0, 0.0, 0.0);
//	left_foot();
//
//    glPopMatrix();
//    glPushMatrix();
//
//    glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, 
//							-0.15*JOINT_POINT_HEIGHT, 0.0);
//	joint_point();
//
//	glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[9], 1.0, 0.0, 0.0);
//	glRotatef(theta[14], 0.0, 0.0, 1.0);
//    right_upper_leg();
//
//	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
//	joint_point();
//
//    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
//    glRotatef(theta[10], 1.0, 0.0, 0.0);
//    right_lower_leg();
//	
//	glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
//	glRotatef(theta[16], 1.0, 0.0, 0.0);
//	right_foot();
//    
//	glPopMatrix();
//}
////--------------------------------Display function--------------------------------
//void myDisplay(void)
//{
//	Body b;
//	glClearColor(1, 1, 0.5, 0.0);
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glColor3f(0.0, 0.0, 0.0);
//	glColor3ub(0, 0, 0);
//	b.drawCyborg();
//    glFlush();
//    glutSwapBuffers();
//}
//
////--------------------------------Keyboard control function-----------------------
//void keyboard(unsigned char key, int x, int y)
//{
//	if(key=='q') {choise=2;}		// Head horiz
//	if(key=='a') {choise=1;}		// Head vert
//
//	if(key=='w') {choise=3;}	//left arm horiz
//	if(key=='s') {choise=11;}		//left arm vert
//
//	if(key=='e') {choise=5;}	//right arm horiz
//	if(key=='d') {choise=12;}		//right arm horiz
//
//	if(key=='r') {choise=7;}		//left leg vert
//	if(key=='f') {choise=13;}	//left leg horiz
//
//	if(key=='t') {choise=9;}		//right leg horiz
//	if(key=='g') {choise=14;}	//right leg vert
//
//	if(key=='z') {choise=0;}		//torso
//
//	if(key=='x') {choise=4;}		//left_lower_arm
//
//	if(key=='c') {choise=6;}		//right_lower_arm
//
//	if(key=='v') {choise=8;}		//left_lower_leg
//
//	if(key=='b') {choise=10;}	//right_lowerleg
//
//	if(key==',') {choise=15;}	//left_foot
//
//	if(key=='.') {choise=16;}	//right_foot
//	
//	if(key=='m') {glutTimerFunc(100,timer_walk,0);}	//animation walk
//
//	if(key=='n') {
//		old_thetaW3=theta[3];
//		old_thetaX4=theta[4];
//		old_thetaE5=theta[5];
//		old_thetaC6=theta[6];
//		old_thetaS11=theta[11];
//		old_thetaD12=theta[12];
//
//		theta[3]=0;	// 0-30
//		theta[4]=0;	// 0
//		theta[11]=-15;	// 0
//		theta[5]=60;	// 0
//		theta[6]=-120;	// 0
//		theta[12]=15;	// 0
//		glutTimerFunc(200,timer_kick,0);/*glutTimerFunc(100,timer_kick,0);*/
//	}	//animation kick
//
//	if(key=='9') {
//		theta[choise] += 5.0;
//		if( theta[choise] > 360.0 ) theta[choise] -= 360.0;
//		glutPostRedisplay();
//	}
//	if(key=='0') {
//		theta[choise] -= 5.0;
//		if( theta[choise] < 360.0 ) theta[choise] += 360.0;
//		glutPostRedisplay();
//	}
//}
//
////--------------------------------Reshape & redisplay functions-------------------
//void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	if (w <= h)
//		glOrtho(-30.0, 30.0, -30.0 * (GLfloat)h / (GLfloat)w,
//		30.0 * (GLfloat)h / (GLfloat)w, -200, 200);
//	else
//		glOrtho(-30.0 * (GLfloat)w / (GLfloat)h,
//		30.0 * (GLfloat)w / (GLfloat)h, -30.0, 30.0, -200, 200);
//
//	gluPerspective(1.0, (float)w / h, 2.0, 1.0);
//	gluLookAt(translation[3].value, translation[4].value, eye[2],
//		at[0], at[1], at[2], up[0], up[1], up[2]);
//	glTranslatef(translation[0].value, translation[1].value,
//		translation[2].value);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void redisplay_all(void) {
//	myReshape(WIN_WIDTH, WIN_HEIGHT);
//	glutPostRedisplay();
//}
//
//
////--------------------------------Display area for mouse conrol-------------------
//void area_update(area* area, int update){
//    if (selection != area->id)
//	return;
//
//    area->value += update * area->step;
//
//    if (area->value < area->min)
//	area->value = area->min;
//    else if (area->value > area->max) 
//	area->value = area->max;
//
//}
//
//int area_hit(area* area, int x, int y){
//    if ((x > 0 && x < WIN_WIDTH) &&
//		(y > 0 && y < WIN_HEIGHT))
//	return area->id;
//    return 0;
//}
//
//int old_y, old_x;
//
//void mouse(int button, int state, int x, int y)
//{
//    selection = 0;
//	if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN 
//									&& (m_choise==0||m_choise==2)) {
//		selection += area_hit(&translation[0], x, y);
//		if (m_choise==0) selection += area_hit(&translation[0], x, y);
//		if (m_choise==2) selection += area_hit(&translation[3], x, y);
//		old_x = x;
//		redisplay_all();
//    }
//	if (button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN 
//					&& ((m_choise==0||m_choise==1)||m_choise==2)) {
//		if (m_choise==0) selection += area_hit(&translation[1], x, y);
//		if (m_choise==1) selection += area_hit(&translation[2], x, y);
//		if (m_choise==2) selection += area_hit(&translation[4], x, y);
//		old_y = y;
//		redisplay_all();
//    } 
//}
//
//void pressed_mouse(int x, int y)
//{
//    area_update(&translation[0], x-old_x);
//    area_update(&translation[1], old_y-y);
//    area_update(&translation[2], old_y-y);
//	area_update(&translation[3], x-old_x);
//    area_update(&translation[4], old_y-y);
//	old_y = y;
//	old_x = x;
//
//	redisplay_all();
//}
//
//void menu(int id) {
//   if(id <3 ) m_choise=id;
//   if(id == 3 ) exit(1);
//}
//
////--------------------------------Animation timer functions-----------------------
//void timer_walk(int) 
//{
//		if(flag1) {
//			theta[3] += 5.0;
//		}
//		else {
//			theta[3] -= 5.0;
//		}
//		if(theta[3] >= 110.0) flag1 = false;
//		if(theta[3] <= 70.0)  flag1 = true;
//		
//		if(flag2) {
//		theta[5] += 5.0;
//		}
//		else {
//			theta[5] -= 5.0;
//		}
//		if(theta[5] >= 110.0) flag2 = false;
//		if(theta[5] <= 70.0)  flag2 = true;
//		
//		if(flag3) {
//			theta[9] += 5.0;
//		}
//		else {
//			theta[9] -= 5.0;
//		}
//		if(theta[9] >= 200.0) flag3 = false;
//		if(theta[9] <= 160.0)  flag3 = true;
//		
//		if(flag4) {
//			theta[7] += 5.0;
//		}
//		else {
//			theta[7] -= 5.0;
//		}
//		if(theta[7] >= 200.0) flag4 = false;
//		if(theta[7] <= 160.0)  flag4 = true;
//		
//		if(hflag) {
//			theta[2] += 5.0;
//		}
//		else {
//			theta[2] -= 5.0;
//		}
//		if(theta[2] >= 30.0) hflag = false;
//		if(theta[2] <= -30.0) hflag = true;
//		
//		glutPostRedisplay();
//	    glutTimerFunc(100,timer_walk,0);
//}
//void timer_kick(int)
//{
//	if(flag1) {
//		theta[3] -= 15.0;
//	}
//	else {
//		theta[3] += 15.0;
//	}
//	if(theta[3] >= 60) flag1 = true;
//	if(theta[3] <= 0)  flag1 = false;	// 0-45
//
//	if(flag2) {
//		theta[4] -= 30;
//	}
//	else {
//		theta[4] += 30;
//	}
//	if(theta[4] >= 0) flag2 = true;
//	if(theta[4] <= -120)  flag2 = false;
//	theta[11]=-15;	// 0
//	
//	if(flag3) {
//		theta[5] -= 15.0;
//	}
//	else {
//		theta[5] += 15.0;
//	}
//	if(theta[5] >= 60) flag3 = true;
//	if(theta[5] <= 0)  flag3 = false;	// 0-45
//	
//	if(flag4) {
//		theta[6] -= 30;
//	}
//	else {
//		theta[6] += 30;
//	}
//	if(theta[6] >= 0) flag4 = true;
//	if(theta[6] <= -120)  flag4 = false;
//	
//	if(flag5) {
//		theta[9] += 10.0;
//	}
//	else {
//		theta[9] -= 10.0;
//	}
//	if(theta[9] >= 200.0) flag5 = false;
//	if(theta[9] <= 160.0)  flag5 = true;
//	
//	if(flag6) {
//		theta[7] += 10.0;
//	}
//	else {
//		theta[7] -= 10.0;
//	}
//	if(theta[7] >= 200.0) flag6 = false;
//	if(theta[7] <= 160.0)  flag6 = true;
//
//	glutPostRedisplay();
//	glutTimerFunc(200,timer_kick,0);
//}
//
////--------------------------------Initialization function-------------------------
//void myInit()
//{
//        GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
//        GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
//        GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};
//        GLfloat mat_shininess={100.0};
//        GLfloat light_ambient[]={0.0, 0.0, 0.0, 1.0};
//        GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
//        GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
//        GLfloat light_position[]={10.0, 10.0, 10.0, 0.0};
//
//        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//        glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
//
//        glShadeModel(GL_SMOOTH);
//        glEnable(GL_LIGHTING); 
//        glEnable(GL_LIGHT0);
//        glDepthFunc(GL_LEQUAL);
//        
///* allocate quadrics with filled drawing style */
//        h=gluNewQuadric();
//		gluQuadricDrawStyle(h, GLU_FILL);
//		
//		n=gluNewQuadric();
//		gluQuadricDrawStyle(n, GLU_FILL);
//
//		t=gluNewQuadric();
//		gluQuadricDrawStyle(t, GLU_FILL);
//
//		jp=gluNewQuadric();
//		gluQuadricDrawStyle(jp, GLU_FILL);
//
//        lua=gluNewQuadric();
//    	gluQuadricDrawStyle(lua, GLU_FILL);
//
//        lla=gluNewQuadric();
//        gluQuadricDrawStyle(lla, GLU_FILL);
//
//        lhnd=gluNewQuadric();
//		gluQuadricDrawStyle(lhnd, GLU_FILL);
//
//		rhnd=gluNewQuadric();
//		gluQuadricDrawStyle(rhnd, GLU_FILL);
//
//		rft=gluNewQuadric();
//		gluQuadricDrawStyle(rft, GLU_FILL);
//
//		lft=gluNewQuadric();
//		gluQuadricDrawStyle(lft, GLU_FILL);
//
//		rua=gluNewQuadric();
//        gluQuadricDrawStyle(rua, GLU_FILL);
//
//        rla=gluNewQuadric();
//        gluQuadricDrawStyle(rla, GLU_FILL);
//
//        lul=gluNewQuadric();
//        gluQuadricDrawStyle(lul, GLU_FILL);
//
//        lll=gluNewQuadric();
//        gluQuadricDrawStyle(lll, GLU_FILL);
//
//        rul=gluNewQuadric();
//        gluQuadricDrawStyle(rul, GLU_FILL);
//
//        rll=gluNewQuadric();
//        gluQuadricDrawStyle(rll, GLU_FILL);
//}
//
//void main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
//	glutInitWindowPosition(50, 50);
//    glutCreateWindow("Humanoid");
//    myInit();
//	glutReshapeFunc(myReshape);
//    glutDisplayFunc(myDisplay);
//	glutMotionFunc(pressed_mouse);
//	glutMouseFunc(mouse);
//	glutCreateMenu(menu);
//	glutAddMenuEntry("view_hor/vert", 0);
//    glutAddMenuEntry("view_zoom_in/out", 1);
//	glutAddMenuEntry("view_lft-rgt/up-dow", 2);
//	glutAddMenuEntry("quit", 3);
//    glutAttachMenu(GLUT_MIDDLE_BUTTON);
//	glutKeyboardFunc(keyboard);
//	redisplay_all();
//    glutMainLoop();
//}
