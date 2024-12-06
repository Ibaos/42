/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:40:13 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/29 14:26:05 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	//std::cout << "Default constructor called" << std::endl;
	x = Fixed(0);
	y = Fixed(0);
}

Point::Point(const float new_x, const float new_y)
{
	//std::cout << "Float constructor called with values: " << new_x << ", " << new_y << std::endl;
	x = Fixed(new_x);
	y = Fixed(new_y);
}

Point::Point(const Point &paste)
{
	//std::cout << "Copy constructor called with value: " << paste.x << " and " << paste.y << std::endl;
	x = paste.x;
	y = paste.y;
}

Point &Point::operator=(const Point &right_value)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &right_value)
	{
		x = right_value.x;
		y = right_value.y;
	}
	return (*this);
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;
}

const Fixed	&Point::get_x() const
{
	return (x);
}

const Fixed	&Point::get_y() const
{
	return (y);
}

float	Point::cross_calc(const Point &second_point, const Point &third_point) const
{
	return (
		((second_point.get_x().toFloat() - this->get_x().toFloat()) * (third_point.get_y().toFloat() - this->get_y().toFloat())) -
        ((second_point.get_y().toFloat() - this->get_y().toFloat()) * (third_point.get_x().toFloat() - this->get_x().toFloat()))
	);
}

std::ostream &operator<<(std::ostream &os, const Point &right_value)
{
	//std::cout << "Operator '<<' called" << std::endl;
	os << right_value.get_x() << right_value.get_y();
	return os;
}
