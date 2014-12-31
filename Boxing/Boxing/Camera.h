#include "Globals.h"

// Camera class.
class Camera
{
	public:
		Camera();
		void initCameraPosition();
		GLdouble getX();
		GLdouble getY();
		GLdouble getZ();
		GLdouble getCenterX();
		GLdouble getCenterY();
		GLdouble getCenterZ();
	
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void moveForward();
		void moveBackward();
	
		void lookUp();
		void lookDown();
		void lookLeft();
		void lookRight();

		void move(GLdouble, int);
		void look(GLdouble, int);
		void topView();
		void topViewDisable();

		void updateView();

	private:
		int isTopView;
		GLdouble x, y, z;
		GLdouble centerX, centerY, centerZ;
		GLdouble angle;
		GLdouble rotatingSpeed;
		GLdouble movingSpeed;
};