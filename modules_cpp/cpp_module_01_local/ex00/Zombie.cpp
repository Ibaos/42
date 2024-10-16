/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:22:44 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/11 17:46:23 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "New zombie \"" << this->name << "\" created" << std::endl;
}

Zombie::Zombie()
{
	this->name = "NULL";
	std::cout << "New zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is now really dead..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
