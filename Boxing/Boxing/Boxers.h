#pragma once
#include "Body.h"

class Boxers : public Body
{
public:
	Boxers(){};
	~Boxers(){};
	void draw_boxer1(GLfloat);
	void draw_boxer2(GLfloat);
	//void animate_boxers_walk(void);
	//void animate_boxers_fight(void);
};

