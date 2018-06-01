#include "MathUtility.h"



float MathUtility::DotProduct(Vector v1, Vector v2) {
	return v1.X*v2.X + v1.Y*v2.Y + v1.Z*v2.Z;
}

Vector MathUtility::CrossProduct(Vector v1, Vector v2) {
	return Vector(v1.StartingPoint, v1.Y*v2.Z - v1.Z*v2.Y, v1.Z*v2.X - v1.X*v2.Z, v1.X*v2.Y - v1.Y*v2.X);
}

Vector MathUtility::AddVectors(Vector v1, Vector v2) {
	return Vector(v1.StartingPoint, v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
}

Vector MathUtility::Reflection(Vector v, Plane p) {
	//Vnew = -2 * (V dot N)*N + V
	float t = (p.A*v.StartingPoint.X + p.B*v.StartingPoint.Y + p.C*v.StartingPoint.Z - p.D) / (-1 * (p.A*v.X + p.B*v.Y + p.C*v.Z));
	float mult = -2 * DotProduct(v, Vector(Point(float(0), float(0), float(0)), p.A, p.B, p.C));
	return Vector(Point(
		v.StartingPoint.X + v.X*t,
		v.StartingPoint.Y + v.Y*t,
		v.StartingPoint.Z + v.Z*t
	),
		v.X + p.A*mult,
		v.Y + p.B*mult,
		v.Z + p.C*mult
	);
}

Vector MathUtility::VectorFromPoints(Point p1, Point p2) {
	return Vector(p1, p2.X - p1.X, p2.Y - p1.Y, p2.Z - p1.Z);
}

int MathUtility::Sign(const int& x) {
	return (x > 0) - (x < 0);
}

float MathUtility::Sign(const float& x) {
	return (x > 0) - (x < 0);
}

Plane MathUtility::PlaneFromThreePoints(Point p1, Point p2, Point p3) {
	return Plane(
		CrossProduct(
			VectorFromPoints(p1, p2),
			VectorFromPoints(p2, p3)),
		p3
	);
}

bool MathUtility::IsPointInTriangle(const Point& A, const Point& B, const Point& C, const Point& D) {

	//TODO can efficiency be improved??

	// Compute vectors        
	Vector v0 = Vector(A, C.X - A.X, C.Y - A.Y, C.Z - A.Z);
	Vector v1 = Vector(A, B.X - A.X, B.Y - A.Y, B.Z - A.Z);
	Vector v2 = Vector(A, D.X - A.X, D.Y - A.Y, D.Z - A.Z);

	// Compute dot products
	float dot00 = DotProduct(v0, v0);
	float dot01 = DotProduct(v0, v1);
	float dot02 = DotProduct(v0, v2);
	float dot11 = DotProduct(v1, v1);
	float dot12 = DotProduct(v1, v2);

	// Compute barycentric coordinates
	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return (u >= 0) && (v >= 0) && (u + v < 1);
}
