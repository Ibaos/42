/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:14:32 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/09 17:25:22 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Frag: Default constructor called" << std::endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &paste): ClapTrap(paste)
{
	std::cout << "Frag: Default copy constructor called" << std::endl;
	_hit_point = paste._hit_point;
	_attack_damage = paste._attack_damage;
	_energy_point = paste._energy_point;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Frag: Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit_point = copy._hit_point;
		_attack_damage = copy._attack_damage;
		_energy_point = copy._energy_point;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Frag: Default destructor called" << std::endl;
}

FragTrap::FragTrap(std::string new_name): ClapTrap(new_name)
{
	std::cout << "Frag: Constructor called with name: " << _name << std::endl;
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}

void FragTrap::attack(const std::string& target)
{
	std::cout << "Frag: ";
	ClapTrap::attack(target);
}

void FragTrap::highFivesGuys()
{
	if (_hit_point > 0)
		std::cout << "FragTrap wants to High Five!" << std::endl;
	else
		std::cout << "FragTrap would probably wantto High Five if he wasn't dead!" << std::endl;
}
