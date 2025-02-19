/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:54:23 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/13 14:31:50 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& param): Animal(param)
{
	std::cout << "Cat: Default copy constructor called" << std::endl;
	brain = new Brain(*param.brain);
}

Cat& Cat::operator=(const Cat& param)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		type = param.type;
		delete brain;
		brain = new Brain(*param.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor called" << std::endl;
	delete(this->brain);
	brain = NULL;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain*	Cat::getBrain()
{
	return (brain);
}

void	Cat::setBrain(unsigned int i, std::string new_idea)
{
	brain->setIdea(i, new_idea);
}

std::string	Cat::getIdea(unsigned int i)
{
	return (brain->getIdea(i));
}