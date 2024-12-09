/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:57:50 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/09 17:24:22 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "Diamond: Default constructor called" << std::endl;
	_name = ClapTrap::_name;
	ClapTrap::_name = ClapTrap::_name + "_clap_name";
	_hit_point = FragTrap::
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &paste): ClapTrap(paste), _name(paste._name)
{
	std::cout << "Diamond: Default copy constructor called" << std::endl;
	_hit_point = paste._hit_point;
	_energy_point = paste._energy_point;
	_attack_damage = paste._attack_damage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Diamond: Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		ClapTrap::_name = copy.ClapTrap::_name;
		_hit_point = copy._hit_point;
		_energy_point = copy._energy_point;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond: Default destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name): ClapTrap(new_name), _name(new_name)
{
	std::cout << "Diamond: Constructor called with name: " << _name << std::endl;
	ClapTrap::_name = new_name + "_clap_name";
	_hit_point = FragTrap::
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	if (_hit_point > 0)
		std::cout << "I'm " << ClapTrap::_name << " as Clap and " << _name << " as Diamond at the same time!" << std::endl;
	else
		std::cout << "I was " << ClapTrap::_name << " as Diamond and " << _name << " as Diamond at the same time!" << std::endl;
}
