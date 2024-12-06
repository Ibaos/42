#ifndef	PHONEBOOK_HPP
# define	PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{
	private:
		Contact	Contact[8];
		int		nbContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		void	search();
		void	print_body();
		void	print_name(std::string str);
		int		get_index(std::string str);
		void	print_contact(int index);
};

#endif