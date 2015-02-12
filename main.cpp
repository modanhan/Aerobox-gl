#include "aerobox.h"

using namespace std;

int width = 0, height = 0;
glm::vec3 camposition(1,3,4), camlookat(0,0,0);

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display() {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat) width / (GLfloat) height, 0.1, 20.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camposition[0], camposition[1], camposition[2],
			camlookat[0], camlookat[1], camlookat[2], 0.0, 1.0, 0.0);
	glutPostRedisplay();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutWireSphere(.5, 10, 10);

	glColor4f(1, 1, 1, 1);
	glBegin (GL_LINES);
	for (int i = -10; i <= 10; i++) {
		glVertex3f(i, 0, -100);
		glVertex3f(i, 0, 100);
		glVertex3f(-100, 0, i);
		glVertex3f(100, 0, i);
	}
	glEnd();

	aerobox::keyboardPostRedisplay();
	glutPostRedisplay();
	glFlush();
}

void reshape(int w, int h) {
	width = w;
	height = h;
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLfloat) w / (GLfloat) h, 0.1, 20.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutPostRedisplay();
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

	glutMouseFunc(aerobox::mousefunc);

	glutMainLoop();
}
