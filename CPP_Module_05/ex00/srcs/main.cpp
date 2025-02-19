/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:54:17 by bhumeau           #+#    #+#             */
/*   Updated: 2025/01/24 14:52:43 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << std::endl << "Test 1: Grade from 150 to 1 to 150" << std::endl;
		try {
			Bureaucrat	bureaucrat(150);
			std::cout << bureaucrat << std::endl;
			for (int i = 0; i < 149; i++)
				bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			for (int i = 0; i < 149; i++)
				bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 1: " << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << std::endl << "Test 2: Grade too low" << std::endl;
		try {
			Bureaucrat	bureaucratTooLow(151);

		}
		catch (std::exception &e)
		{
			std::cout << "Throw 2: " << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << std::endl << "Test 3: Grade too high" << std::endl;
		try {
			Bureaucrat	bureaucratTooLow(0);

		}
		catch (std::exception &e)
		{
			std::cout << "Throw 3: " << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << std::endl << "Test 4: Copy constructor and copy assignment" << std::endl;
		try {
			Bureaucrat	Bobreaucrat(4, "Bob");
			Bureaucrat	BobFan(Bobreaucrat);
			Bureaucrat	BobLast;
			BobLast = BobFan;
			std::cout << Bobreaucrat << std::endl;
			std::cout << BobFan << std::endl;
			std::cout << BobLast << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 4: " << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << std::endl << "Test 5: Increment too high" << std::endl;
		try {
			Bureaucrat	bureaucrat(1, "Boss");
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 5: " << e.what() << std::endl << std::endl;
		}
	}

	{
		std::cout << std::endl << "Test 6: Decrement too low" << std::endl;
		try {
			Bureaucrat	bureaucrat(150, "Rookie");
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << "Throw 6: " << e.what() << std::endl << std::endl;
		}
	}

	std::cout << std::endl;
	return (0);
}
