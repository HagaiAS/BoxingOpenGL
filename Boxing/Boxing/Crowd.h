#include "Boxers.h"

class Crowd : public Body
{
	public:
		GLfloat *crowdColors;
		Crowd();
		~Crowd(){};
		void draw_crowds(GLfloat*);
		void fillRandomColor();
};