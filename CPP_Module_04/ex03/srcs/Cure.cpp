/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:33:41 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/10 14:07:55 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	//std::cout << "Cure: Default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& param)
{
	//std::cout << "Cure: Default copy constructor called" << std::endl;
	_type = param._type;
}

Cure& Cure::operator=(const Cure& param)
{
	//std::cout << "Cure: Copy assignment operator called" << std::endl;
	_type = param._type;
	return (*this);
}

Cure::~Cure()
{
	//std::cout << "Cure: Default destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	//std::cout << "Cure: Clone called" << std::endl;
	return (new Cure());
}
