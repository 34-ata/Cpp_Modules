#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
	public:
		Fixed &operator=(const Fixed &other);
	public:
		int getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int bits;
		static const int fract = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedPoint);

#endif
