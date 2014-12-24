#include "Globals.h"

// World
const GLdouble WORLD_WIDTH = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);

// Edges
const GLdouble LEFT_EDGE = -WINDOW_WIDTH / 2;
const GLdouble RIGHT_EDGE = WINDOW_WIDTH / 2;
const GLdouble BOTTOM_EDGE = -WINDOW_HEIGHT / 2;
const GLdouble TOP_EDGE = WINDOW_HEIGHT / 2;
const GLdouble OUTSIDE_EDGE = -WINDOW_WIDTH / 2;
const GLdouble INSIDE_EDGE = WINDOW_WIDTH / 2;

// Roof, Floor, walls
const GLdouble ROOF_Y = WORLD_HEIGHT / 2;
const GLdouble FLOOR_Y = -WORLD_HEIGHT / 2;
const GLdouble FRONT_Z_WALL = WORLD_WIDTH / 2;
const GLdouble BACK_Z_WALL = -WORLD_WIDTH / 2;
const GLdouble RIGHT_X_WALL = WORLD_WIDTH / 2;
const GLdouble LEFT_X_WALL = -WORLD_WIDTH / 2;

// Lights
const GLfloat LIGHT_POS_X = 0;
const GLfloat LIGHT_POS_Y = 100;
const GLfloat LIGHT_POS_Z = 0;
const GLfloat LIGHT0_DIFFUSE[] = { 1.0, 1.0, 1.0, 1. };     //color of light - white 
const GLfloat LIGHT0_POSITION[] = { LIGHT_POS_X, LIGHT_POS_Y, LIGHT_POS_Z, 1.}; //w=1; for position of positional source(point of light) to all directions

void draw_axes();
void draw_world();
void draw_lamp();