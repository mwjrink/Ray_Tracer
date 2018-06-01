#pragma once

struct Plane {
public:
	float A;
	float B;
	float C;
	float D;
	//Ax + By + Cz = D
	Plane(float A, float B, float C, float D) {
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}

	Plane(Vector Normal, Point p) {
		this->A = Normal.X;
		this->B = Normal.Y;
		this->C = Normal.Z;
		this->D = A * p.X + B * p.Y + C * p.Z;
	}
};