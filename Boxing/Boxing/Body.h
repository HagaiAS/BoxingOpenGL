#pragma once
#include "Globals.h"

const GLfloat BODY_SCALE = 8;
const GLfloat TORSO_HEIGHT = 5.0 * BODY_SCALE;
const GLfloat TORSO_RADIUS = 1.3 * BODY_SCALE;
const GLfloat UPPER_ARM_HEIGHT = 2.5 * BODY_SCALE;
const GLfloat LOWER_ARM_HEIGHT = 2.3 * BODY_SCALE;
const GLfloat UPPER_ARM_RADIUS = 0.5 * BODY_SCALE;
const GLfloat LOWER_ARM_RADIUS = 0.5 * BODY_SCALE;
const GLfloat UPPER_LEG_RADIUS = 0.5 * BODY_SCALE;
const GLfloat LOWER_LEG_RADIUS = 0.5 * BODY_SCALE;
const GLfloat LOWER_LEG_HEIGHT = 3.1 * BODY_SCALE;
const GLfloat UPPER_LEG_HEIGHT = 3.3 * BODY_SCALE;
const GLfloat HEAD_HEIGHT = 1.2 * BODY_SCALE;
const GLfloat HEAD_RADIUS = 1.4	* BODY_SCALE;
const GLfloat HAND_RADIUS = 0.6	* BODY_SCALE;
const GLfloat HAND_HEIGHT = 0.9	* BODY_SCALE;
const GLfloat FOOT_RADIUS = 0.7	* BODY_SCALE;
const GLfloat FOOT_HEIGHT = 1.1	* BODY_SCALE;
const GLfloat NECK_RADIUS = 0.5	* BODY_SCALE;
const GLfloat NECK_HEIGHT = 1.0	* BODY_SCALE;
const GLfloat JOINT_POINT_RADIUS = 0.5 * BODY_SCALE;
const GLfloat JOINT_POINT_HEIGHT = 0.5 * BODY_SCALE;

const GLdouble ARENA_SIZE_B = WINDOW_WIDTH / 5;
const GLdouble ARENA_Y_SCALE_B = 0.3;
//
const GLdouble WORLD_HEIGHT_B = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);
const GLdouble ARENA_FLOOR_Y = (ARENA_Y_SCALE_B * ARENA_SIZE_B);
const GLdouble FLOOR_Y_B = (-WORLD_HEIGHT_B / 2) + ARENA_FLOOR_Y + LOWER_LEG_HEIGHT + UPPER_LEG_HEIGHT;

void timer_walk(int);
void timer_kick(int);

class Body
{
	public:
		Body(){};
		~Body(){};
		void draw_body(GLfloat*);
		void init_body();
	private:
		void head();
		void neck();
		void torso();
		void joint_point();
		void left_upper_arm();
		void left_lower_arm();
		void left_hand();
		void right_upper_arm();
		void right_lower_arm();
		void right_hand();
		void left_upper_leg();
		void left_lower_leg();
		void left_foot();
		void right_upper_leg();
		void right_lower_leg();
		void right_foot();	
};


//TODO
/*
 - Restart function
 - Stop animation function
 - More body parts' rotation
 - Rotation borders
*/