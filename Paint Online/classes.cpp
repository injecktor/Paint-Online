#include "classes.h"

Color::Color() { r = 0, g = 0, b = 0; };
Color::Color(int R, int G, int B) { r = R; g = G; b = B; };
Color::Color(COLORREF colorRef) { b = (colorRef >> 16) & 0xFF; g = (colorRef >> 8) & 0xFF; r = colorRef & 0xFF; };

Color Color::operator+(const Color other) { return Color(r + other.r, g + other.g, b + other.b); };
Color Color::operator-(const Color other) { return Color(r - other.r, g - other.g, b - other.b); };
Color Color::operator*(int t) { return Color(r * t, g * t, b * t); };
Color Color::operator/(int t) { return Color(r / t, g / t, b / t); };

COLORREF Color::toRGB()
{
	return (b << 16) | (g << 8) | r;
}

Color Color::Lerp(Color toColor, int t, int p)
{
	return *this + (toColor - *this) * t / p;
}