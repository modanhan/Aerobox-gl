#pragma once
#include <vector>

#include "gllibs.h"

#include "face.h"
namespace aerobox {
class objfile {
public:
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> texcoords;
	std::vector<face> faces;
	objfile(const char*);
	void render();
};
}
