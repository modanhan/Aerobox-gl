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
	float x = 0, y = 0, z = 0;
};
template<>
class vec3<int> {
public:
	int x = 0, y = 0, z = 0;
};
}
