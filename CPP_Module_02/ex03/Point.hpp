#ifndef POINT_H
# define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &paste);
		Point &operator=(const Point &right_value);
		~Point();
		const Fixed &get_x() const;
		const Fixed &get_y() const;
		float cross_calc(const Point &second_point, const Point &third_point) const;
	private:
		Fixed x;
		Fixed y;
};

std::ostream &operator<<(std::ostream &os, const Point &right_value);

#endif