/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:51:51 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/09 14:02:10 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Origin("Origin");
	Origin.takeDamage(9);
	ClapTrap Copy(Origin);
	ClapTrap Equal;
	Equal = Origin;
	std::cout << std::endl;
	Copy.takeDamage(1);
	Equal.takeDamage(1);
	std::cout << std::endl;

	Origin.beRepaired(4294967293);
	Origin.beRepaired(1);
	Origin.beRepaired(5000);
	std::cout << std::endl;

	ClapTrap P1("Metag Robill");
	ClapTrap P2("Emma Tompouce");

	P1.attack("Emma Tompouce");
	P2.takeDamage(0);
	P2.beRepaired(6);
	
	std::cout << std::endl;

	ClapTrap P3(P1);
	ClapTrap P4;

	for (int i = 0; i < 11; i++)
	{
		P3.attack("unnamed");
		P4.takeDamage(0);
		P4.beRepaired(5);
	}
	P4.attack("Anyone");

	std::cout << std::endl;
	P4.takeDamage(600);
	P4.attack("Anyone");
	P4.beRepaired(10);
	P4.takeDamage(1);
	std::cout << std::endl;
	return (0);
}
