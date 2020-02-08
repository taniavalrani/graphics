#ifndef SPECIAL_H
#define SPECIAL_H

#include "Shape.h"
#include <vector>

class Special : public Shape {
public:
	Special() {
        tip_x = 0.0f;
		tip_y = -0.5f;
		tip_z = 0.0f;
		radius = 0.25f;
		pi = 3.141592;
	};
	~Special() {};

	OBJ_TYPE getType() {
		return SHAPE_SPECIAL1 ;
	}

		void draw() {
		drawBase();
		drawCone();

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
		float y = 0.0f;
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

	void drawCone(){
		glBegin(GL_TRIANGLES);
		std::vector <float> hat;

		float side = 0.25f;

		for (int i = 0; i < m_segmentsX; i++) {
			float x = side * cos((2.0f * pi * i) / m_segmentsX);
			float y = 0.0f;
			float z = side * sin((2.0f * pi * i) / m_segmentsX);
			
			hat.push_back(x);
			hat.push_back(y);
			hat.push_back(z);

		}

		unsigned size = hat.size();

		for (int i = 0; i < size; i+=3){
			if(i == (size - 3)) { /* edge case for last */
				glVertex3f(tip_x, tip_y, tip_z);
				glVertex3f(hat[0], hat[1], hat[2]);
				glVertex3f(hat[size - 3], hat[size - 2], hat[size-1]);

			}
			else{
				glVertex3f(tip_x, tip_y, tip_z);
				glVertex3f(hat[i], hat[i + 1], hat[i + 2]);
				glVertex3f(hat[i + 3], hat[i + 4], hat[i + 5]);

			}
		}
		glEnd();
	}





};





#endif