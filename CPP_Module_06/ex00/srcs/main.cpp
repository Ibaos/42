/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/02/04 14:30:20 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
