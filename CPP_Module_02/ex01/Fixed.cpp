/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:07:57 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/20 16:22:52 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << 8)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &paste)
{
	this->_value = paste.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &new_value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &new_value)
		_value = new_value.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (_value / (float)(1 << 8));
}

int Fixed::toInt() const
{
	return (_value >> 8);
}

std::ostream &operator<<(std::ostream &os, const Fixed &new_value)
{
	os << new_value.toFloat();
	return os;
}
