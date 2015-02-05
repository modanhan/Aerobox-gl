#pragma once
#include <vector>
#include "face.h"
namespace aerobox {
class objfile {
public:
	std::vector<vec3<float> > vertices, normals;
	std::vector<face> faces;
	objfile(const char*);
	void render();
};
}
