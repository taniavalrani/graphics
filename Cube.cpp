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

            curr_x += width_x;
        } 
        curr_x = start_x;
        for (int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x + width_x, curr_y + height_y, curr_z);
            glVertex3f(curr_x, curr_y + height_y, curr_z);
            glVertex3f(curr_x, curr_y, curr_z);
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

            curr_x += width_x;
        } 
        curr_x = start_x;
        for (int j = 0; j < Shape::m_segmentsX; j++) {
            glVertex3f(curr_x + width_x, curr_y , curr_z + height_y);
            glVertex3f(curr_x, curr_y , curr_z + height_y);
            glVertex3f(curr_x, curr_y, curr_z);
            curr_x += width_x;
        }
        curr_x = start_x;
        curr_z += height_y; 
    
    }

    glEnd();
}

void Cube::drawNormal() {
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    // /* front face */
    // // glNormal3f(0.0f, 0.0f, 0.0f);
    // // glVertex3f(1.0f, 0.0f, 0.0f);
    // // glVertex3f(0.0f, 0.0f, 0.0f);
    // // glVertex3f(0.0f, 1.0f, 0.0f);
    // // glVertex3f(0.0f, 0.0f, 0.0f);
    // // glVertex3f(0.0f, 0.0f, 1.0f);
    // glVertex3f(0.0f, 0.0f, 0.0f);
    // glVertex3f(0.0f, 0.0f, -1.0f);
    // glVertex3f(0.0f, 0.0f, 0.0f);
    // glVertex3f(1.0f, 0.0f, 1.0f);

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