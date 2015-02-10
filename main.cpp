#include <iostream>
#include <cstring>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "keyboard.h"

using namespace std;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display() {
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(1.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);
	glFlush();
	
	aerobox::keyboardPostRedisplayFunc();

	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(500, 500);
	glutInit(&argc, argv);

	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutIgnoreKeyRepeat(1);

	glutKeyboardFunc(aerobox::keyboardFunc);
	glutKeyboardUpFunc(aerobox::keyboardUpFunc);
	glutMainLoop();
}
