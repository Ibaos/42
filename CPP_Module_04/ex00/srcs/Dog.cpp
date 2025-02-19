/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:54:21 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/10 13:05:49 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& param): Animal(param)
{
	std::cout << "Dog: Default copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& param)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		type = param.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
