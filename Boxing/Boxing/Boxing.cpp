//		  Boxing.cpp
// Harel Ezra , Hagai Asaban
//------------------------------------------------
//#pragma once
#include "Init.h"

//-------------------------------------
//               MAIN
//-------------------------------------

void main(int argc, char **argv)
{
	printInstructions();

	glutInit(&argc, argv);

	Init_Parent();
	Init_Intro();
	//Init_View_Mode();
	//Init_View_Play();
	//Init_Help_Menu();

	// Infinite loop
	glutMainLoop();
}