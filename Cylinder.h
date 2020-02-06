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
		drawSideFace();

	};

	

	void drawNormal() {
	};


private:

	std::vector <float> face_vertices;
	void drawTopFace(){
		glBegin(GL_TRIANGLES);
		std::vector <float> top_face_vertices;
		/* adding top most origin*/
		float pi = 3.141598f;
		float radius = 0.5f;
		top_face_vertices.push_back(0.0f);
		top_face_vertices.push_back(0.5f);
		top_face_vertices.push_back(0.0f);
		float slice_angle =  (2 * pi) / m_segmentsX;
		float curr_angle = slice_angle;
		int index = 0;
		for(int i = 0; i < m_segmentsX ; i++) {
			top_face_vertices.push_back(radius * cos(curr_angle));
			top_face_vertices.push_back(0.5f);
			top_face_vertices.push_back(radius * sin(curr_angle));
			
			if (i > 0) {
				
				glVertex3f(radius * cos(curr_angle), 0.5f, radius * sin(curr_angle));
				glVertex3f(0.0f, 0.5f, 0.0f);
				glVertex3f(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
				

			}
			index +=3;
			curr_angle += slice_angle;
			
		}

		glVertex3f(top_face_vertices[index], top_face_vertices[index + 1], top_face_vertices[index + 2]);
		glVertex3f(top_face_vertices[3], top_face_vertices[4], top_face_vertices[5]);
		glVertex3f(0.0f, 0.5f, 0.0f);
		face_vertices = top_face_vertices;
		
		
		glEnd();

	}
	void drawBottomFace(){
		std::vector <float> bottom_face_vertices;
		glBegin(GL_TRIANGLES);
		/* adding bottom most origin*/
		float pi = 3.141598f;
		float radius = 0.5f;
		bottom_face_vertices.push_back(0.0f);
		bottom_face_vertices.push_back(-0.5f);
		bottom_face_vertices.push_back(0.0f);
		float slice_angle =  (2 * pi) / m_segmentsX;
		float curr_angle = slice_angle;
		int index = 0;
		for(int i = 0; i < m_segmentsX ; i++) {
			bottom_face_vertices.push_back(radius * cos(curr_angle));
			bottom_face_vertices.push_back(-0.5f);
			bottom_face_vertices.push_back(radius * sin(curr_angle));
			
			if (i > 0) {
				
				glVertex3f(radius * cos(curr_angle), -0.5f, radius * sin(curr_angle));
				glVertex3f(0.0f, -0.5f, 0.0f);
				glVertex3f(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
				

			}
			index +=3;
			curr_angle += slice_angle;
			
		}

		glVertex3f(bottom_face_vertices[index], bottom_face_vertices[index + 1], bottom_face_vertices[index + 2]);
		glVertex3f(bottom_face_vertices[3], bottom_face_vertices[4], bottom_face_vertices[5]);
		glVertex3f(0.0f, -0.5f, 0.0f);

		glEnd();
		
	}

	void drawSideFace(){
		glBegin(GL_TRIANGLES);
		float width = 1 / m_segmentsY;
		float curr_y = -0.5f;

		for(int i = 0; i < m_segmentsX; i++) {
			curr_y = width;
			for(int j = 0; j < m_segmentsY; j++) {
				glVertex3f(face_vertices[i+3], curr_y + width, face_vertices[i+5]);
				glVertex3f(face_vertices[i+3], curr_y, face_vertices[i+5]);
				glVertex3f(face_vertices[i+3], curr_y, face_vertices[i+5]);
				glVertex3f(face_vertices[i+6], curr_y, face_vertices[i+5]);
				curr_y += width;
			}
			
		}

		glEnd();

	}

	


};

#endif