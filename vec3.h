#pragma once

namespace aerobox {
template<class T>
class vec3 {
public:
	T x, y, z;
};
template<>
class vec3<float> {
public:
	float x, y, z;
};
template<>
class vec3<int> {
public:
	int x, y, z;
};
}
