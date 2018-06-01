#pragma once
#include <algorithm>

struct Color
{
	//use a single int?
	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int A;

	Color(int r, int g, int b, int a) {
		R = r;
		G = g;
		B = b;
		A = a;
	}

	Color& operator +=(const Color& c) {
		R = min((int)(c.R + R), 255);
		G = min((int)(c.G + G), 255);
		B = min((int)(c.B + B), 255);
		A = min((int)(c.A + A), 255);
		return *this;
	}

	Color operator +(const Color& c) {
		return Color(
			min((int)(c.R + R), 255),
			min((int)(c.G + G), 255),
			min((int)(c.B + B), 255),
			min((int)(c.A + A), 255));
	}

	/*Color& operator=(Color& c)
	{
		this->swap(c);
		return *this;
	}*/

	Color& operator=(Color& c) {
		R = c.R;
		G = c.G;
		B = c.B;
		A = c.A;
		return *this;
	}
};