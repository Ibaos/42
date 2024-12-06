#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class DiamondTrap: public ClapTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &paste);
		DiamondTrap &operator=(const DiamondTrap &right_value);
		~DiamondTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void whoAmI();
		void diamondStats();
	private:
		std::string _name;
};

#endif