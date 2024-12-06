/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:54:23 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 18:18:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& param): Animal(param)
{
	type = param.type;
	std::cout << "Cat: Default copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& param)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &param)
	{

	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
