#include "Fixed.hpp"

Fixed::Fixed():m_fixed(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		m_fixed = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num):m_fixed(num * (1 << m_fixed_bits))
{
}

Fixed::Fixed(const float num):m_fixed(std::roundf(num * (1 << m_fixed_bits)))
{
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

//comparison operator
bool Fixed::operator>(const Fixed &fixed) const
{
	return (m_fixed > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (m_fixed < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (m_fixed >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (m_fixed <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (m_fixed == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (m_fixed != fixed.getRawBits());
}

//arithmatic operator
Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed tmp;

	tmp.setRawBits(m_fixed + fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed tmp;

	tmp.setRawBits(m_fixed - fixed.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed tmp;

	tmp.setRawBits((m_fixed * fixed.getRawBits()) >> m_fixed_bits);
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed tmp;

	if (fixed.getRawBits() != 0)
		tmp.setRawBits((m_fixed / fixed.getRawBits()) >> m_fixed_bits);
	return (tmp);
}

//increment, decrement
Fixed &Fixed::operator++(void)
{
	m_fixed++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	m_fixed--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	else
		return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	else
		return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}