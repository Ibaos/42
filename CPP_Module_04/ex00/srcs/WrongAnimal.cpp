/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:26:35 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/10 12:03:42 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& param): type(param.type)
{
	std::cout << "WrongAnimal: Default copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& param)
{
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		type = param.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Default destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Indistinguishable sound!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}
