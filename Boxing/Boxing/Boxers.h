#pragma once
#include "Body.h"

class Boxers : public Body
{
	public:
		GLfloat *BoxerAngles1;
		GLfloat *BoxerAngles2;

		Boxers();
		~Boxers(){};
		void draw_boxer1(GLfloat);
		void draw_boxer2(GLfloat);
		void animate_boxers_walk(GLfloat*);
		void animate_boxers_fight(GLfloat*);
};