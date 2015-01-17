#pragma once
#include "Globals.h"

const GLfloatPoint arrColorArray[7] = 
{
	{ 0.75, 0.5, 0.0 },
	{ 0.75, 0.0, 0.75 },
	{ 0.0, 0.75, 0.5 },
	{ 1.0, 1.0, 0.0 },
	{ 0.75, 0.0, 0.0 },
	{ 0.0, 0.0, 0.75 },
	{ 0.6, 0.8, 1.0 }
};

// print bitmap text
void BitmapText(GLfloatPoint location, char *string)
{
	char *c;

	glRasterPos3f(location.x, location.y, location.z);    //definition of position

	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

// print stroke text
void StrokeText(char *string, GLfloatPoint location, int strokeSize = 8, GLfloatPoint scale = { 0.04, 0.06, 0 })
{
	char *c;
	GLfloat alfa = 0.03;
	for (int i = 0; i < strokeSize; i++)
	{
		glPushMatrix();
		glTranslatef(location.x + (i * alfa), -location.y, location.z);  //definition of position
		glScalef(scale.x, scale.y, scale.z);

		for (c = string; *c != '\0'; c++)
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *c);
		glPopMatrix();
	}
}

// print big logo title 
void PrintStrokeText(char *logo,
	GLfloatPoint location,
	GLfloatPoint strokeColor = { 1.0, 1.0, 1.0 },
	GLfloatPoint scaleLogo = { 0.01, 0.022, 0 },
	int strokeSize = 8,
	GLfloat delta = 1.2,
	bool multiColor = false,
	GLfloatPoint shadowColor = { 0.2, 0.2, 0.2 })
{
	char* c = logo;
	GLfloat alfa = -0.2;
	GLfloatPoint color;

	for (int i = 0; logo[i]; i++)
	{
		char c = logo[i];
		GLfloatPoint strokeLocation = location;
		strokeLocation.x += delta * i;
		GLfloatPoint shadowLocation = strokeLocation;

		shadowLocation.x -= alfa;
		shadowLocation.y -= alfa;
		shadowLocation.z -= alfa;
		glColor3f(shadowColor.x, shadowColor.y, shadowColor.z);
		StrokeText(&c, shadowLocation, strokeSize, scaleLogo);

		// print multi color
		if (multiColor)
		{
			color = arrColorArray[i];
			glColor3f(color.x, color.y, color.z);
		}
		else
		{
			glColor3f(strokeColor.x, strokeColor.y, strokeColor.z);
		}

		StrokeText(&c, strokeLocation, strokeSize, scaleLogo);

	}
}

// print menu items
void printMenuItems(char* menuItems[],
	int numOfItems,
	GLfloatPoint menuLocation,
	GLfloatPoint scaleHeaderMenuItem = { 0.014, 0.028, 0.0 },
	GLfloatPoint colorHeaderMenuItem = { 0.0, 1.0, 0.2 })
{
	GLfloat delta = 4;
	GLfloat alfa = -0.2;
	GLfloat shadow = -0.2;
	GLfloatPoint titleLocation = menuLocation;
	titleLocation.x += (2 / numOfItems + 1) * 4;
	PrintStrokeText(menuItems[0], titleLocation, colorHeaderMenuItem, scaleHeaderMenuItem, 8, 1.35);

	for (int i = 1; i <= numOfItems; i++)
	{
		char* item = menuItems[i];
		GLfloatPoint itemLocation = menuLocation;
		itemLocation.y += delta * i;
		PrintStrokeText(item, itemLocation);
	}
}