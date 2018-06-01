#pragma once
#include "ImportUtility.h"
#include "Vector.h"
#include "Plane.h"

class MathUtility {

public:
	//Member Functions
	static float DotProduct(Vector, Vector);
	static Vector CrossProduct(Vector, Vector);
	static Vector AddVectors(Vector, Vector);
	static Vector Reflection(Vector, Plane);
	static Plane PlaneFromThreePoints(Point, Point, Point);
	static Vector VectorFromPoints(Point, Point);
	static int Sign(const int& x);
	static float Sign(const float& x);
	static bool IsPointInTriangle(const Point&, const Point&, const Point&, const Point&);
};