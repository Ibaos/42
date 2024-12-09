#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &paste);
		FragTrap &operator=(const FragTrap &right_value);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys();
	private:
};

#endif