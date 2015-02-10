#include <vector>
namespace aerobox {
std::vector<bool> keydown(256, 0), keypressed(256, 0), keyreleased(256, 0);

void keyboardPostRedisplay() {
	keypressed.assign(256, 0);
	keyreleased.assign(256, 0);
}

void keyboardFunc(unsigned char key, int x, int y) {
	keypressed[key] = 1;
	keydown[key] = 1;
}

void keyboardUpFunc(unsigned char key, int x, int y) {
	keyreleased[key] = 1;
	keydown[key] = 0;
}
}
