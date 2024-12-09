/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:51:51 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/09 17:36:14 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap Origin("Origin");
	Origin.takeDamage(99);
	FragTrap Copy(Origin);
	FragTrap Equal;
	Equal = Origin;
	std::cout << std::endl;
	Copy.takeDamage(1);
	Equal.takeDamage(1);
	std::cout << std::endl;

	Origin.beRepaired(4294967293);
	Origin.beRepaired(1);
	Origin.beRepaired(5000);
	std::cout << std::endl;

	FragTrap P1("Metag Robill");
	FragTrap P2("Emma Tompouce");

	P1.attack("Emma Tompouce");
	P2.takeDamage(0);
	P2.beRepaired(6);
	
	std::cout << std::endl;

	FragTrap P3(P1);
	FragTrap P4;

	for (int i = 0; i < 101; i++)
	{
		P3.attack("unnamed");
		P4.takeDamage(30);
		P4.beRepaired(35);
	}
	P4.attack("Anyone");

	std::cout << std::endl;
	P4.takeDamage(600);
	P4.attack("Anyone");
	P4.beRepaired(10);
	P4.takeDamage(1);
	std::cout << std::endl;

	P1.highFivesGuys();
	P1.takeDamage(100);
	P1.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
