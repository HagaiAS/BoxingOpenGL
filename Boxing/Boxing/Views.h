#pragma once
#include "Globals.h"
#include "Print.h"

void WelcomeIntroWindow(void)
{
	char* headerItems[] = {
		{ " Created By: " },
		{ " Harel Ezra - ID: 201591799 " },
		{ " Hagai Asaban - ID: 302897509 " }
	};

	char* menuItems[] = {
		{ " Menu: " },
		{ " F1 -> View Mode " },
		{ " F2 -> Play Mode " },
		{ "	F4 -> Exit " }
	};

	GLfloatPoint sceLogoLocation = { -16.0, -21, 0.0 };
	GLfloatPoint sceLogoColor = { 1.0, 1.0, 1.0 };
	GLfloatPoint sceScaleLogo = { 0.02, 0.03, 0.0 };
	GLfloatPoint movieLogoColor = { 0, 0.5, 0.8 };
	PrintStrokeText(" SCE", sceLogoLocation, sceLogoColor, sceScaleLogo, 20, 2, false);


	GLfloatPoint movieLogoLocation = sceLogoLocation;
	movieLogoLocation.x += 8;
	movieLogoLocation.y -= 0.5;

	GLfloatPoint movieScaleLogo = { 0.01, 0.02, 0.0 };
	PrintStrokeText(" Movies Production", movieLogoLocation, movieLogoColor, movieScaleLogo, 8, 1.2, false);

	GLfloatPoint lineLocation = { -24.0, -20.5, 0.0 };
	char* line = "________________________________";
	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint creditHeaderItems = { -16, -16, 0.0 };
	printMenuItems(headerItems, 2, creditHeaderItems);

	GLfloatPoint boxerLogoLocation = { -12.0, 1.5, 0.0 };
	GLfloatPoint boxerScaleLogo = { 0.04, 0.06, 0 };
	int boxerStrokeSize = 24;
	GLfloat boxerDelta = 4;
	PrintStrokeText("BOXING", boxerLogoLocation, movieLogoColor, boxerScaleLogo, boxerStrokeSize, boxerDelta, true);

	lineLocation.y = boxerLogoLocation.y + 1;

	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint menuLocation = { -8.2, 8, 0.0 };
	printMenuItems(menuItems, 3, menuLocation);
}

void ViewModeSubWindow(void)
{
	char* headerItems[] = {
		{ " View Mode: " },
		{ " H  -> Help " },
		{ "Esc -> Back To Menu " }
	};

	char* menuItems[] = {
		{ " Menu: " },
		{ " F1 -> View Mode " },
		{ " F2 -> Play Mode " },
		{ "	F4 -> Exit the program " }
	};

	GLfloatPoint sceLogoLocation = { -16.0, -21, 0.0 };
	GLfloatPoint sceLogoColor = { 1.0, 1.0, 1.0 };
	GLfloatPoint sceScaleLogo = { 0.02, 0.03, 0.0 };
	GLfloatPoint movieLogoColor = { 0, 0.5, 0.8 };
	PrintStrokeText(" SCE", sceLogoLocation, sceLogoColor, sceScaleLogo, 20, 2, false);


	GLfloatPoint movieLogoLocation = sceLogoLocation;
	movieLogoLocation.x += 8;
	movieLogoLocation.y -= 0.5;

	GLfloatPoint movieScaleLogo = { 0.01, 0.02, 0.0 };
	PrintStrokeText(" Movies Production", movieLogoLocation, movieLogoColor, movieScaleLogo, 8, 1.2, false);

	GLfloatPoint lineLocation = { -24.0, -20.5, 0.0 };
	char* line = "________________________________";
	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint creditHeaderItems = { -16, -16, 0.0 };
	printMenuItems(headerItems, 2, creditHeaderItems);

	GLfloatPoint boxerLogoLocation = { -12.0, 1.5, 0.0 };
	GLfloatPoint boxerScaleLogo = { 0.04, 0.06, 0 };
	int boxerStrokeSize = 24;
	GLfloat boxerDelta = 4;
	PrintStrokeText("BOXING", boxerLogoLocation, movieLogoColor, boxerScaleLogo, boxerStrokeSize, boxerDelta, true);

	lineLocation.y = boxerLogoLocation.y + 1;

	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint menuLocation = { -8.2, 8, 0.0 };
	printMenuItems(menuItems, 3, menuLocation);
}

void PlayModeSubWindow(void)
{
	char* headerItems[] = {
		{ " Play Mode: " },
		{ " H  -> Help " },
		{ "Esc -> Back To Menu " }
	};

	char* menuItems[] = {
		{ " Play Mode: " },
		{ " F1 -> View Mode " },
		{ " F2 -> Play Mode " },
		{ "	F4 -> Exit the program " }
	};

	GLfloatPoint sceLogoLocation = { -16.0, -21, 0.0 };
	GLfloatPoint sceLogoColor = { 1.0, 1.0, 1.0 };
	GLfloatPoint sceScaleLogo = { 0.02, 0.03, 0.0 };
	GLfloatPoint movieLogoColor = { 0, 0.5, 0.8 };
	PrintStrokeText(" SCE", sceLogoLocation, sceLogoColor, sceScaleLogo, 20, 2, false);


	GLfloatPoint movieLogoLocation = sceLogoLocation;
	movieLogoLocation.x += 8;
	movieLogoLocation.y -= 0.5;

	GLfloatPoint movieScaleLogo = { 0.01, 0.02, 0.0 };
	PrintStrokeText(" Movies Production", movieLogoLocation, movieLogoColor, movieScaleLogo, 8, 1.2, false);

	GLfloatPoint lineLocation = { -24.0, -20.5, 0.0 };
	char* line = "________________________________";
	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint creditHeaderItems = { -16, -16, 0.0 };
	printMenuItems(headerItems, 2, creditHeaderItems);

	GLfloatPoint boxerLogoLocation = { -12.0, 1.5, 0.0 };

	lineLocation.y = boxerLogoLocation.y + 1;

	PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint menuLocation = { -8.2, 8, 0.0 };
	printMenuItems(menuItems, 3, menuLocation);
}

void HelpSubWindow(void)
{
	char* headerItems[] = {
		{ " Help: " },
		{ " H  -> Help " },
		{ "Esc -> Back To Menu " }
	};

	char* menuItems[] = {
		{ " Help: " },
		{ " F1 -> View Mode " },
		{ " F2 -> Play Mode " },
		{ "	F4 -> Exit the program " }
	};

	GLfloatPoint sceLogoLocation = { -16.0, -21, 0.0 };
	GLfloatPoint sceLogoColor = { 1.0, 1.0, 1.0 };
	GLfloatPoint sceScaleLogo = { 0.02, 0.03, 0.0 };
	GLfloatPoint movieLogoColor = { 0, 0.5, 0.8 };
	//PrintStrokeText(" SCE", sceLogoLocation, sceLogoColor, sceScaleLogo, 20, 2, false);


	GLfloatPoint movieLogoLocation = sceLogoLocation;
	movieLogoLocation.x += 8;
	movieLogoLocation.y -= 0.5;

	GLfloatPoint movieScaleLogo = { 0.01, 0.02, 0.0 };
	//PrintStrokeText(" Movies Production", movieLogoLocation, movieLogoColor, movieScaleLogo, 8, 1.2, false);

	GLfloatPoint lineLocation = { -24.0, -20.5, 0.0 };
	char* line = "________________________________";
	//PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint creditHeaderItems = { -16, -16, 0.0 };
	printMenuItems(headerItems, 2, creditHeaderItems);

	GLfloatPoint boxerLogoLocation = { -12.0, 1.5, 0.0 };
	GLfloatPoint boxerScaleLogo = { 0.04, 0.06, 0 };
	int boxerStrokeSize = 24;
	GLfloat boxerDelta = 4;
	//PrintStrokeText("BOXING", boxerLogoLocation, movieLogoColor, boxerScaleLogo, boxerStrokeSize, boxerDelta, true);

	lineLocation.y = boxerLogoLocation.y + 1;

	//PrintStrokeText(line, lineLocation, movieLogoColor, { 0.02, 0.02, 0.0 }, 14, 1.45, false);

	GLfloatPoint menuLocation = { -8.2, 8, 0.0 };
	printMenuItems(menuItems, 3, menuLocation);
}
