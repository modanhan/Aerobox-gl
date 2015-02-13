#pragma once

#include <vector>

#include "gllibs.h"

namespace aerobox {

bool keydown(int);

bool keypressed(int);

bool keyreleased(int);

void keyboardPostRedisplay();

void keyboardFunc(unsigned char, int, int);

void keyboardUpFunc(unsigned char, int, int);
}
