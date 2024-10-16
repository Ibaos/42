/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:26:37 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/16 13:48:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Need 2 arguments!" << std::endl, 1);
	std::string level =  argv[1];
	Harl test;
	int i = 0;
	std::string table[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
		if (!level.compare(table[i]))
			break;
	std::cout << i << std::endl;
	switch (i)
	{
		case 0:
			test.complain("DEBUG");
		case 1:
			test.complain("INFO");
		case 2:
			test.complain("WARNING");
		case 3:
			test.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}