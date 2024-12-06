/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:25:36 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 18:29:14 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& param): WrongAnimal(param)
{
	type = param.type;
	std::cout << "WrongCat: Default copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& param)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	if (this != &param)
	{

	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
