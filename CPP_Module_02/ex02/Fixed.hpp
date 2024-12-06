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
		Fixed &operator=(const Fixed &right_value);
		bool operator>(const Fixed &right_value);
		bool operator<(const Fixed &right_value);
		bool operator>=(const Fixed &right_value);
		bool operator<=(const Fixed &right_value);
		bool operator==(const Fixed &right_value);
		bool operator!=(const Fixed &right_value);
		Fixed	operator+(const Fixed &right_value);
		Fixed	operator-(const Fixed &right_value);
		Fixed	operator*(const Fixed &right_value);
		Fixed	operator/(const Fixed &right_value);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		~Fixed();

		static Fixed min(Fixed &left_value, Fixed &right_value);
		static Fixed min(const Fixed &left_value, const Fixed &right_value);
		static Fixed max(Fixed &left_value, Fixed &right_value);
		static Fixed max(const Fixed &left_value, const Fixed &right_value);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int _value;
		static const int _nb_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &right_value);

#endif