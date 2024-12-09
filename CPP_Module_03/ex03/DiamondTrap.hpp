#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &paste);
		DiamondTrap &operator=(const DiamondTrap &right_value);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();
	private:
		std::string _name;
};

#endif