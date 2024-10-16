/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:22:04 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/15 14:04:36 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->nameA = name;
	this->weaponA = &weapon;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << this->nameA << " attacks with their " << weaponA->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->weaponA = &weapon;
}