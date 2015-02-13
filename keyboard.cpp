#include "keyboard.h"
namespace aerobox {
std::vector<bool> kd(256, 0), lkd(256, 0);
bool keydown(int c) {
	return kd[c];
}

bool keypressed(int c) {
	return (!lkd[c]) && kd[c];
}

bool keyreleased(int c) {
	return lkd[c] && (!kd[c]);
}

void keyboardPostRedisplay() {
	lkd = kd;
}

void keyboardFunc(unsigned char key, int x, int y) {
	kd[key] = 1;
}

void keyboardUpFunc(unsigned char key, int x, int y) {
	kd[key] = 0;
}
}
