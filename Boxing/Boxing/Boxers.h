#pragma once
#include "Body.h"

class Boxers : public Body
{
	public:
		GLfloat red, green, blue = 0;
		GLfloat *BoxerAngles;
		GLdouble BoxersDistance = 80.0;
		GLdouble BoxersMoveLegs = 12.0;
		bool isOpponent;

		Boxers(){};
		Boxers(GLfloat*);
		~Boxers(){};
		void init_body(GLuint*, bool, GLfloat, GLfloat, GLfloat);
		void draw_boxer(GLfloat);
		void animate_boxer_walk();
		void animate_boxer_fight();
};