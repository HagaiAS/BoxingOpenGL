#pragma once
#include "Entrance.h"
#include "Arena.h"
#include "Tribune.h"
#include "World.h"
#include "Boxers.h"
#include "Crowd.h"
#include "Textures.h"

Crowd crowd;
Boxers boxer1(BoxerAng1);
Boxers boxer2(BoxerAng2);

// Animation variables
GLfloat boxersDistance = ARENA_SIZE_B / 2;
GLfloat boxersAngleY = 45.;
GLfloat boxersAngleZ = 0.;
GLfloat boxersAngleDeltaZ = 7.5;

GLfloat BOXER_RED_X = 0.;
GLfloat BOXER_RED_Y = FLOOR_Y_B;
GLfloat BOXER_RED_Z = -boxersDistance;

GLfloat BOXER_BLUE_X = 0.;
GLfloat BOXER_BLUE_Y = FLOOR_Y_B;
GLfloat BOXER_BLUE_Z = boxersDistance;

GLfloat BOXER_RED_MOVING_SPEED = 3.0;
GLfloat BOXER_BLUE_MOVING_SPEED = -3.0;

int BOXER_RED_DIRECTION = 1;
int BOXER_BLUE_DIRECTION = -1;

GLfloat BOXERS_ANGLE_SPEED = 0.6;
GLfloat CLAPPING_SPEED = 10.0;
GLfloat HANDS_UP_SPEED = 5.0;

bool knockoutPart = false;
bool walkingPart = true;
bool fightingPart = false;
bool isAutoCameraOn = true; // whether to change camera views during the scene
float currTime = 0.0;

GLfloat crowdAnglesClapping[17] =
{
	0.0, 0.0, 0.0, // torso, neckX, neckY
	10.0, -30.0, // left upper/lower armX
	10.0, -30.0, // right upper/lower armX
	90.0, 90.0, // left upper/lower legX
	90.0, 90.0, // right upper/lower legX
	-55.0, 55.0, // left upper / right upper armZ
	0.0, 0.0, // left upper / right upper legZ
	20.0, 20.0 // left / right footX
};

GLfloat crowdAnglesUpArms[17] =
{
	0.0, 0.0, 0.0, // torso, neckX, neckY
	40.0, 0.0, // left upper/lower armX
	40.0, 0.0, // right upper/lower armX
	90.0, 90.0, // left upper/lower legX
	90.0, 90.0, // right upper/lower legX
	0.0, 0.0, // left upper / right upper armZ
	0.0, 0.0, // left upper / right upper legZ
	20.0, 20.0 // left / right footX
};

// For the menu
bool lightsOn = true;
bool boxersAnimationOn = true;
bool crowdAnimationOn = true;
bool topViewOn = false;
bool slowMotionOn = false;
int timerSeconds = TIMERMSECS;

// This method show the scene by 3 parts, the last part of the scene is limitless
void showScene()
{
	GLfloat redBoxerZ = BOXER_RED_Z + BOXER_RED_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
	GLfloat redBoxerX = BOXER_RED_X + BOXER_RED_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
	GLfloat blueBoxerZ = BOXER_BLUE_Z + BOXER_BLUE_MOVING_SPEED + (BOXER_BLUE_DIRECTION * TORSO_RADIUS);
	GLfloat blueBoxerX = BOXER_BLUE_X + BOXER_BLUE_MOVING_SPEED + (BOXER_BLUE_DIRECTION * TORSO_RADIUS);

	// If its the first part of the scene - THE MATCH STARTS
	if (currTime <= TIME_PART * 1 / 3)
	{
		// If change camera automatically
		if (isAutoCameraOn) {

		}

		// If the boxers distance is above the minimal distance 
		if ((abs(redBoxerZ - blueBoxerZ) >= BOXERS_MIN_DISTANCE) &&
			(abs(redBoxerX - blueBoxerX) >= BOXERS_MIN_DISTANCE))
		{
			// If the red boxer is inside the arena - move it
			if (((ARENA_SIZE / 2) >= abs(redBoxerZ)) &&
				((ARENA_SIZE / 2) >= abs(redBoxerX)))
			{
				BOXER_RED_Z += BOXER_RED_MOVING_SPEED;
			}
			else
			{
				// Change red boxer moving direction
				BOXER_RED_DIRECTION *= -1;
				BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;
			}

			// If the blue boxer is inside the arena - move it
			if (((ARENA_SIZE / 2) >= abs(blueBoxerZ)) &&
				((ARENA_SIZE / 2) >= abs(blueBoxerX)))
			{
				BOXER_BLUE_Z += BOXER_BLUE_MOVING_SPEED;
			}
			else
			{
				// Change blue boxer moving direction
				BOXER_BLUE_DIRECTION *= -1;
				BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
			}
		}
		else
		{
			// Turn the boxers a little bit
			boxersAngleY += BOXERS_ANGLE_SPEED;
			if ((boxersAngleY > 60.) || (boxersAngleY < 45.)) {
				BOXERS_ANGLE_SPEED *= -1;
			}
		}
	}
	else if (currTime <= TIME_PART * 2)
	{
		// This is the second part of the scene - THE FIGHT
		if (!fightingPart) {
			BOXER_RED_DIRECTION *= -1;
			BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;
			BOXER_BLUE_DIRECTION *= -1;
			BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
		}

		walkingPart = false;
		fightingPart = true;
		redBoxerZ = BOXER_RED_Z + BOXER_BLUE_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);
		redBoxerX = BOXER_RED_X + BOXER_BLUE_MOVING_SPEED + (BOXER_RED_DIRECTION * TORSO_RADIUS);

		// Move the boxers in the arena together

		// If the red and blue boxer are inside the arena - move them together
		if (((ARENA_SIZE / 2.4) >= abs(redBoxerZ)) &&
			((ARENA_SIZE / 2.4) >= abs(redBoxerX)) &&
			((ARENA_SIZE / 2.4) >= abs(blueBoxerZ)) &&
			((ARENA_SIZE / 2.4) >= abs(blueBoxerX)))
		{
			BOXER_RED_Z += BOXER_BLUE_MOVING_SPEED;
			BOXER_BLUE_Z += BOXER_BLUE_MOVING_SPEED;

			// Turn the boxers a little bit

			if ((boxersAngleY >= 100.) || (boxersAngleY <= -60.)) {
				BOXERS_ANGLE_SPEED *= -1;
			}
			boxersAngleY += BOXERS_ANGLE_SPEED;
		}
		else
		{
			// Change red boxer moving direction
			BOXER_RED_DIRECTION *= -1;
			BOXER_RED_MOVING_SPEED *= BOXER_RED_DIRECTION;

			// Change blue boxer moving direction
			BOXER_BLUE_DIRECTION *= -1;
			BOXER_BLUE_MOVING_SPEED *= BOXER_BLUE_DIRECTION;
		}
	}
	else
	{
		// This is the third part of the scene - THE KNOCKOUT
		fightingPart = false;

		// Throw knockout punch
		//boxer1.animate_boxer_fight();

		// If rocky is inside the arena
		if (abs(BOXER_RED_Z) < ARENA_SIZE / 3)
		{
			knockoutPart = true;

			// Move away from falling clubber
			BOXER_RED_Z -= BOXER_BLUE_MOVING_SPEED;
		}

		// Knockdown clubber boxer
		if (boxersAngleZ > -90.)
		{
			boxersAngleZ -= boxersAngleDeltaZ;
		}
		else
		{
			BoxerAng1[3] = -30;
			BoxerAng1[4] = -30;
			BoxerAng1[5] = -30;
			BoxerAng1[6] = -30;
			boxer1.animate_boxer_winning();
		}
	}

	// If the scene is not over
	if (currTime < SCENE_TOTAL_SEC)
	{
		// Increment time and continue with scene
		currTime += TIME_DELTA;
	}
}

// This method clap the crowd hands
void clapHands()
{
	// Move clapping hands
	if ((crowdAnglesClapping[4] < -30) || (crowdAnglesClapping[4] > 0)) {
		CLAPPING_SPEED *= -1;
	}

	crowdAnglesClapping[4] += CLAPPING_SPEED;
	crowdAnglesClapping[6] += CLAPPING_SPEED;
}

// This method move the crowd hands up and down
void moveHandsUp()
{
	// Move hands up and down
	if ((crowdAnglesUpArms[3] > 40) || (crowdAnglesUpArms[3] < -100)) {
		HANDS_UP_SPEED *= -1;
	}

	crowdAnglesUpArms[3] += HANDS_UP_SPEED;
	crowdAnglesUpArms[5] += HANDS_UP_SPEED;
}

//------------------------------------------------
//                ANIMATION FUNCTIONS
//------------------------------------------------


// This method change the angles for each draw
void my_idle(void)
{
	// If need to animate the boxers
	if (boxersAnimationOn)
	{
		// If need to walk
		if (!knockoutPart) {

			// Move the boxer legs infinity
			boxer1.animate_boxer_walk();
			boxer2.animate_boxer_walk();
		}

		if (fightingPart) {
			boxer1.animate_boxer_fight();
			boxer2.animate_boxer_fight();
		}
	}

	// If need to animate the crowd
	if (crowdAnimationOn)
	{
		// Move clapping hands
		clapHands();

		// Move hands up and down
		moveHandsUp();
	}

	// Call redisplay again
	glutPostRedisplay();
}

// This method handles the animations of the objects and the delay of movement
void make_delay(int)
{
	my_idle();

	showScene();

	glutTimerFunc(timerSeconds, make_delay, 1);
}


