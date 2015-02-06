#include "aerobox.h"
#define TIMERSECS 1

#define PI 3.14159265
using namespace std;

aerobox::objfile o("box.obj");

void init() {

}
float angle = 0.0f;

void display() {
	angle+=0.5f*PI;
	glColor4f(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	o.render();
	glPopMatrix();
	glFlush();
}

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat) w / (GLfloat) h, 0.1, 20.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}
void animate(int value) {
  glutTimerFunc(TIMERSECS, animate, 1);
  glutPostRedisplay();
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(TIMERSECS, animate, 0);

	glutMainLoop();
	return 0;
}
