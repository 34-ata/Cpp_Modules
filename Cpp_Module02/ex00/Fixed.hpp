#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
	public:
		Fixed &operator=(const Fixed &other);
	public:
		int getRawBits(void) const;
		void setRawBits(const int raw);
	private:
		int bits;
		static const int fract = 8;
};

#endif
