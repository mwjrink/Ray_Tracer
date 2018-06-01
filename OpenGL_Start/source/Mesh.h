#pragma once
#include "Point.h"
#include "Triangle.h"
#include <map>

class Mesh
{
private:
	std::string path;
	std::map<std::string, Point> points;
	Triangle triangles[]; //possible hold three versions in memory, either resort by x, y, z each time or once and store OR vvv
	//TODO store in kD tree? SORTING NEEDED FOR KD TREE

public:
	Mesh();

	~Mesh();
};

