/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/31 12:07:16 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "Test 1: Shrubbery" << std::endl;
	{
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
			Bureaucrat bob(1, "Bob");
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Test 2: Robotomy" << std::endl;
	{
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			Bureaucrat bob(1, "Bob");
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Test 3: Presidential Pardon" << std::endl;
	{
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("presidential request", "Bender");
			Bureaucrat bob(1, "Bob");
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Test 4: Unknown form" << std::endl;
	{
		try {
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("UnknownForm", "Bender");
			Bureaucrat bob(1, "Bob");
			bob.signForm(*rrf);
			bob.executeForm(*rrf);
			if (rrf)
				delete rrf;
		}
		catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
