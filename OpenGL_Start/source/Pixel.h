#pragma once
#include "ImportUtility.h"
#include "Point.h"
#include "Color.h"
#include "Vector.h"
#include "MathUtility.h"
#include "Static_View_Helper.h"

class Pixel {
private:
	Point point;
	Color color;
	int X, Y;

public:
	Pixel();
	Pixel(int&, int&);

	void SetXY(int&, int&);

	void RefreshPoint(const Point&, const Vector&, const Vector&);
	//static Vector DirVecB(const Point&, const Vector&);
	//static Vector DirVecD(const Point&, const Vector&);
	//static Point PointA(const Point&, const Vector&);

	~Pixel();
};

