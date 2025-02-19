/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:02:44 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/10 14:02:26 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _isEquiped(false)
{
	//std::cout << "AMateria: Default constructor called" << std::endl;
	_type = "default";
}

AMateria::AMateria(const AMateria& param)
{
	//std::cout << "AMateria: Default copy constructor called" << std::endl;
	_type = param._type;
	_isEquiped = false;
}

AMateria& AMateria::operator=(const AMateria& param)
{
	//std::cout << "AMateria: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		_type = param._type;
		_isEquiped = false;
	}
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria: Default destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

bool AMateria::getIsEquiped() const
{
	return (_isEquiped);
}

void AMateria::setIsEquiped(bool isEquiped)
{
	_isEquiped = isEquiped;
}
