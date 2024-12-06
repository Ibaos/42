#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &paste);
		Fixed &operator=(const Fixed &new_value);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int _value;
		static const int _nb_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &new_value);

#endif