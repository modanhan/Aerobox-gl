#include "gllibs.h"

#include "mouse.h"
#include "keyboard.h"
#include "objfile.h"
#include "viewport.h"

using namespace std;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display() {
	glViewport(0, 0, (GLsizei) aerobox::width, (GLsizei) aerobox::height);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(aerobox::fov,
			(GLfloat) aerobox::width / (GLfloat) aerobox::height,
			aerobox::vpnear, aerobox::vpfar);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(aerobox::vpposition[0], aerobox::vpposition[1],
			aerobox::vpposition[2], aerobox::vplookat[0], aerobox::vplookat[1],
			aerobox::vplookat[2],
			aerobox::vpup[0],aerobox::vpup[1],aerobox::vpup[2]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
	 glTranslatef(aerobox::gx,0,aerobox::gz);
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glutWireSphere(.5, 10, 10);
	 glPopMatrix();

/*	glBegin (GL_LINES);
	glVertex3f(aerobox::rayorigin[0], aerobox::rayorigin[1],
			aerobox::rayorigin[2]);
	glVertex3f(aerobox::raydir[0], aerobox::raydir[1], aerobox::raydir[2]);
	glEnd();*/

	glColor4f(1, 1, 1, 1);
	glBegin(GL_LINES);
	for (int i = -10; i <= 10; i++) {
		glVertex3f(i, 0, -100);
		glVertex3f(i, 0, 100);
		glVertex3f(-100, 0, i);
		glVertex3f(100, 0, i);
	}
	glEnd();

//	o.render();

	aerobox::keyboardPostRedisplay();
	glutPostRedisplay();
	glFlush();
}

void reshape(int w, int h) {
	aerobox::width = w;
	aerobox::height = h;
}

int main(int argc, char* argv[]) {
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(500, 250);
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
