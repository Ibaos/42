/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:11:48 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/13 14:33:06 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Dog Dogmatix;
	Dogmatix.setBrain(42, "The true answer!");
	Dog Snoop(Dogmatix);
	Dog Rintincan = Dogmatix;
	Cat	Soki;
	Soki.setBrain(42, "The true answer!");
	Cat	Pink(Soki);
	Cat	Orange = Soki;
	std::cout << std::endl;

	Dogmatix.makeSound();
	Snoop.makeSound();
	Rintincan.makeSound();
	std::cout << std::endl;

	Soki.makeSound();
	Pink.makeSound();
	Orange.makeSound();
	std::cout << std::endl;

	std::cout << Dogmatix.getIdea(42) << std::endl;
	std::cout << Snoop.getIdea(42) << std::endl;
	std::cout << Rintincan.getIdea(42) << std::endl;
	std::cout << std::endl;

	std::cout << Soki.getIdea(42) << std::endl;
	std::cout << Pink.getIdea(42) << std::endl;
	std::cout << Orange.getIdea(42) << std::endl;
	std::cout << std::endl;
	return (0);
}
