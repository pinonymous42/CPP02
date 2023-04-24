#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		Fixed(const int num);
		Fixed(const float num);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int					m_fixed;
		static const int	m_fixed_bits = 8;
};

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed);
#endif