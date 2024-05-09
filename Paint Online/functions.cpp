#include "functions.h"

RECT CreateRect(int x1, int y1, int width, int height)
{
	return RECT{ x1, y1, x1 + width, y1 + height };
}

void CreateGradientRect(HDC hDC, const RECT* lprc, Color leftColor, Color rightColor)
{
	int width = lprc->right - lprc->left;

	for (int x = lprc->left; x < lprc->right; x++)
	{
		for (int y = lprc->top; y < lprc->bottom; y++)
		{
			Color newColor = leftColor.Lerp(rightColor, x - lprc->left, width);
			SetPixel(hDC, x, y, newColor.toRGB());
		}
	}
}