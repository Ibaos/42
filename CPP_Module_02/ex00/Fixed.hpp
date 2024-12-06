#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed& paste);
		Fixed& operator=(Fixed& new_value);
		~Fixed();
		int	getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int	_value;
		static const int _nb_bits = 8;
};

#endif