/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:11:48 by bhumeau           #+#    #+#             */
/*   Updated: 2024/12/05 18:28:47 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog oui;
	Dog non(oui);
	Animal pouet;

	Cat Soki;
	Cat	nous;

	std::cout << std::endl;
	oui.makeSound();
	non.makeSound();
	Soki.makeSound();
	nous.makeSound();
	pouet.makeSound();
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << std::endl;
	const WrongAnimal* metttttaaaa = new WrongAnimal();
	const WrongAnimal* iiiiii = new WrongCat();
	std::cout << iiiiii->getType() << " " << std::endl;
	iiiiii->makeSound(); //will output the cat sound!
	metttttaaaa->makeSound();

	return (0);
}
