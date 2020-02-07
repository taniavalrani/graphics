#ifndef CONE_H
#define CONE_H

#include "Shape.h"

class Cone : public Shape {
public:
	Cone() {
		tip_x = 0.0f;
		tip_y = 0.5f;
		tip_z = 0.0f;
		radius = 0.5f;
		pi = 3.141598;
	};
	~Cone() {};

	OBJ_TYPE getType() {
		return SHAPE_CONE;
	}

	void draw() {
		drawBase();
	};

	void drawNormal() {
	};

private:
	float tip_x;
	float tip_y;
	float tip_z;
	float radius;
	float pi;
	void drawBase(){
		/* y is 0.5f since we are drawing the base */
		float y = -0.5f;
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < m_segmentsX; i++) {
			float curr_seg_x = radius * cos((2 * pi * i) / m_segmentsX);
			float curr_seg_z = radius * sin((2 * pi * i) / m_segmentsX);
			float next_seg_x = radius * cos((2 * pi * (i + 1.0)) / m_segmentsX);
			float next_seg_z = radius * sin((2 * pi * (i + 1.0)) / m_segmentsX);

			/* center of base of base*/
			glVertex3f(0, y, 0);
			glVertex3f(curr_seg_x, y, curr_seg_z);
			glVertex3f(next_seg_x, y, next_seg_z);
			

			

		}

		glEnd();
	}
};

#endif