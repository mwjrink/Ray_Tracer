#include "Pixel.h"

Pixel::Pixel() : X(0), Y(0), color(0, 0, 0, 0) {

}

Pixel::Pixel(int& x, int& y) : X(x), Y(y), color(0, 0, 0, 0) {

}

void Pixel::SetXY(int& x, int& y) {
	X = x;
	Y = y;
}

/*
(-Width/2,Height/2)-------------------------(Width/2,Height/2)
|                                                            |
|                                                            |
|                          (0,0)                             |
|                                                            |
|                                                            |
(-Width/2,-Height/2)--------------------------(Width,-Height/2)
*/

void Pixel::RefreshPoint(const Point& A, const Vector& dirVecB, const Vector& dirVecD) {

	//TODO determine this
	int scale = 1;
	Static_View_Helper StaticViewHelper;

	//TODO EFFICIENCIFY

	point = A;
	int tempX, tempY;
	tempX += X > (StaticViewHelper.Width / 2) ? 1 : 0;
	tempX -= (StaticViewHelper.Width / 2);

	tempY += Y > (StaticViewHelper.Height / 2) ? 1 : 0;
	tempX -= (StaticViewHelper.Height / 2);

	float xMult = scale * tempX;
	point += Vector(A, dirVecD.X*xMult, dirVecD.Y*xMult, dirVecD.Z*xMult);
	float yMult = scale * tempY);
	point += Vector(A, dirVecB.X*xMult, dirVecB.Y*xMult, dirVecB.Z*xMult);
}

static Point PointA(const Point& camera, const Vector& camVec) {
	return Point(camera) + camVec;
}

Pixel::~Pixel() {

}
