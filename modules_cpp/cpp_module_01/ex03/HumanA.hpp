#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string Type, Weapon &Weapon);
		~HumanA();
		void	attack(); 
		void	setWeapon(Weapon &Weapon);
	private:
		std::string	nameA;
		Weapon	 	*weaponA;
};

#endif