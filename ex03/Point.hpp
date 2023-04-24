#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &point);
		Point &operator=(const Point &point);
		const Fixed &getX(void) const; 
		const Fixed &getY(void) const;
	private:
		const Fixed m_x;
		const Fixed m_y;
};

std::ostream &operator<<(std::ostream& ostr, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif