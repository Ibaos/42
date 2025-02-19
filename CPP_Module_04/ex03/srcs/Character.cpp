/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:33:24 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/13 14:00:47 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	//std::cout << "Character: Default constructor called" << std::endl;
	_name = "Unnamed";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& param)
{
	//std::cout << "Character: Default copy constructor called" << std::endl;
	_name = param.getName();
	for (int i = 0; i < 4; i++)
	{
		if (param._inventory[i] != NULL)
				_inventory[i] = param._inventory[i]->clone();
			else
				_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& param)
{
	//std::cout << "Character: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		_name = param.getName();
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (param._inventory[i] != NULL)
				_inventory[i] = param._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	//std::cout << "Character: Default destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character::Character(std::string new_name):  _name(new_name)
{
	//std::cout << "Character: Constructor with name called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Can't equip a NULL materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL && m->getIsEquiped() == false)
		{
			_inventory[i] = m;
			m->setIsEquiped(true);
			std::cout << "Equiped " << m->getType() << std::endl;
			return ;
		}
		if (_inventory[i] == NULL && m->getIsEquiped() == true)
		{
			std::cout << "This materia is already equiped!" << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Inventory number " << idx << " already empty!" << std::endl;
	}
	else
	{
		_inventory[idx]->setIsEquiped(false);
		_inventory[idx] = NULL;
		std::cout << "Unequiped inventory number " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Inventory number " << idx << " is empty!" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::showInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			std::cout << "Inventory slot " << i << ": " << _inventory[i]->getType() << std::endl;
			//std::cout << "Inventory slot " << i << ": " << _inventory[i] << std::endl;
		}
		else
			std::cout << "Inventory slot " << i << ": Empty" << std::endl;
	}
}