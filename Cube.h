#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"

class Cube : public Shape {
public:
	Cube();
	~Cube();

	OBJ_TYPE getType();


	void draw();

	

	void drawNormal();

private:
	void drawFrontBackFace(float start_x, float start_y, float start_z);
	void drawLeftRightFace(float start_x, float start_y, float start_z);
	void drawTopBottomFace(float start_x, float start_y, float start_z);
};

#endif