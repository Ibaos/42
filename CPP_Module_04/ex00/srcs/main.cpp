/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:11:48 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/13 14:48:36 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog Dogmatix;
	Dog Snoop(Dogmatix);
	Animal Rintincan;

	Cat Soki;
	Cat	Pink(Soki);
	std::cout << std::endl;

	Dogmatix.makeSound();
	Snoop.makeSound();
	Soki.makeSound();
	Pink.makeSound();
	Rintincan.makeSound();
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	const WrongAnimal* metttttaaaa = new WrongAnimal();
	const WrongAnimal* iiiiii = new WrongCat();
	std::cout << iiiiii->getType() << " " << std::endl;
	iiiiii->makeSound();
	metttttaaaa->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete metttttaaaa;
	delete iiiiii;
	return (0);
}
