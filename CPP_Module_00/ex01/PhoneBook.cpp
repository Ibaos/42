/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:12:12 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/06 11:47:12 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::print_contact(int index)
{
	if (index >= 0 && index < this->nbContacts && index < 8)
	{
		std::cout << this->Contact[index].getFirstName() << std::endl;
		std::cout << this->Contact[index].getLastName() << std::endl;
		std::cout << this->Contact[index].getNickname() << std::endl;
		std::cout << this->Contact[index].getPhoneNumber() << std::endl;
		std::cout << this->Contact[index].getDarkestSecret() << std::endl;
	}
}

int	PhoneBook::get_index(std::string str)
{
	std::string cmd;

	while (!std::cin.eof() && cmd.empty())
	{
		int index = -1;
		std::cout << str;
		std::getline(std::cin, cmd);
		if (cmd.length() == 1 && cmd.at(0) - 48 < this->nbContacts)
			index = cmd.at(0) - 48;
		if (index == -1 || index >= this->nbContacts || index >= 8)
			std::cout << "Ivalid index!" << std::endl;
		else
			return (index);
	}
	return (-1);
}

void	print_footer()
{
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void	PhoneBook::print_name(std::string str)
{
	for (int i = 0; i + str.length() < 10; i++)
		std::cout << " ";
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << str;
	std::cout << "|";
}

void	PhoneBook::print_body()
{
	for (int i = 0; i < this->nbContacts && i < 8; i++)
	{
		std::cout << "|         " << i << "|";
		print_name(this->Contact[i].getFirstName());
		print_name(this->Contact[i].getLastName());
		print_name(this->Contact[i].getNickname());
		std::cout << std::endl;
	}
}

void	print_header()
{
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void PhoneBook::search()
{
	std::string cmd;

	print_header();
	print_body();
	print_footer();
	print_contact(get_index("Enter an index: "));
		
}

std::string	get_value(std::string str)
{
	std::string cmd;

	while (!std::cin.eof() && cmd.empty())
	{
		std::cout << str;
		std::getline(std::cin, cmd);
	}
	return (cmd);	
}

void	PhoneBook::add()
{
	std::string	cmd;

	if (this->nbContacts >= 8)
		std::cout << "Contact list is full, new contact overwrite the oldest contact!" << std::endl;
	
	cmd = get_value("Enter contact first name: ");
	this->Contact[this->nbContacts % 8].setFirstName(cmd);
	cmd = get_value("Enter contact last name: ");
	this->Contact[this->nbContacts % 8].setLastName(cmd);
	cmd = get_value("Enter contact nickname: ");
	this->Contact[this->nbContacts % 8].setNickname(cmd);
	cmd = get_value("Enter contact phone number: ");
	this->Contact[this->nbContacts % 8].setPhoneNumber(cmd);
	cmd = get_value("Enter contact darkest secret: ");
	this->Contact[this->nbContacts % 8].setDarkestSecret(cmd);
	this->nbContacts++;
}
