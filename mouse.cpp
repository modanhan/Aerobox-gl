#include "mouse.h"

#include <iostream>
#include <math.h>

#include "gllibs.h"
#include "viewport.h"
namespace aerobox {
float gx = 0, gz = 0;
glm::vec3 rayorigin(0, 0, 0);
glm::vec3 raydir(0, 0, 0);
void mousefunc(int key, int state, int x, int y) {
	glm::vec3 view = vplookat - vpposition;
	view = glm::normalize(view);
	glm::vec3 h = glm::cross(view, vpup);
	h = glm::normalize(h);
	glm::vec3 v = glm::cross(h, view);
	v = glm::normalize(v);

	float rad = fov * M_PI / 180;
	float vl = tan(rad / 2) * vpnear;
	float hl = vl * (float) width / height;
	h *= hl;
	v *= vl;
	float fx = x, fy = -y;
	fx -= width / 2;
	fy += height / 2;
	fx /= width / 2;
	fy /= height / 2;

	rayorigin = vpposition;
	rayorigin += view * vpnear;
	h *= fx;
	rayorigin += h;
	v *= fy;
	rayorigin += v;

	raydir = rayorigin - vpposition;
	gx = vpposition[0] - raydir[0] * vpposition[1] / raydir[1];
	gz = vpposition[2] - raydir[2] * vpposition[1] / raydir[1];
}
}
