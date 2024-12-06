/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:57:50 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 15:43:46 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), _name(ClapTrap::_name + "_clap_name")
{
	std::cout << "Scav: Default constructor called" << std::endl;
	diamondStats();
}

DiamondTrap::DiamondTrap(const DiamondTrap &paste): ClapTrap(paste), _name(ClapTrap::_name + "_clap_name")
{
	std::cout << "Scav: Default copy constructor called" << std::endl;
	_name = paste._name;
	diamondStats();
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Scav: Copy assignment operator called" << std::endl;
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Scav: Default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name): ClapTrap(new_name), _name(ClapTrap::_name + "_clap_name")
{
	std::cout << "Scav: Constructor called with name: " << _name << std::endl;
	diamondStats();
}

void DiamondTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI()
{
	if (_hit_point > 0)
		std::cout << "I'm " << ClapTrap::_name << " and " << _name << " at the same time!" << std::endl;
	else
		std::cout << "I was " << ClapTrap::_name << " and " << _name << " at the same time!" << std::endl;
}

void DiamondTrap::diamondStats()
{
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 30;
}