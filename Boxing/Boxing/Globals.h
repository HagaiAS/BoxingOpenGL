#pragma once
#include <iostream>
#include "time.h"
#include "cstdlib"
#include <glut.h> 
#include <math.h> 
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define WINDOW_HEIGHT	768
#define WINDOW_WIDTH	1280
#define WINDOW_POS_X	10
#define WINDOW_POS_Y	10
#define Pi				3.14159
#define START_ANGLE		0.0
#define TIMERMSECS		30 
#define NUM_OF_BODY_TEXTURES 6
#define NUM_OF_WORLD_TEXTURES 2
#define NUM_OF_FLOOR_TILES 12
#define BOXERS_MIN_DISTANCE 25

// Do not change these values - it is relevant for the specific scene
#define TIME_DELTA 0.1
#define TIME_PARTS 3
#define SCENE_TOTAL_SEC 80
#define TIME_PART SCENE_TOTAL_SEC / TIME_PARTS

#define WALL_TEXTURE_ID 0
#define FLOOR_TEXTURE_ID 1

#define HEAD_TEXTURE_ID 0
#define BODY_TEXTURE_ID 1
#define HAND_TEXTURE_ID 2
#define GLOVE_TEXTURE_ID 3
#define SKIN_TEXTURE_ID 4
#define SHORTS_TEXTURE_ID 5
#define UNDEFINED_TEXTURE_ID 6

// Display lists
#define TRIBUNE_LIST			1 
#define ROPES_LIST				2 
#define ENTRANCE_LIST			3
#define CROWD_ROW_LIST			4
#define CROWD_CLAPPING_LIST		5
#define CROWD_HANDS_UP_LIST		6

// World
const GLdouble WORLD_WIDTH = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT = WINDOW_HEIGHT - (WINDOW_HEIGHT / 12);

// Edges
const GLdouble LEFT_EDGE = -WINDOW_WIDTH / 2;
const GLdouble RIGHT_EDGE = WINDOW_WIDTH / 2;
const GLdouble BOTTOM_EDGE = -WINDOW_HEIGHT / 2;
const GLdouble TOP_EDGE = WINDOW_HEIGHT / 2;
const GLdouble OUTSIDE_EDGE = -WINDOW_WIDTH / 2;
const GLdouble INSIDE_EDGE = WINDOW_WIDTH / 2;


const GLint NUMBER_OF_STAIRS = 5;
const GLint NUMBER_OF_CROWD_IN_ROW = 9;
const GLint NUMBER_OF_CROWD_COLORS = 5;
const GLdouble TRIBUNES_SIZE = (WINDOW_WIDTH / 5) * 1.8;
const GLdouble TRIBUNES_Y_SCALE = 0.05;
const GLdouble TRIBUNES_Z_SCALE = 0.5;

const GLdouble WORLD_WIDTH_T = WINDOW_WIDTH - (WINDOW_WIDTH / 10);
const GLdouble WORLD_HEIGHT_T = WINDOW_HEIGHT - (WINDOW_HEIGHT / 12);
const GLdouble FLOOR_Y_T = -WORLD_HEIGHT_T / 2;
const GLdouble FRONT_Z_WALL_T = WORLD_WIDTH_T / 2;
const GLdouble RIGHT_X_WALL_T = WORLD_WIDTH_T / 2;

const GLfloat TRIBUNE_AMBIENT_DIFFUSE[] = { 1.0, 1.0, 0.0, 1.0 }; //color of material: red
const GLfloat TRIBUNE_SPECULAR[] = { 0.0, 0.0, 0.2, 1.0 }; //colors of reflection of material:white
const GLfloat TRIBUNE_SHININESS[] = { 12.0 };

extern GLfloat BoxerAng1[17];
extern GLfloat BoxerAng2[17];
extern GLuint worldTextures[NUM_OF_WORLD_TEXTURES];
const GLdouble ARENA_SIZE_C = WINDOW_WIDTH / 5;