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
				float x1 = l1 * cos(2 * PI * j / m_segmentsX);
				float z1 = l1 * sin(2 * PI * j / m_segmentsX);

				float x2 = l2 * cos(2 * PI * j / m_segmentsX);
				float z2 = l2 * sin(2 * PI * j / m_segmentsX);
				glVertex3f(x1, y, z1);
				/* end of line */
				glVertex3f(x2, y + 0.05f, z2);
			}
		}

		glEnd();
	};

private:
	float tip_x = 0.0f;
	float tip_y = 0.5f;
	float tip_z = 0.0f;
	float radius = 0.5f;

	void drawBase() {
		std::vector <float> bottom_face_vertices;
		glBegin(GL_TRIANGLES);

		/* adding bottom most origin*/
		float radius = 0.5f;
		bottom_face_vertices.push_back(0.0f);
		bottom_face_vertices.push_back(-0.5f);
		bottom_face_vertices.push_back(0.0f);
		float slice_angle = (2 * PI) / m_segmentsX;
		float curr_angle = slice_angle;
		int index = 0;

		for (int i = 0; i < m_segmentsX; i++) {
			bottom_face_vertices.push_back(radius * cos(curr_angle));
			bottom_face_vertices.push_back(-0.5f);
			bottom_face_vertices.push_back(radius * sin(curr_angle));

			if (i > 0) {

				setNormal(radius * cos(curr_angle), -0.5f, radius * sin(curr_angle),
					0.0f, -0.5f, 0.0f,
					bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);

				glVertex3f(radius * cos(curr_angle), -0.5f, radius * sin(curr_angle));
				normalizeNormal(radius * cos(curr_angle), -0.5f, radius * sin(curr_angle));

				glVertex3f(0.0f, -0.5f, 0.0f);
				normalizeNormal(0.0f, -0.5f, 0.0f);

				glVertex3f(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
				normalizeNormal(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
			}
			index += 3;
			curr_angle += slice_angle;
		}

		setNormal(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5],
			0.0f, -0.5f, 0.0f,
			bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);

		glVertex3f(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5]);
		normalizeNormal(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5]);
		glVertex3f(0.0f, -0.5f, 0.0f);
		normalizeNormal(0.0f, -0.5f, 0.0f);
		glVertex3f(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
		normalizeNormal(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);

		glEnd();

	}

	void drawTop(){
		glBegin(GL_TRIANGLES);
		
		std::vector <float> hat;

		float side = 0.5f / (float) m_segmentsY;

		for (int i = 0; i < m_segmentsX; i++) {
			float x = side * cos((2.0f * PI * i) / m_segmentsX);
			float y = 0.5f - 1.0f/m_segmentsY;
			float z = side * sin((2.0f * PI * i) / m_segmentsX);
			
			hat.push_back(x);
			hat.push_back(y);
			hat.push_back(z);

		}

		unsigned size = hat.size();

		for (int i = 0; i < size; i+=3){
			if(i == (size - 3)) { /* edge case for last */
				setNormal(tip_x, tip_y, tip_z,
				hat[size - 3], hat[size - 2], hat[size - 1],
				hat[0], hat[1], hat[2]
				);

				glVertex3f(tip_x, tip_y, tip_z);
				normalizeNormal(tip_x, tip_y, tip_z);

				glVertex3f(hat[size - 3], hat[size - 2], hat[size-1]);
				normalizeNormal(hat[size - 3], hat[size - 2], hat[size - 1]);

				glVertex3f(hat[0], hat[1], hat[2]);
				normalizeNormal(hat[0], hat[1], hat[2]);
			}
			else{
				glVertex3f(tip_x, tip_y, tip_z);
				normalizeNormal(tip_x, tip_y, tip_z); 
				glVertex3f(hat[i + 3], hat[i + 4], hat[i + 5]);
				normalizeNormal(hat[i + 3], hat[i + 4], hat[i + 5]);
				glVertex3f(hat[i], hat[i + 1], hat[i + 2]);
				normalizeNormal(hat[i], hat[i + 1], hat[i + 2]);
			}
		}
		glEnd();
	}
	void drawBody() {
		glBegin(GL_TRIANGLES);

		float seg_height = (float)1 / (float)m_segmentsY;
		float curr_seg_height = -0.5f;
		float radius = 0.5f;
		float curr_radius = 0.0f;
		int curr_circle = m_segmentsY;

		for (int i = 0; i < m_segmentsX + 1; i++) {
			for (int j = 0; j < m_segmentsY - 1; j++) {
				float curr_seg_x = curr_radius * cos((2 * PI * i) / m_segmentsX);
				float curr_seg_z = curr_radius * sin((2 * PI * i) / m_segmentsX);
				float next_seg_x = curr_radius * cos((2 * PI * (i + 1.0)) / m_segmentsX);
				float next_seg_z = curr_radius * sin((2 * PI * (i + 1.0)) / m_segmentsX); 

				curr_circle--;
				curr_radius = (curr_circle / (float)m_segmentsY) * radius;

				float curr_seg_x_above = curr_radius * cos((2 * PI * i) / m_segmentsX);
				float curr_seg_z_above = curr_radius * sin((2 * PI * i) / m_segmentsX);
				float next_seg_x_above = curr_radius * cos((2 * PI * (i + 1.0)) / m_segmentsX);
				float next_seg_z_above = curr_radius * sin((2 * PI * (i + 1.0)) / m_segmentsX);
				float seg_y_above = curr_seg_height + seg_height;

				/*setNormal(curr_seg_x, curr_seg_height, curr_seg_z,
					next_seg_x_above, seg_y_above, next_seg_z_above,
					next_seg_x, curr_seg_height, next_seg_z
					);

				setNormal(curr_seg_x, curr_seg_height, curr_seg_z,
					curr_seg_x_above, seg_y_above, curr_seg_z_above,
					next_seg_x_above, seg_y_above, next_seg_z_above
				);
				*/
				glVertex3f(curr_seg_x, curr_seg_height, curr_seg_z); // bottom right
				normalizeNormal(curr_seg_x, curr_seg_height, curr_seg_z);
				glVertex3f(next_seg_x_above, seg_y_above, next_seg_z_above); //top left
				normalizeNormal(next_seg_x_above, seg_y_above, next_seg_z_above);
				glVertex3f(next_seg_x, curr_seg_height, next_seg_z); // bottom left
				normalizeNormal(next_seg_x, curr_seg_height, next_seg_z);

				glVertex3f(curr_seg_x, curr_seg_height, curr_seg_z); // bottom right
				normalizeNormal(curr_seg_x, curr_seg_height, curr_seg_z);
				glVertex3f(curr_seg_x_above, seg_y_above, curr_seg_z_above); //top right
				normalizeNormal(next_seg_x_above, seg_y_above, next_seg_z_above);
				glVertex3f(next_seg_x_above, seg_y_above, next_seg_z_above); //top left
				normalizeNormal(curr_seg_x_above, seg_y_above, curr_seg_z_above);

				curr_seg_height = seg_y_above;
				seg_y_above += seg_height;

			}
			curr_radius = radius;
			curr_circle = m_segmentsY;
			curr_seg_height = -0.5f;
		}
		glEnd();

	}
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