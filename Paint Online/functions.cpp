#include "functions.h"

RECT CreateRect(int x1, int y1, int width, int height)
{
	return RECT{ x1, y1, x1 + width, y1 + height };
}