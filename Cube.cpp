#include "Cube.h"
#include <iostream>
using namespace std;


Cube::Cube(){
}


Cube::~Cube(){
    return;

}

OBJ_TYPE Cube::getType() {
	return SHAPE_CUBE;

}

void Cube::draw() {

    // float corners [] = /* bottom left corners */
    // {
    //     /* front face */
    //     -0.5, -0.5, 0.5,
    //     /* back face */
    //     -0.5, -0.5, -0.5,
    //     /* left face */
    //     -0.5, -0.5, 0.5,
    //     /* right face */
    //     0.5, -0.5, 0.5,
    //     /* top face */
    //     0.5, 0.5, 0.5,
    //     /* bottom face */
    //     0.5, -0.5, 0.5,
    // };
    
    drawFrontBackFace(-0.5f, -0.5f, 0.5f);
    drawFrontBackFace(-0.5f, -0.5f, -0.5f);

    drawLeftRightFace(-0.5, -0.5,-0.5);
    drawLeftRightFace(0.5, -0.5,-0.5);

    drawTopBottomFace(-0.5, -0.5, -0.5);
    drawTopBottomFace(-0.5, 0.5, -0.5);

	drawNormal_topBot(-0.5, 0.5, -0.5);
    return;
};

void Cube::drawFrontBackFace(float start_x, float start_y, float start_z){
    glBegin(GL_TRIANGLES);
    float width_x = (float) 1 / (float) Shape::m_segmentsX;
    float height_y = (float) 1 / (float) Shape::m_segmentsY;

    float curr_x = start_x;
    float curr_y = start_y;
    float curr_z = start_z;

        for (int i = 0; i < Shape::m_segmentsY; i++){   
            for(int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x, curr_y, curr_z);
            glVertex3f(curr_x + width_x, curr_y, curr_z);
            glVertex3f(curr_x + width_x, curr_y + height_y, curr_z);

			setNormal(
				curr_x, curr_y, curr_z,
				curr_x + width_x, curr_y, curr_z,
				curr_x + width_x, curr_y + height_y, curr_z
			);

            curr_x += width_x;
        } 
        curr_x = start_x;
        for (int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x + width_x, curr_y + height_y, curr_z);
            glVertex3f(curr_x, curr_y + height_y, curr_z);
            glVertex3f(curr_x, curr_y, curr_z);

			setNormal(
				curr_x + width_x, curr_y + height_y, curr_z,
				curr_x, curr_y + height_y, curr_z,
				curr_x, curr_y, curr_z
			);

			curr_x += width_x;

        }
        curr_x = start_x;
        curr_y += height_y; 
    
    }

    glEnd();
}


void Cube::drawLeftRightFace(float start_x, float start_y, float start_z){
    glBegin(GL_TRIANGLES);
    float width_x = (float) 1 / (float) Shape::m_segmentsX;
    float height_y = (float) 1 / (float) Shape::m_segmentsY;

    float curr_x = start_x;
    float curr_y = start_y;
    float curr_z = start_z;

        for (int i = 0; i < Shape::m_segmentsY; i++){   
        /* for each X segment*/
        for(int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x, curr_y, curr_z);
            glVertex3f(curr_x, curr_y, curr_z + width_x);
            glVertex3f(curr_x , curr_y + height_y, curr_z+ width_x);

            curr_z += width_x;
        } 
        curr_z = start_z;
        for (int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x , curr_y + height_y, curr_z + width_x);
            glVertex3f(curr_x, curr_y + height_y, curr_z);
            glVertex3f(curr_x, curr_y, curr_z);

            curr_z += width_x;
        }
        curr_z = start_z;
        curr_y += height_y; 
    
    }

    glEnd();
}

void Cube::drawTopBottomFace(float start_x, float start_y, float start_z){
    glBegin(GL_TRIANGLES);
    float width_x = (float) 1 / (float) Shape::m_segmentsX;
    float height_y = (float) 1 / (float) Shape::m_segmentsY;

    float curr_x = start_x;
    float curr_y = start_y;
    float curr_z = start_z;

        for (int i = 0; i < Shape::m_segmentsY; i++){   
        /* for each X segment*/
        for(int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x, curr_y, curr_z);
            glVertex3f(curr_x + width_x, curr_y, curr_z);
            glVertex3f(curr_x + width_x, curr_y , curr_z + height_y);

			////draw normal for top face
			//glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			//float l1 = 0.5;
			//float l2 = 0.6;
			//glVertex3f(curr_x + width_x, l1, curr_z);
			//glVertex3f(curr_x + width_x, l2, curr_z + height_y);
			//glEnd();
			//glColor3f(1.0, 1.0, 1.0);
			////end draw normal

            curr_x += width_x;
        } 
		glBegin(GL_TRIANGLES);

        curr_x = start_x;
        for (int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x + width_x, curr_y , curr_z + height_y);
            glVertex3f(curr_x, curr_y , curr_z + height_y);
            glVertex3f(curr_x, curr_y, curr_z);

			////draw normal for bot face
			//glBegin(GL_LINES);
			//glColor3f(1.0, 0.0, 0.0);
			//float l1 = 0.5;
			//float l2 = 0.6;
			//glVertex3f(curr_x + width_x, l1, curr_z);
			//glVertex3f(curr_x + width_x, l2, curr_z + height_y);
			//glEnd();
			//glColor3f(1.0, 1.0, 1.0);
			////end draw normal

            curr_x += width_x;
        }
        curr_x = start_x;
        curr_z += height_y; 
    
    }

    glEnd();
}

void Cube::drawNormal_topBot(float start_x, float start_y, float start_z) {
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    
	float width_x = (float)1 / (float)Shape::m_segmentsX;
	float height_y = (float)1 / (float)Shape::m_segmentsY;

	float curr_x = start_x;
	float curr_y = start_y;
	float curr_z = start_z;

	float l1 = 0.5f; //length of vector is 0.1
	float l2 = 0.6f;

		for (int i = 0; i < Shape::m_segmentsY; i++) {
			/* for each X segment*/
			for (int j = 0; j < Shape::m_segmentsX; j++) {

				/*glVertex3f(curr_x + width_x, curr_y, curr_z);
				glVertex3f(curr_x + width_x, curr_y, curr_z + height_y);
				*/

				float x1 = 0.5 * cos(2 * PI * j / m_segmentsX);
				float z1 = 0.5 * sin(2 * PI * j / m_segmentsX);
				float x2 = 0.5 * cos(2 * PI * j / m_segmentsX);
				float z2 = 0.5 * sin(2 * PI * j / m_segmentsX);

				//top
				glBegin(GL_LINES);
				glVertex3f(x1, l1, z1);
				glVertex3f(x2, l2, z2);
				glEnd();


				curr_x += width_x;
			}
		}
	/*glVertex3f(-1, 0.5, 0);
	glVertex3f(-1, 0.6, 0);*/


	
	/*front face */
    //glNormal3f(0.0f, 0.0f, 0.0f);
  /*  glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
*/
    glEnd();
	return;
};


/* copy and pasted from lab1*/
void Cube::setNormal(float x1, float y1, float z1,
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