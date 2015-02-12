#pragma once

#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <glm\glm.hpp>
#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#endif