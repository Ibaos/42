/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:54:24 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 18:08:39 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal& param): type("animal")
{
	(void)param;
	std::cout << "Animal: Default copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& param)
{
	std::cout << "Animal: Copy assignment operator called" << std::endl;
	if (this != &param)
	{

	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Default destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Indistinguishable sound!" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}
