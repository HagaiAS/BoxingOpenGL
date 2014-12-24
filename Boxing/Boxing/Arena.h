#include "Globals.h"

const GLdouble ARENA_SIZE = WINDOW_WIDTH / 5;
const GLdouble ARENA_Y_SCALE = 0.3;
const GLdouble ARENA_ROPES_NUMBER = 4;
const GLdouble ARENA_ROPE_THICKNESS = 2;
const GLdouble ARENA_ROPE_Y_DELTA = (ARENA_SIZE * ARENA_Y_SCALE) / ARENA_ROPES_NUMBER;
const GLdouble ARENA_CORNER_THICKNESS = 7;

const GLdouble WORLD_WIDTH_A = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT_A = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);
const GLdouble FLOOR_Y_A = -WORLD_HEIGHT_A / 2;
const GLdouble FRONT_Z_WALL_A = WORLD_WIDTH_A / 2;

const GLfloat ARENA_AMBIENT_DIFFUSE[] = { 1.0, 0.0, 0.0, 0.1 }; //color of material: red
const GLfloat ARENA_SPECULAR[] = { 1.0, 0.0, 0.0, 0.0 }; //colors of reflection of material:white
const GLfloat ARENA_SHININESS[] = { 10.0 };

void draw_arena(void);
void draw_corners(void);
void draw_ropes(void);
void setArenaMaterial(void);
