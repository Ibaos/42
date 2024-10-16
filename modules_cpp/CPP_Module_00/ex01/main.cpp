/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:13:19 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/10 12:01:53 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;

	while (42)
	{
		std::string	cmd;
	
		while (!std::cin.eof() && cmd.empty())
		{
			std::cout << "Please enter a command: ";
			std::getline(std::cin, cmd);
		}
		if (cmd == "EXIT")
			break ;
		else if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
