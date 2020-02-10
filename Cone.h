#ifndef CONE_H
#define CONE_H

#include "Shape.h"
#include <vector>

class Cone : public Shape {
public:
	Cone() {
		tip_x = 0.0f;
		tip_y = 0.5f;
		tip_z = 0.0f;
		radius = 0.5f;
		pi = 3.141592;
	};
	~Cone() {};

	OBJ_TYPE getType() {
		return SHAPE_CONE;
	}

	void draw() {
		drawBase();
		drawTop();
		drawBody();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);

		/* normal at top of cone */
		glVertex3f(0.0f, 0.5f, 0.0f);
		glVertex3f(0.0f, 0.6f, 0.0f);
		/* normal at bottom of cone */
		glVertex3f(0.0f, -0.5f, 0.0f);
		glVertex3f(0.0f, -0.6f, 0.0f);

		for (int i = 1; i <= m_segmentsY; i++) {
			for (int j = 0; j < m_segmentsX; j++) {
				float l1, l2;
				float y = 0.5f - ((float) i) / m_segmentsY;
				l1 = ((float) i)/2.0f/m_segmentsY;
				l2 = l1 + .1;
				float x1 = l1 * cos(2 * pi * j / m_segmentsX);
				float z1 = l1 * sin(2 * pi * j / m_segmentsX);

				float x2 = l2 * cos(2 * pi * j / m_segmentsX);
				float z2 = l2 * sin(2 * pi * j / m_segmentsX);
				glVertex3f(x1, y, z1);
				/* end of line */
				glVertex3f(x2, y + 0.05f, z2);
			}
		}

		glEnd();
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

	void drawTop(){
		glBegin(GL_TRIANGLES);
		
		std::vector <float> hat;

		float side = 0.5f / (float) m_segmentsY;

		for (int i = 0; i < m_segmentsX; i++) {
			float x = side * cos((2.0f * pi * i) / m_segmentsX);
			float y = 0.5f - 1.0f/m_segmentsY;
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

				setNormal(tip_x, tip_y, tip_z,
						 hat[0], hat[1], hat[2], 
						 hat[size - 3], hat[size - 2], hat[size-1]);

			}
			else{
				glVertex3f(tip_x, tip_y, tip_z);
				glVertex3f(hat[i], hat[i + 1], hat[i + 2]);
				glVertex3f(hat[i + 3], hat[i + 4], hat[i + 5]);
				
				setNormal(hat[i + 3], hat[i + 4], hat[i + 5],
						 hat[i], hat[i + 1], hat[i + 2], tip_x, tip_y, tip_z);

			}
		}
		glEnd();
	}
	void drawBody() {
		glBegin(GL_TRIANGLES);

		float seg_height = (float)1 / (float)m_segmentsY;
		float curr_seg_height = -0.5f;
		float radius = 0.5f;
		float curr_radius = 0.5f;
		int curr_circle = m_segmentsY;

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 0; j < m_segmentsY - 1; j++) {
				float curr_seg_x = curr_radius * cos((2 * pi * i) / m_segmentsX);
				float curr_seg_z = curr_radius * sin((2 * pi * i) / m_segmentsX);
				float next_seg_x = curr_radius * cos((2 * pi * (i + 1.0)) / m_segmentsX);
				float next_seg_z = curr_radius * sin((2 * pi * (i + 1.0)) / m_segmentsX);
				
				curr_circle--;
				curr_radius = (curr_circle / (float) m_segmentsY) * radius;

				float curr_seg_x_above = curr_radius * cos((2 * pi * i) / m_segmentsX);
				float curr_seg_z_above = curr_radius * sin((2 * pi * i) / m_segmentsX);
				float next_seg_x_above = curr_radius * cos((2 * pi * (i + 1.0)) / m_segmentsX);
				float next_seg_z_above = curr_radius * sin((2 * pi * (i + 1.0)) / m_segmentsX);

				float seg_y_above = curr_seg_height + seg_height;

				glVertex3f(curr_seg_x, curr_seg_height, curr_seg_z);
				glVertex3f(next_seg_x, curr_seg_height, next_seg_z);
				glVertex3f(curr_seg_x_above, seg_y_above, curr_seg_z_above);

				glVertex3f(curr_seg_x_above, seg_y_above, curr_seg_z_above);
				glVertex3f(next_seg_x, curr_seg_height, next_seg_z);
				glVertex3f(next_seg_x_above, seg_y_above, next_seg_z_above);

				setNormal(curr_seg_x, curr_seg_height, curr_seg_z,
						 curr_seg_x_above, seg_y_above, curr_seg_z_above,
						  next_seg_x_above, seg_y_above, next_seg_z_above);
				setNormal(next_seg_x_above, seg_y_above, next_seg_z_above, 
						  next_seg_x, curr_seg_height, next_seg_z,
						   curr_seg_x, curr_seg_height, curr_seg_z);
				curr_seg_height = seg_y_above;
				seg_y_above += seg_height;

			}
			curr_radius = radius;
			curr_circle = m_segmentsY;
			curr_seg_height = -0.5f;			
		}
		glEnd();

	}
	/* copy and pasted from lab1*/
	void setNormal(float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3) {

		float v1x, v1y, v1z;
		float v2x, v2y, v2z;
		float cx, cy, cz;

		//find vector between x2 and x1
		v1x = x1 - x2;
		v1y = y1 - y2;
		v1z = z1 - z2;

		//find vector between x3 and x2
		v2x = x2 - x3;
		v2y = y2 - y3;
		v2z = z2 - z3;

		//cross product v1xv2

		cx = v1y * v2z - v1z * v2y;
		cy = v1z * v2x - v1x * v2z;
		cz = v1x * v2y - v1y * v2x;

		//normalize

		float length = sqrt(cx * cx + cy * cy + cz * cz);
		cx = cx / length;
		cy = cy / length;
		cz = cz / length;

		glNormal3f(cx, cy, cz);
	}

};

#endif