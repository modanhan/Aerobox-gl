#include "aerobox.h"
#include <bits/stdc++.h>
aerobox::objfile::objfile(const char* file) {
	std::ifstream in(file, std::ios::in);
	std::string s;
	while (in >> s) {
		if (s == "v") {
			vec3<float> v;
			in >> v.x >> v.y >> v.z;
			vertices.push_back(v);
		} else if (s == "vt") {

		} else if (s == "vn") {
			vec3<float> v;
			in >> v.x >> v.y >> v.z;
			normals.push_back(v);
		} else if (s == "f") {
			char* c = new char[128];
			in >> c;
			vec3<int> vi;
			sscanf(c, "%d/%d/%d", &vi.x, &vi.y, &vi.z);
			vi.x--;
			vi.y--;
			vi.z--;
			in >> c;
			vec3<int> vti;
			sscanf(c, "%d/%d/%d", &vti.x, &vti.y, &vti.z);
			vti.x--;
			vti.y--;
			vti.z--;
			in >> c;
			vec3<int> vni;
			sscanf(c, "%d/%d/%d", &vni.x, &vni.y, &vni.z);
			vni.x--;
			vni.y--;
			vni.z--;
			face f;
			f.vertex = vi;
			f.normal = vni;
			faces.push_back(f);
		} else {
		}
	}
}
void aerobox::objfile::render() {
	glBegin (GL_TRIANGLES);
	for (int i = 0; i < faces.size(); i++) {
		glNormal3f(normals[faces[i].normal.x].x, normals[faces[i].normal.x].y,
				normals[faces[i].normal.x].z);
		glVertex3f(vertices[faces[i].vertex.x].x, vertices[faces[i].vertex.x].y,
				vertices[faces[i].vertex.x].z);
		glNormal3f(normals[faces[i].normal.y].x, normals[faces[i].normal.y].y,
				normals[faces[i].normal.y].z);
		glVertex3f(vertices[faces[i].vertex.y].x, vertices[faces[i].vertex.y].y,
				vertices[faces[i].vertex.y].z);
		glNormal3f(normals[faces[i].normal.z].x, normals[faces[i].normal.z].y,
				normals[faces[i].normal.z].z);
		glVertex3f(vertices[faces[i].vertex.z].x, vertices[faces[i].vertex.z].y,
				vertices[faces[i].vertex.z].z);
	}
	glEnd();
}
