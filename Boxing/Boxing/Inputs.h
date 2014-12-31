#include "Globals.h"

/*
Mouse and Keyboard control area & view point translation initialization
*/
typedef struct _Area {
	int id;
	int x, y;
	float min, max;
	float value;
	float step;
} Area;

void area_update(Area*, int);
int area_hit(Area*, int, int);
void mouse(int, int, int, int);
void pressed_mouse(int, int);
void keyboard(unsigned char, int, int);
void special_key_input(int, int, int);
void change_size(int, int);
void redisplay_all(void);
void my_idle(void);