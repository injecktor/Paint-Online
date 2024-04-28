#include "functions.h"

RECT CreateRect(int x1, int y1, int width, int height)
{
	return RECT{ x1 + width, y1, x1, y1 + height };
}

RECT CreateRectAlt(int x1, int y1, int x2, int y2)
{
	return RECT{ x2, y1, x1, y2 };
}