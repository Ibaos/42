/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:02:38 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/10 18:27:04 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& param)
{
	//std::cout << "MateriaSource: Default copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (param.learned[i] != NULL)
			learned[i] = param.learned[i]->clone();
		else
			learned[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& param)
{
	//std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		for (int i = 0; i < 4; i++)
		{
			if (learned[i] != NULL)
				delete learned[i];
			if (param.learned[i] != NULL)
				learned[i] = param.learned[i]->clone();
			else
				learned[i] = NULL;
		}
	}
	return (*this);
}


MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource: Default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] != NULL)
			delete learned[i];
	}
}

void MateriaSource::learnMateria(AMateria* new_materia)
{
	if (new_materia == NULL)
	{
		std::cout << "MateriaSource: Can't learn a NULL materia!" << std::endl;
		return ;
	}	
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] == new_materia)
		{
			std::cout << "MateriaSource: Already learned this specific materia!" << std::endl;
			return ;
		}
		if (learned[i] == NULL)
		{
			learned[i] = new_materia;
			std::cout << "MateriaSource: Learned " << new_materia->getType() << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource: No space to learn a new materia!" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] != NULL && learned[i]->getType() == type)
			return (learned[i]->clone());
	}
	std::cout << "MateriaSource: Can't create a materia of type " << type << " because it was not learned!" << std::endl;
	return (0);
}
