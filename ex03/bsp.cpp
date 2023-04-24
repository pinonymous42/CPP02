#include "Point.hpp"

float sign (Point p1, Point p2, Point p3)
{
    return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) - (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool b1, b2, b3;

	if (sign(point, a, b) == 0.0f || sign(point, b, c) == 0.0f || sign(point, c, a) == 0.0f)
		return (false);
   b1 = sign(point, a, b) < 0.0f;
   b2 = sign(point, b, c) < 0.0f;
   b3 = sign(point, c, a) < 0.0f;

   return ((b1 == b2) && (b2 == b3));
}