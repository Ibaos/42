/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:51:51 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 14:56:13 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap P1("Metag Robill");
	ScavTrap P2("Emma Tompouce");

	P1.attack("Emma Tompouce");
	P2.takeDamage(0);
	P2.beRepaired(6);
	
	std::cout << std::endl;

	ScavTrap P3(P1);
	ScavTrap P4;

	for (int i = 0; i < 51; i++)
	{
		P3.attack("unnamed");
		P4.takeDamage(20);
		P4.beRepaired(25);
	}
	P4.attack("Anyone");

	std::cout << std::endl;
	P4.takeDamage(350);
	P4.attack("Anyone");
	P4.beRepaired(10);
	P4.takeDamage(1);
	std::cout << std::endl;

	P1.guardGate();
	P1.takeDamage(100);
	P1.guardGate();
	std::cout << std::endl;
}
