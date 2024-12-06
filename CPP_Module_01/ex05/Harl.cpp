/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:28:17 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/16 11:42:24 by bhumeau          ###   ########.fr       */
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
	void (Harl::*member_ptr[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string table[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(table[i]))
			(this->*member_ptr[i])();
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
