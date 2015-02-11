#pragma once

#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#endif

#ifdef unix
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <fstream>
#include <istream>

#include "keyboard.h"