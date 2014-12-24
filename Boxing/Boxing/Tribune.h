#include "Globals.h"

const GLint NUMBER_OF_STAIRS = 5;
const GLdouble TRIBUNES_SIZE = (WINDOW_WIDTH / 5) * 1.8;
const GLdouble TRIBUNES_Y_SCALE = 0.05;
const GLdouble TRIBUNES_Z_SCALE = 0.5;

const GLdouble WORLD_WIDTH_T = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT_T = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);
const GLdouble FLOOR_Y_T = -WORLD_HEIGHT_T / 2;
const GLdouble FRONT_Z_WALL_T = WORLD_WIDTH_T / 2;

const GLfloat TRIBUNE_AMBIENT_DIFFUSE[] = { 1.0, 1.0, 0.0, 1.0 }; //color of material: red
const GLfloat TRIBUNE_SPECULAR[] = { 0.0, 0.0, 0.2, 1.0 }; //colors of reflection of material:white
const GLfloat TRIBUNE_SHININESS[] = { 12.0 };

void draw_tribunes();
void draw_tribune();
void setTribuneMaterial();
