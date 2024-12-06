/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:22:44 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/16 13:53:11 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "New zombie \"" << this->name << "\" created." << std::endl;
}

Zombie::Zombie()
{
	this->name = "NULL";
	std::cout << "New zombie created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie \"" << this->name << "\" destroyed." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
