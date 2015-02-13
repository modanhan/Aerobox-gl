#include <string>
#include <vector>

#include <cstdlib>
#include <fstream>
#include <istream>

#include "objfile.h"
namespace aerobox{
	objfile::objfile(const char* file) {
		std::ifstream in(file, std::ios::in);
		std::string s;
		while (in >> s) {
			if (s == "v") {
				glm::vec3 v;
				in >> v[0] >> v[1] >> v[2];
				vertices.push_back(v);
			}
			else if (s == "vt") {
				glm::vec2 v;
				in >> v[0] >> v[1];
				texcoords.push_back(v);
			}
			else if (s == "vn") {
				glm::vec3 v;
				in >> v[0] >> v[1] >> v[2];
				normals.push_back(v);
			}
			else if (s == "f") {
				char* c = new char[128];
				in >> c;
				glm::detail::tvec3<int> vi;
				glm::detail::tvec3<int> vti;
				glm::detail::tvec3<int> vni;
				sscanf(c, "%d/%d/%d", &vi[0], &vti[0], &vni[0]);
				in >> c;
				sscanf(c, "%d/%d/%d", &vi[1], &vti[1], &vni[1]);
				in >> c;
				sscanf(c, "%d/%d/%d", &vi[2], &vti[2], &vni[2]);
				vi[0]--;
				vi[1]--;
				vi[2]--;
				vti[0]--;
				vti[1]--;
				vti[2]--;
				vni[0]--;
				vni[1]--;
				vni[2]--;
				face f;
				f.vertex = vi;
				f.texcoord = vti;
				f.normal = vni;
				faces.push_back(f);
			}
			else {
			}
		}
	}
	void objfile::render() {
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < faces.size(); i++) {
			glTexCoord2f(texcoords[faces[i].texcoord[0]][0],
				texcoords[faces[i].texcoord[0]][1]);
			glNormal3f(normals[faces[i].normal[0]][0], normals[faces[i].normal[0]][1],
				normals[faces[i].normal[0]][2]);
			glVertex3f(vertices[faces[i].vertex[0]][0], vertices[faces[i].vertex[0]][1],
				vertices[faces[i].vertex[0]][2]);

			glTexCoord2f(texcoords[faces[i].texcoord[1]][0],
				texcoords[faces[i].texcoord[1]][1]);
			glNormal3f(normals[faces[i].normal[1]][0], normals[faces[i].normal[1]][1],
				normals[faces[i].normal[1]][2]);
			glVertex3f(vertices[faces[i].vertex[1]][0], vertices[faces[i].vertex[1]][1],
				vertices[faces[i].vertex[1]][2]);

			glTexCoord2f(texcoords[faces[i].texcoord[2]][0],
				texcoords[faces[i].texcoord[2]][1]);
			glNormal3f(normals[faces[i].normal[2]][0], normals[faces[i].normal[2]][1],
				normals[faces[i].normal[2]][2]);
			glVertex3f(vertices[faces[i].vertex[2]][0], vertices[faces[i].vertex[2]][1],
				vertices[faces[i].vertex[2]][2]);
		}
		glEnd();
	}
}