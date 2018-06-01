#pragma once
#include "ImportUtility.h"
#include "Vector.h"
#include "Color.h"

class Ray {
private:
	Vector RayVec;
public:
	Ray(Vector);

	Color Trace();

	~Ray();
};

