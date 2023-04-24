#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		m_fixed = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num):m_fixed(num * (1 << m_fixed_bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num):m_fixed(std::roundf(num * (1 << m_fixed_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (m_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	m_fixed = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(m_fixed) / (1 << m_fixed_bits));
}

int		Fixed::toInt(void) const
{
	return (m_fixed >> m_fixed_bits);
}

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed)
{
	ostr << fixed.toFloat();
	return (ostr);
}