/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:17 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/12 13:05:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Class Harl has been created!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Class Harl has been destroyed!" << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string table[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < 4; i++)
		if (!level.compare(table[i]))
			break;
	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug( void )
{
	std::cout << "DEBUG" << std::endl;
}
void Harl::info( void )
{
	std::cout << "INFO" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING" << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR" << std::endl;
}
