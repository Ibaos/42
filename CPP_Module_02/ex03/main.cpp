/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:23:27 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/02 13:45:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0,0);
	Point b(0,4);
	Point c(4,0);
	Point p(2,2);
	Point p2(2,1.9);
	if (bsp(a, b, c, p) == true)
		std::cout << "Point is inside" << std::endl;
	else
		std::cout << "Point is outside" << std::endl;
	if (bsp(a, b, c, p2) == true)
		std::cout << "Point is inside" << std::endl;
	else
		std::cout << "Point is outside" << std::endl;
	return (0);
}
