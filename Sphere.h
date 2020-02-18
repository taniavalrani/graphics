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
		std::vector <float> ordered_radii;
		std::vector <float> radii;
		float num_of_unique_radii = floor(m_segmentsY / 2);
		int curr_circle = floor(m_segmentsY / 2);
		float width_segment = 0.5f / num_of_unique_radii;
		float curr_radius = 0.5f;
		radii.push_back(curr_radius);
		for(int i = 1; i < num_of_unique_radii; i++) {
			curr_circle--;
			curr_radius =(curr_circle / num_of_unique_radii) * radius;
			radii.push_back(curr_radius);
		}

		if (m_segmentsY % 2 == 1) {
			for(int i = radii.size() - 1; i >= 0; i--)
			{	
				ordered_radii.push_back(radii[i]);
			}
			for(unsigned i = 0; i < radii.size(); i++) {
				ordered_radii.push_back(radii[i]);

			}

		} else {
			for(int i = radii.size() - 1; i > 0; i--)
			{	
				ordered_radii.push_back(radii[i]);
			}
			for(unsigned i = 0; i < radii.size(); i++) {
				ordered_radii.push_back(radii[i]);

			}

		}

		drawHat(ordered_radii[0]);
		drawCone(ordered_radii[0]); /* same radius as hat*/
		drawBody(ordered_radii);

	};

	void drawNormal() {
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		/*normals at top and bottom*/
		float l1 = 0.5f;
		float l2 = 0.6f;

		for (int i = 0; i < m_segmentsY; i++) {
			for (int j = 0; j < m_segmentsX; j++) {
				float x1 = l1 * cos(2.0f * pi * j / m_segmentsX) * sin(pi * i / m_segmentsY);
				float x2 = l2 * cos(2.0f * pi * j / m_segmentsX) * sin(pi * i / m_segmentsY);	
				float y1 = l1 * cos(pi * i / m_segmentsY);		
				float y2 = l2 * cos(pi * i / m_segmentsY);	
				float z1 = l1 * sin(2.0f * pi * j / m_segmentsX) * sin(pi * i / m_segmentsY);
				float z2 = l2 * sin(2.0f * pi * j / m_segmentsX) * sin(pi * i / m_segmentsY);	

				glVertex3f(x1, y1, z1);
				glVertex3f(x2, y2, z2);	
			}
		}
		glEnd();

	};

private:
	float top_point [3];
	float bottom_point [3];
	float radius;
	float pi;
	

	void drawHat(float curr_radius) {
		glBegin(GL_TRIANGLES);
		std::vector <float> hat;
		float width = (float) 1 / (float) m_segmentsY;

		for (int i = 0; i < m_segmentsX; i++) {
			float x = curr_radius * cos((2.0f * pi * i) / m_segmentsX);
			float y = 0.5f - width;
			float z = curr_radius * sin((2.0f * pi * i) / m_segmentsX);
			
			hat.push_back(x);
			hat.push_back(y);
			hat.push_back(z);

		}

		unsigned size = hat.size();

		for (int i = 0; i < size; i+=3){
			if(i == (size - 3)) { /* edge case for last */
				glVertex3f(top_point[0], top_point[1], top_point[2]);
				glVertex3f(hat[0], hat[1], hat[2]);
				glVertex3f(hat[size - 3], hat[size - 2], hat[size-1]);

			}
			else{
				glVertex3f(top_point[0], top_point[1], top_point[2]);
				glVertex3f(hat[i], hat[i + 1], hat[i + 2]);
				glVertex3f(hat[i + 3], hat[i + 4], hat[i + 5]);

			}
		}
		glEnd();
				
	}

	void drawCone(float curr_radius) {
		glBegin(GL_TRIANGLES);
		std::vector <float> cone;

		float width = (float) 1 / (float) m_segmentsY;


		for (int i = 0; i < m_segmentsX; i++) {
			float x = curr_radius * cos((2.0f * pi * i) / m_segmentsX);
			float y = -0.5f + width;
			float z = curr_radius * sin((2.0f * pi * i) / m_segmentsX);
			
			cone.push_back(x);
			cone.push_back(y);
			cone.push_back(z);

		}

		unsigned size = cone.size();

		for (int i = 0; i < size; i+=3){
			if(i == (size - 3)) { /* edge case for last */
				glVertex3f(bottom_point[0], bottom_point[1], bottom_point[2]);
				glVertex3f(cone[0], cone[1], cone[2]);
				glVertex3f(cone[size - 3], cone[size - 2], cone[size-1]);

			}
			else{
				glVertex3f(bottom_point[0], bottom_point[1], bottom_point[2]);
				glVertex3f(cone[i], cone[i + 1], cone[i + 2]);
				glVertex3f(cone[i + 3], cone[i + 4], cone[i + 5]);

			}
		}
		glEnd();
	}

	void drawBody(std::vector <float> ordered_radii) {

		glBegin(GL_TRIANGLES);


		float seg_height = (float)1 / (float)m_segmentsY;
		float curr_seg_height = -0.5f + seg_height;
		int index = 0;
		float curr_radius = ordered_radii[index];
		// std::cout << ordered_radii.size() << ": size of curr radius!\n" << std::endl;
		

		for (int i = 0; i < m_segmentsX; i++) {
			for (int j = 1; j < m_segmentsY - 1; j++) {


				float curr_seg_x = curr_radius * cos((2 * pi * i) / m_segmentsX);
				float curr_seg_z = curr_radius * sin((2 * pi * i) / m_segmentsX);
				float next_seg_x = curr_radius * cos((2 * pi * (i + 1)) / m_segmentsX);
				float next_seg_z = curr_radius * sin((2 * pi * (i + 1)) / m_segmentsX);
				
				index ++;
				curr_radius = ordered_radii[index];

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

				curr_seg_height = seg_y_above;
				seg_y_above += seg_height;

			}
			index = 0;
			curr_radius = ordered_radii[index];
			curr_seg_height = -0.5f + seg_height;					
		}
		glEnd();

	}

};


#endif