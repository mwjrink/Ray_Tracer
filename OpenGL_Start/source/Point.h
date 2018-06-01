#pragma once
#include "ImportUtility.h"
#include "Vector.h"

struct Point {
	float X;
	float Y;
	float Z;

	Point() {
		X = 0;
		Y = 0;
		Z = 0;
	}

	Point(float x, float y, float z) {
		X = x;
		Y = y;
		Z = z;
	}

	inline Point operator+(const Vector& rhs)
	{
		return Point(this->X + rhs.X, this->Y + rhs.Y, this->Z + rhs.Z);
	}

	inline Point operator+=(const Vector& rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
		this->Z += rhs.Z;
		return *this;
	}

	//Point(Point &p) {
	//	X = p.X; 
	//	Y = p.Y; 
	//	Z = p.Z;
	//}
};