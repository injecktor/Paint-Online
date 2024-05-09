#pragma once

#include <windows.h>

enum MenuFileProcedures {
	New = 0,
	Open,
	Exit,
};

class Color
{
public:
	int r, g, b;

	Color();
	Color(int R, int G, int B);
	Color(COLORREF colorRef);

	Color operator+(const Color other);
	Color operator-(const Color other);
	Color operator*(int t);
	Color operator/(int t);

	COLORREF toRGB();

	Color Lerp(Color toColor, int t, int p);
};