#pragma once
#include "aerobox.h"
namespace aerobox {
class objfile {
public:
	std::vector<vec3<float> > vertices, normals;
	std::vector<vec2<float> > texcoords;
	std::vector<face> faces;
	objfile(const char*);
	void render();
};
}
