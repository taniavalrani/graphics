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
		radius = 0.5f;
		pi = 3.141592;
	};
	~Sphere() {};

	OBJ_TYPE getType() {
		return SHAPE_SPHERE;
	}

	void draw() {
		drawHat();
		// drawCone();
		// drawBody();

	};

	void drawNormal() {
	};

private:
	float top_point [3];
	float bottom_point [3];
	float radius;
	float pi;

	void drawHat() {
		// glBegin(GL_TRIANGLES);
		// std::vector <float> hat;
		// float width = (float) 1 / (float) m_segmentsY;
		// int half_segments = floor(m_segmentsY / 2);
		// std::vector <float> circle_radii;
		// float curr_radii = width;
		// int curr_circle = 1;
		// float width = radius / half_segments;
		// for (int i = 0; i < m_segmentsY; i++) {
		// 	circle_radii.push_back(curr_radii);
		// 	curr_circle++;
		// 	if (curr_circle = )


		// }


		// for (int i = 0; i < m_segmentsX; i++) {
		// 	float x = curr_radius * cos((2.0f * pi * i) / m_segmentsX);
		// 	float y = 0.5f - width;
		// 	float z = curr_radius * sin((2.0f * pi * i) / m_segmentsX);
			
		// 	hat.push_back(x);
		// 	hat.push_back(y);
		// 	hat.push_back(z);

		// }

		// unsigned size = hat.size();

		// for (int i = 0; i < size; i+=3){
		// 	if(i == (size - 3)) { /* edge case for last */
		// 		glVertex3f(top_point[0], top_point[1], top_point[2]);
		// 		glVertex3f(hat[0], hat[1], hat[2]);
		// 		glVertex3f(hat[size - 3], hat[size - 2], hat[size-1]);

		// 	}
		// 	else{
		// 		glVertex3f(top_point[0], top_point[1], top_point[2]);
		// 		glVertex3f(hat[i], hat[i + 1], hat[i + 2]);
		// 		glVertex3f(hat[i + 3], hat[i + 4], hat[i + 5]);

		// 	}
		// }
		// glEnd();
				
	}

	void drawCone() {
		// glBegin(GL_TRIANGLES);
		// std::vector <float> cone;

		// float width = (float) 1 / (float) m_segmentsY;

		// float curr_radius = 0.5f / (float) m_segmentsY;

		// for (int i = 0; i < m_segmentsX; i++) {
		// 	float x = curr_radius * cos((2.0f * pi * i) / m_segmentsX);
		// 	float y = -0.5f + width;
		// 	float z = curr_radius * sin((2.0f * pi * i) / m_segmentsX);
			
		// 	cone.push_back(x);
		// 	cone.push_back(y);
		// 	cone.push_back(z);

		// }

		// unsigned size = cone.size();

		// for (int i = 0; i < size; i+=3){
		// 	if(i == (size - 3)) { /* edge case for last */
		// 		glVertex3f(bottom_point[0], bottom_point[1], bottom_point[2]);
		// 		glVertex3f(cone[0], cone[1], cone[2]);
		// 		glVertex3f(cone[size - 3], cone[size - 2], cone[size-1]);

		// 	}
		// 	else{
		// 		glVertex3f(bottom_point[0], bottom_point[1], bottom_point[2]);
		// 		glVertex3f(cone[i], cone[i + 1], cone[i + 2]);
		// 		glVertex3f(cone[i + 3], cone[i + 4], cone[i + 5]);

		// 	}
		// }
		// glEnd();
	}

	void drawBody() {
	// 	float width = (float) 1 / (float) m_segmentsY;

	// 	glBegin(GL_TRIANGLES);
	// 	for (int i = 0; i < m_segmentsX; i++) {
	// 		for(int j = 1; j < m_segmentsY - 1; i++){


	// 		}
	// 	}

	// 	float seg_height = (float)1 / (float)m_segmentsY;
	// 	float curr_seg_height = -0.5f;
	// 	float radius = 0.5f;
	// 	float curr_radius = 0.5f;
	// 	int curr_circle = m_segmentsY;

	// 	for (int i = 0; i < m_segmentsX; i++) {
	// 		for (int j = 0; j < m_segmentsY - 1; j++) {
	// 			float curr_seg_x = curr_radius * cos((2 * pi * i) / m_segmentsX);
	// 			float curr_seg_z = curr_radius * sin((2 * pi * i) / m_segmentsX);
	// 			float next_seg_x = curr_radius * cos((2 * pi * (i + 1.0)) / m_segmentsX);
	// 			float next_seg_z = curr_radius * sin((2 * pi * (i + 1.0)) / m_segmentsX);
				
	// 			curr_circle--;
	// 			curr_radius = (curr_circle / (float) m_segmentsY) * radius;

	// 			float curr_seg_x_above = curr_radius * cos((2 * pi * i) / m_segmentsX);
	// 			float curr_seg_z_above = curr_radius * sin((2 * pi * i) / m_segmentsX);
	// 			float next_seg_x_above = curr_radius * cos((2 * pi * (i + 1.0)) / m_segmentsX);
	// 			float next_seg_z_above = curr_radius * sin((2 * pi * (i + 1.0)) / m_segmentsX);

	// 			float seg_y_above = curr_seg_height + seg_height;

	// 			glVertex3f(curr_seg_x, curr_seg_height, curr_seg_z);
	// 			glVertex3f(next_seg_x, curr_seg_height, next_seg_z);
	// 			glVertex3f(curr_seg_x_above, seg_y_above, curr_seg_z_above);

	// 			glVertex3f(curr_seg_x_above, seg_y_above, curr_seg_z_above);
	// 			glVertex3f(next_seg_x, curr_seg_height, next_seg_z);
	// 			glVertex3f(next_seg_x_above, seg_y_above, next_seg_z_above);


	// 			curr_seg_height = seg_y_above;
	// 			seg_y_above += seg_height;

	// 		}
	// 		curr_radius = radius;
	// 		curr_circle = m_segmentsY;
	// 		curr_seg_height = -0.5f;			
	// 	}
	// 	glEnd();

	}

};


#endif