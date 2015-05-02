// A Simple OpenGL Project
// Author: Michael Hall
//
// This C++ code and project are provided "as is" without warranty of any kind.
//
// Copyright 2010 XoaX - For personal use only, not for distribution
#include "stdafx.h"
#include <glut.h>

GLfloat gfPosX = 0.0;
GLfloat PosY1 = 0.93,PosY2=0.95,PosY3=0.82,PosY4=0.82;
GLfloat gfDeltaX = .0001;


void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	//pala
	glBegin(GL_POLYGON);
		glVertex3f(0.05,0.93,0.0);
		glVertex3f(0.18,0.93,0.0);
		glVertex3f(0.18,0.85,0.0);
		glVertex3f(0.05,0.85,0.0);
	glEnd();

	//leher
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.11,0.85,0.0);
		glVertex3f(0.18,0.85,0.0);
		glVertex3f(0.18,0.46,0.0);
		glVertex3f(0.11,0.46,0.0);
	glEnd();

	//badan
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.18,0.67,0.0);
		glVertex3f(0.73,0.67,0.0);
		glVertex3f(0.73,0.46,0.0);
		glVertex3f(0.18,0.46,0.0);
	glEnd();

	//kaki
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.43,0.46,0.0);
		glVertex3f(0.48,0.46,0.0);
		glVertex3f(0.53,0.36,0.0);
		glVertex3f(0.48,0.36,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0.23,0.46,0.0);
		glVertex3f(0.28,0.46,0.0);
		glVertex3f(0.33,0.36,0.0);
		glVertex3f(0.28,0.36,0.0);
	glEnd();

	//ekor
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex3f(0.73,0.57,0.0);
		glVertex3f(0.82,0.57,0.0);
		glVertex3f(0.82,0.6,0.0);
		glVertex3f(0.73,0.6,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0.82,0.6,0.0);
		glVertex3f(0.86,0.6,0.0);
		glVertex3f(0.86,0.39,0.0);
		glVertex3f(0.82,0.39,0.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3f(0.82,0.39,0.0);
		glVertex3f(0.95,0.39,0.0);
		glVertex3f(0.95,0.36,0.0);
		glVertex3f(0.82,0.36,0.0);
	glEnd();

	//sayap
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.27,0.67,0.0);
		glVertex3f(0.47,PosY1,0.0);
		glVertex3f(0.81,PosY2,0.0);
		glVertex3f(0.6,PosY3,0.0);
		glVertex3f(0.72,PosY4,0.0);
		glVertex3f(0.49,0.67,0.0);
	glEnd();
	glutSwapBuffers();
	PosY1 -= 2*gfDeltaX;
	PosY2 -= 2*gfDeltaX;
	PosY3 -= gfDeltaX;
	PosY4 -= gfDeltaX;
	if (PosY2 >= 1.0 || PosY1 <= 0.0) {
		gfDeltaX = -gfDeltaX;
	}
	glutPostRedisplay();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,0);
	glutCreateWindow("Cimbel Extension");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}