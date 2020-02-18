#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"
#include <vector>

class Cylinder : public Shape {
public:
	Cylinder() {

	};
	~Cylinder() {};

	OBJ_TYPE getType() {
		return SHAPE_CYLINDER;
	}

	void draw() {
		drawTopFace();
		drawBottomFace();
		drawSideFaces();
	};

	void drawNormal() {
		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		/* normal at top and bottom*/
		float l1 = 0.5f; //length of vector is 0.1
		float l2 = 0.6f;
		glVertex3f(0, l1, 0);
        glVertex3f(0, l2, 0);
        glVertex3f(0, -l1, 0);
        glVertex3f(0, -l2, 0);
		
        /*vertical normals for top/bottom face vertices */ 
		for (int i = 0; i <= m_segmentsY; i++) {
			for (int j = 0; j < m_segmentsX; j++) {
				float x1 = 0.5 * cos(2 * PI * j / m_segmentsX);
				float z1 = 0.5 *sin(2 * PI * j / m_segmentsX);
				float x2 = 0.5 *cos(2 * PI * j / m_segmentsX);
				float z2 = 0.5 *sin(2 * PI * j / m_segmentsX);
				
				//top
				glVertex3f(x1, l1, z1);
				glVertex3f(x2, l2, z2);
				
				//bottom
				glVertex3f(x1, -l1, z1);
				glVertex3f(x2, -l2, z2);
			}
		}

		//creates normals layer by layer
		for (int i = 0; i <= m_segmentsY; i++) {
			for (int j = 0; j < m_segmentsX; j++) {
				float y = 0.5f - ((float) i) / m_segmentsY;
				float x1 = l1 * cos(2 * PI * j / m_segmentsX);
				float z1 = l1 * sin(2 * PI * j / m_segmentsX);
				float x2 = l2 * cos(2 * PI * j / m_segmentsX);
				float z2 = l2 * sin(2 * PI * j / m_segmentsX);
				glVertex3f(x1, y, z1);
				glVertex3f(x2, y, z2);
			}
		}

		glEnd();
	};

private:

	std::vector <float> face_vertices;
	void drawTopFace() {
		std::vector <float> top_face_vertices;
		glBegin(GL_TRIANGLES);

		/* adding bottom most origin*/
		float radius = 0.5f;
		top_face_vertices.push_back(0.0f);
		top_face_vertices.push_back(0.5f);
		top_face_vertices.push_back(0.0f);
		float slice_angle = (2 * PI) / m_segmentsX;
		float curr_angle = slice_angle;
		int index = 0;
		for (int i = 0; i < m_segmentsX; i++) {
			top_face_vertices.push_back(radius * cos(curr_angle));
			top_face_vertices.push_back(0.5f);
			top_face_vertices.push_back(radius * sin(curr_angle));

			if (i > 0) {

				setNormal(radius * cos(curr_angle), 0.5f, radius * sin(curr_angle),
					0.0f, 0.5f, 0.0f,
					top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
				glVertex3f(0.0f, 0.5f, 0.0f);
				normalizeNormal(0.0f, 0.5f, 0.0f);
				
				glVertex3f(radius * cos(curr_angle), 0.5f, radius * sin(curr_angle));
				normalizeNormal(radius * cos(curr_angle), 0.5f, radius * sin(curr_angle));

				

				glVertex3f(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
				normalizeNormal(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
			}
			index += 3;
			curr_angle += slice_angle;
		}

		setNormal(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2],
			top_face_vertices[3], top_face_vertices[4], top_face_vertices[5],
			0.0f, 0.5f, 0.0f);

		glVertex3f(0.0f, 0.5f, 0.0f);
		normalizeNormal(0.0f, 0.5f, 0.0f);
		glVertex3f(top_face_vertices[3], top_face_vertices[4], top_face_vertices[5]);
		normalizeNormal(top_face_vertices[3], top_face_vertices[4], top_face_vertices[5]);
		
		glVertex3f(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
		normalizeNormal(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);

		glEnd();

	}

	void drawBottomFace(){
		std::vector <float> bottom_face_vertices;
		glBegin(GL_TRIANGLES);

		/* adding bottom most origin*/
		float radius = 0.5f;
		bottom_face_vertices.push_back(0.0f);
		bottom_face_vertices.push_back(-0.5f);
		bottom_face_vertices.push_back(0.0f);
		float slice_angle =  (2 * PI) / m_segmentsX;
		float curr_angle = slice_angle;
		int index = 0;
		for(int i = 0; i < m_segmentsX ; i++) {
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
			index +=3;
			curr_angle += slice_angle;
		}

		setNormal(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2],
				bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5],
				0.0f, -0.5f, 0.0f);

		
		glVertex3f(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5]);
		normalizeNormal(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5]);
		glVertex3f(0.0f, -0.5f, 0.0f);
		normalizeNormal(0.0f, -0.5f, 0.0f);
		glVertex3f(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
		normalizeNormal(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);

		glEnd();
		
	}

	void drawSideFaces(){
		glBegin(GL_TRIANGLES);

		std::vector <float> caps;
		float radius = 0.5f;
		float y = 0.5f;
		float x, z;

		//First vertex 
		caps.push_back(0.0f);
		caps.push_back(0.5f);
		caps.push_back(0.0f);

		//push to list one vertex at a time
		for (int i = 0; i <= m_segmentsX; i++) {
			x = radius * cos((2 * PI * i) / m_segmentsX);
			z = radius * sin((2 * PI * i )/ m_segmentsX);
			caps.push_back(x);
			caps.push_back(y);
			caps.push_back(z);
		}

		int index = 3;

		for (int i = 1; i <= m_segmentsX; i++) {
			float width = 1.0f/ (float) m_segmentsY;
			float top = width;
			float bottom = 0;
			
			for (int j = 0; j < m_segmentsY; j++){
				setNormal(caps[index + 3], caps[index + 4] - bottom, caps[index + 5],
					caps[index + 3], caps[index + 4] - top, caps[index + 5],
					caps[index], caps[index + 1] - top, caps[index + 2]);

				setNormal(caps[index], caps[index + 1] - bottom, caps[index + 2],
					caps[index + 3], caps[index + 4] - bottom, caps[index + 5],
					caps[index], caps[index + 1] - top, caps[index + 2]);

				/* two right angle triangles make a square */

				glVertex3f(caps[index + 3], caps[index + 4] - bottom, caps[index + 5]); //top left
				normalizeNormal(caps[index + 3], caps[index + 4] - bottom, caps[index + 5]);

				glVertex3f(caps[index + 3], caps[index + 4] - top, caps[index + 5]); // bottom left
				normalizeNormal(caps[index + 3], caps[index + 4] - top, caps[index + 5]);

				glVertex3f(caps[index], caps[index + 1] - top, caps[index + 2]); //bottom right 
				normalizeNormal(caps[index], caps[index + 1] - top, caps[index + 2]);
				
				//triangle 2

				glVertex3f(caps[index], caps[index+1]-bottom, caps[index +2]); //top right
				normalizeNormal(caps[index], caps[index + 1] - bottom, caps[index + 2]);
				
				glVertex3f(caps[index +3], caps[index +4]-bottom, caps[index +5]); //top left
				normalizeNormal(caps[index + 3], caps[index + 4] - bottom, caps[index + 5]);

				glVertex3f(caps[index], caps[index + 1] - top, caps[index + 2]); //bottom right
				normalizeNormal(caps[index], caps[index + 1] - top, caps[index + 2]);
	
				top += width;
				bottom += width;
			}
			index += 3;
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