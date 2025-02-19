/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/30 13:54:06 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "Test 0: Operator << on a form" << std::endl;
	{
		Form	Important("Important Form", 1, 1);
		std::cout << Important << std::endl;
	}

	std::cout << std::endl << "Test 1: Sign twice the same form" << std::endl;
	{
		try {
			Bureaucrat Boss(1, "Boss");
			Form Important("Important Form", 1, 1);
			Important.beSigned(Boss);
			Important.beSigned(Boss);
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 1: " << e.what() << std::endl << std::endl;
		}
	}

	std::cout << std::endl << "Test 2: Sign a form with a too low grade" << std::endl;
	{
		try {
			Form Important("Important Form", 1, 1);
			Bureaucrat Employee(150, "Rookie");
			Important.beSigned(Employee);
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 2: " << e.what() << std::endl << std::endl;
		}
	}

	std::cout << std::endl << "Test 3: Copy a form" << std::endl;
	{
		try {
			Form Important("Important Form", 1, 1);
			Form Copy(Important);

			Bureaucrat Boss(1, "Boss");
			Copy.beSigned(Boss);
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 3: " << e.what() << std::endl << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "Test 4: Operator = on a form" << std::endl;
	{
		try {
			Form Important("Important Form", 1, 1);
			Form Copy("Copy Form", 150, 150);

			Bureaucrat Boss(1, "Boss");
			Copy.beSigned(Boss);
			Copy = Important;
			Copy.beSigned(Boss);
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 4: " << e.what() << std::endl << std::endl;
		}
	}
	return (0);
}
