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
	void setNormal(float x1, float y1, float z1,
					float x2, float y2, float z2,
					float x3, float y3, float z3);
};

#endif