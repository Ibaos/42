/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/13 14:05:36 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	std::cout << std::endl << std::endl << "		Subject tests" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << std::endl << "		Multiple assignation of the same materia" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp = new Ice;
		src->learnMateria(tmp);
		src->learnMateria(tmp);
		src->learnMateria(tmp);
		delete src;
	}

	std::cout << std::endl << std::endl << "		Multiple assignation of differents materias" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* ice = new Ice;
		src->learnMateria(new Cure);
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		src->learnMateria(new Cure);
		src->learnMateria(ice);
		delete ice;
		delete src;
	}

	std::cout << std::endl << std::endl << "		Character equiping more than 4 materias" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		ICharacter* me = new Character("me");
		AMateria* ice;
		AMateria* cure;
		ice = src->createMateria("ice");
		cure = src->createMateria("cure");
		me->equip(new Ice);
		me->equip(new Cure);
		me->equip(new Ice);
		me->equip(new Cure);
		me->equip(ice);
		me->equip(cure);
		me->use(0, *me);
		me->use(1, *me);
		me->use(2, *me);
		me->use(3, *me);
		delete me;
		delete src;
		delete ice;
		delete cure;
	}

	std::cout << std::endl << std::endl << "		Equip same materia on two characters" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		ICharacter* me = new Character("me");
		ICharacter* him = new Character("him");
		AMateria* ice = src->createMateria("ice");
		me->equip(ice);
		him->equip(ice);
		
		delete me;
		delete him;
		delete src;
	}

	std::cout << std::endl << std::endl << "		Show inventory" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);
		src->learnMateria(new Cure);
		ICharacter* me = new Character("me");

		AMateria* ice = src->createMateria("ice");
		me->showInventory();
		std::cout << std::endl;
		me->equip(ice);
		me->equip(new Cure);
		me->equip(new Ice);
		me->equip(new Cure);
		me->showInventory();
		std::cout << std::endl;
		me->unequip(0);
		me->unequip(0);
		me->unequip(5);
		me->use(0, *me);
		me->showInventory();
		std::cout << std::endl;
		delete ice;
		delete me;
		delete src;
	}

	std::cout << std::endl << std::endl << "		Deep copy" << std::endl << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice);

		AMateria *tmp = src->createMateria("ice");

		Character Charlie("Charlie");
		Character bob("bob");

		std::cout << std::endl << "\033[1mCharlie: \033[0m" << std::endl;
		Charlie.showInventory();
		std::cout << std::endl << "\033[1mBob: \033[0m" << std::endl;
		bob.showInventory();

		Charlie.equip(tmp);

		std::cout << std::endl << "\033[1mCharlie: \033[0m" << std::endl;
		Charlie.showInventory();
		std::cout << std::endl << "\033[1mBob: \033[0m" << std::endl;
		bob.showInventory();

		bob = Charlie;

		std::cout << std::endl << "\033[1mCharlie: \033[0m" << std::endl;
		Charlie.showInventory();
		std::cout << std::endl << "\033[1mBob: \033[0m" << std::endl;
		bob.showInventory();

		delete src;
		std::cout << std::endl << std::endl;
	}
	return 0;
}
