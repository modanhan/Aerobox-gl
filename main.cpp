#include <bits/stdc++.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "aerobox.h"

using namespace std;

aerobox::objfile o("box centered.obj");

void init() {

}

void display() {
	glColor4f(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	o.render();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0, 10.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
