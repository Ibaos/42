/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:51:40 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 15:42:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unnamed"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &paste): _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Default copy constructor called" << std::endl;
	_name = paste._name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string new_name): _name(new_name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "Constructor called with name: " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energy_point > 0 && _hit_point > 0)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		std::cout << _name << " is dead!" << std::endl;
	else if (_energy_point <= 0)
		std::cout << _name << " has no energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_point > 0)
	{
		std::cout << _name << " lost " << amount << " hit points!" << std::endl;
		_hit_point -= amount;
		if (_hit_point <= 0)
			std::cout << _name << " is now dead!" << std::endl;
	}
	else
		std::cout << _name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_point > 0 && _energy_point > 0)
	{
		_hit_point += amount;
		std::cout << _name << " healed for " << amount << ", health is now " << _hit_point << " hit points!" << std::endl;
		_energy_point--;
	}
	else if (_hit_point <= 0)
		std::cout << _name << " is dead!" << std::endl;
	else if (_energy_point <= 0)
		std::cout << _name << " has no energy to repair!" << std::endl;
}
