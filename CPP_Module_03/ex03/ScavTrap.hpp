#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &paste);
		ScavTrap &operator=(const ScavTrap &right_value);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
	private:
};

#endif