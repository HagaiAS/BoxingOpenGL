#include "Globals.h"

// Body parts
const GLdouble HEAD_RADIUS = 16;
const GLdouble HEAD_RADIUS_WIDTH_SCALE = 0.8;
const GLdouble EYE_RADIUS = 5;
const GLdouble NOSE_RADIUS = 5;
const GLdouble NOSE_RADIUS_WIDTH_SCALE = 2.5;

const GLdouble NECK_RADIUS = 6;
const GLdouble NECK_RADIUS_WIDTH_SCALE = 0.6;

const GLdouble BODY_RADIUS_HEIGHT = 60;
const GLdouble BODY_RADIUS_WIDTH_SCALE = 0.3;

const GLdouble HAND_RADIUS_HEIGHT = 20;
const GLdouble HAND_RADIUS_WIDTH_SCALE = 0.4;

const GLdouble LEGS_RADIUS_HEIGHT = 16;
const GLdouble LEGS_RADIUS_WIDTH_SCALE = 0.45;
const GLdouble FOOTS_RADIUS_HEIGHT = 8;
const GLdouble FOOTS_RADIUS_WIDTH_SCALE = 0.4;

const GLdouble ARENA_SIZE_B = WINDOW_WIDTH / 5;
const GLdouble ARENA_Y_SCALE_B = 0.3;

const GLdouble WORLD_HEIGHT_B = WINDOW_HEIGHT - (WINDOW_HEIGHT / 10);
const GLdouble ARENA_FLOOR_Y = (ARENA_Y_SCALE_B * ARENA_SIZE_B);
const GLdouble FLOOR_Y_B = (-WORLD_HEIGHT_B / 2) + ARENA_FLOOR_Y;
const GLdouble TOP_EDGE_B = WINDOW_HEIGHT / 2;

const double angle = START_ANGLE;
const double angle_delta = 0.83;
const double body_angle = START_ANGLE;
const double body_angle_delta = 0.52;
const double arm_angle = START_ANGLE;
const double arm_angle_delta = 1.92;

void draw_boxer();
void draw_head();
void draw_neck();
void draw_body();
void draw_hands();
void draw_legs();
void draw_face();
void draw_ball();
void rotateToFixZ();
