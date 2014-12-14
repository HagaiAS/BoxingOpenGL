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

void draw_axes();
void draw_world();
