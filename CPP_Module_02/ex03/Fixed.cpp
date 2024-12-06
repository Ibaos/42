/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:07:57 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/28 15:34:19 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << 8)
{
	//std::cout << "Int constructor called with value: " << value << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << 8)))
{
	//std::cout << "Float constructor called with value: " << value << std::endl;
}

Fixed::Fixed(const Fixed &paste)
{
	//std::cout << "Copy constructor called with value: " << paste.getRawBits() << std::endl;
	this->_value = paste.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &right_value)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &right_value)
		_value = right_value.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &right_value)
{
	//std::cout << "Operator '>' called" << std::endl;
	return (_value > right_value.getRawBits());
}

bool Fixed::operator<(const Fixed &right_value)
{
	//std::cout << "Operator '<' called" << std::endl;
	return (_value < right_value.getRawBits());
}

bool Fixed::operator>=(const Fixed &right_value)
{
	//std::cout << "Operator '>=' called" << std::endl;
	return (_value >= right_value.getRawBits());
}
bool Fixed::operator<=(const Fixed &right_value)
{
	//std::cout << "Operator '<=' called" << std::endl;
	return (_value <= right_value.getRawBits());
}

bool Fixed::operator==(const Fixed &right_value)
{
	//std::cout << "Operator '==' called" << std::endl;
	return (_value == right_value.getRawBits());
}

bool Fixed::operator!=(const Fixed &right_value)
{
	//std::cout << "Operator '!=' called" << std::endl;
	return (_value != right_value.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &right_value)
{
	//std::cout << "Operator '+' called" << std::endl;
	Fixed res(this->toFloat() + right_value.toFloat());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &right_value)
{
	//std::cout << "Operator '-' called" << std::endl;
	Fixed res(this->toFloat() - right_value.toFloat());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &right_value)
{
	//std::cout << "Operator '*' called" << std::endl;
	Fixed res(this->toFloat() * right_value.toFloat());
	return (res);
}

Fixed	Fixed::operator/(const Fixed &right_value)
{
	//std::cout << "Operator '/' called" << std::endl;
	if (right_value.toFloat() == 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	Fixed res(this->toFloat() / right_value.toFloat());
	return (res);
}

Fixed	&Fixed::operator++()
{
	//std::cout << "Operator '++x' called" << std::endl;
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	//std::cout << "Operator 'x++' called" << std::endl;
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	//std::cout << "Operator '--x' called" << std::endl;
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	//std::cout << "Operator 'x--' called" << std::endl;
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed Fixed::min(Fixed &left_value, Fixed &right_value)
{
	//std::cout << "Function 'min' called" << std::endl;
	if (left_value.toFloat() < right_value.toFloat())
		return (left_value);
	return (right_value);
}

Fixed Fixed::min(const Fixed &left_value, const Fixed &right_value)
{
	//std::cout << "Function 'min' called" << std::endl;
	if (left_value.toFloat() < right_value.toFloat())
		return (left_value);
	return (right_value);
}

Fixed Fixed::max(Fixed &left_value, Fixed &right_value)
{
	//std::cout << "Function 'max' called" << std::endl;
	if (left_value.toFloat() > right_value.toFloat())
		return (left_value);
	return (right_value);
}

Fixed Fixed::max(const Fixed &left_value, const Fixed &right_value)
{
	//std::cout << "Function 'max' called" << std::endl;
	if (left_value.toFloat() > right_value.toFloat())
		return (left_value);
	return (right_value);
}

int Fixed::getRawBits() const
{
	//std::cout << "Function 'getRawBits' called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "Function 'setRawBits' called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const
{
	//std::cout << "Function 'toFloat' called" << std::endl;
	return (_value / (float)(1 << 8));
}

int Fixed::toInt() const
{
	//std::cout << "Function 'toInt' called" << std::endl;
	return (_value >> 8);
}

std::ostream &operator<<(std::ostream &os, const Fixed &right_value)
{
	//std::cout << "Operator '<<' called" << std::endl;
	os << right_value.toFloat();
	return os;
}
