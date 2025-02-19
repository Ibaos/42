/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/31 12:17:09 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "Test 1: Shrubbery" << std::endl;
	try {
		Bureaucrat	bob(1, "Bob");
		ShrubberyCreationForm	tree = ShrubberyCreationForm("home");
		tree.beSigned(bob);
		bob.executeForm(tree);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 2: Robotomy" << std::endl;
	try {
		Bureaucrat	bob(1, "Bob");
		RobotomyRequestForm	robot = RobotomyRequestForm("Bob");
		robot.beSigned(bob);
		bob.executeForm(robot);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test 3: Presidential Pardon" << std::endl;
	try {
		Bureaucrat	bob(1, "Bob");
		PresidentialPardonForm	pardon = PresidentialPardonForm("Bob");
		pardon.beSigned(bob);
		bob.executeForm(pardon);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
