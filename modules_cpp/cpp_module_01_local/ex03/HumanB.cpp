/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:23:12 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/15 14:07:00 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weaponB = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weaponB->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weaponB = &weapon;
}
