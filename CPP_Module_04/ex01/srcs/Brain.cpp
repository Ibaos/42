/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:05:54 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/12 16:38:05 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& param)
{
	std::cout << "Brain: Default copy constructor called" << std::endl;
	*this = param;
}

Brain& Brain::operator=(const Brain& param)
{
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = param.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: Default destructor called" << std::endl;
}

void	Brain::setIdea(unsigned int i, std::string new_idea)
{
	ideas[i] = new_idea;
}

std::string	Brain::getIdea(unsigned int i)
{
	return (ideas[i]);
}