#pragma once

#include "includes.h"

extern RECT CreateRect(int x1, int y1, int width, int height);

extern void CreateGradientRect(HDC hDC, const RECT* lprc, Color leftColor, Color rightColor);