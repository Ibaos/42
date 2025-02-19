/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:54:21 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/12 16:38:35 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& param): Animal(param)
{
	std::cout << "Dog: Default copy constructor called" << std::endl;
	brain = new Brain(*param.brain);
}

Dog& Dog::operator=(const Dog& param)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		type = param.type;
		delete brain;
		brain = new Brain(*param.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor called" << std::endl;
	delete(this->brain);
	brain = NULL;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain*	Dog::getBrain()
{
	return (brain);
}


void	Dog::setBrain(unsigned int i, std::string new_idea)
{
	brain->setIdea(i, new_idea);
}

std::string	Dog::getIdea(unsigned int i)
{
	return (brain->getIdea(i));
}