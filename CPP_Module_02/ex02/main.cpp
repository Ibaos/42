/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:23:27 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/02 13:44:41 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed z(27);
	Fixed y(3);

	std::cout << z << std::endl;
	std::cout << y << std::endl;
	
	std::cout << std::endl << "Operations of " << z << " with " << y << std::endl << std::endl;

	std::cout << z + y << std::endl;
	std::cout << z - y << std::endl;
	std::cout << z * y << std::endl;
	std::cout << z / y << std::endl;

	std::cout << std::endl << "Comparisons of " << z << " with " << y << std::endl << std::endl;

	std::cout << (int)(z > y) << std::endl;
	std::cout << (int)(z < y) << std::endl;
	std::cout << (int)(z >= y) << std::endl;
	std::cout << (int)(z <= y) << std::endl;
	std::cout << (int)(z == y) << std::endl;
	std::cout << (int)(z != y) << std::endl;

	std::cout << std::endl << "Incrementation" << std::endl << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}
