#include "Globals.h"
const GLdouble WORLD_WIDTH_E = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT_E = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);

const GLdouble FLOOR_Y_E = -WORLD_HEIGHT_E / 2;
const GLdouble FRONT_Z_WALL_E = WORLD_WIDTH_E / 2;
const GLdouble RIGHT_X_WALL_E = WORLD_WIDTH_E / 2;
const GLdouble RIGHT_X_WALL_E_DELTA = -WORLD_WIDTH_E / 6;

const GLdouble ENTRANCE_SIDES_THICKNESS = 5;
const GLdouble ENTRANCE_TOP_THICKNESS = 5;
const GLdouble ENTRANCE_HEIGHT = 150;
const GLdouble ENTRANCE_WIDTH = 80;

void draw_entrance(void);