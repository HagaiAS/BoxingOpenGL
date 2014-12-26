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

#define WINDOW_HEIGHT 768
#define WINDOW_WIDTH 1280
#define WINDOW_POS_X 10
#define WINDOW_POS_Y 10
#define Pi 3.14159
#define START_ANGLE 0.0

// Display lists
#define TRIBUNE_LIST 1 
#define ROPES_LIST 2 
#define CROWD_LIST 3 
#define ENTRANCE_LIST 4

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


const GLint NUMBER_OF_STAIRS = 5;
const GLint NUMBER_OF_CROWD_IN_ROW = 9;
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

