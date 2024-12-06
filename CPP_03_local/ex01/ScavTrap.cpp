/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:41:22 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 14:56:59 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Scav: Default constructor called" << std::endl;
	scavStats();
}

ScavTrap::ScavTrap(const ScavTrap &paste): ClapTrap(paste)
{
	std::cout << "Scav: Default copy constructor called" << std::endl;
	_name = paste._name;
	scavStats();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Scav: Copy assignment operator called" << std::endl;
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav: Default destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string new_name): ClapTrap(new_name)
{
	std::cout << "Scav: Constructor called with name: " << _name << std::endl;
	scavStats();
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

void ScavTrap::guardGate()
{
	if (_hit_point > 0)
		std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap would probably be in Gate keeper mode if he wasn't dead!" << std::endl;

}

void ScavTrap::scavStats()
{
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}