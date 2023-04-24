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

		//comparison operator
		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		//arithmatic operator
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		//increment, decrement
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int					m_fixed;
		static const int	m_fixed_bits = 8;
};

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed);
#endif