#include "Point.hpp"

Point::Point():m_x(0), m_y(0)
{

}

Point::~Point()
{

}

Point::Point(const float x, const float y):m_x(x), m_y(y)
{

}

Point::Point(const Point &point)
{
	*this = point;
}

const Fixed &Point::getX(void) const
{
	return (m_x);
}

const Fixed &Point::getY(void) const
{
	return (m_y);
}

Point &Point::operator=(const Point &point)
{
	if (this != &point)
	{
		const_cast<Fixed &>(m_x) = point.getX();
		const_cast<Fixed &>(m_y) = point.getY();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream& ostr, const Point &point)
{
	std::cout << "x: " << point.getX() << ", y: " << point.getY();
	return (ostr);
}
