/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:14:32 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/06 15:40:14 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Frag: Default constructor called" << std::endl;
	fragStats();
}

FragTrap::FragTrap(const FragTrap &paste): ClapTrap(paste)
{
	std::cout << "Frag: Default copy constructor called" << std::endl;
	_name = paste._name;
	fragStats();
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Frag: Copy assignment operator called" << std::endl;
	if (this != &copy)
		_name = copy._name;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Frag: Default destructor called" << std::endl;
}

FragTrap::FragTrap(std::string new_name): ClapTrap(new_name)
{
	std::cout << "Frag: Constructor called with name: " << _name << std::endl;
	fragStats();
}

void FragTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

void FragTrap::guardGate()
{
	std::cout << "FragTrap is now in Gate keeper mode!" << std::endl;
}

void FragTrap::fragStats()
{
	_hit_point = 100;
	_energy_point = 100;
	_attack_damage = 30;
}