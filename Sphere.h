#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
public:
	Sphere() {
		top_point[0] = 0.0f;
		top_point[1] = 0.5f;
		top_point[2] = 0.0f;
		bottom_point[0] = 0.0f;
		bottom_point[1] = -0.5f;
		bottom_point[2] = 0.0f;
	};
	~Sphere() {};

	OBJ_TYPE getType() {
		return SHAPE_SPHERE;
	}

	void draw() {

	};

	void drawNormal() {
	};

private:
	float top_point [3];
	float bottom_point [3];
};

#endif