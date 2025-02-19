#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character();
		Character(const Character&);
		Character(const std::string new_name);
		Character& operator=(const Character&);
		~Character();
		void showInventory();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
    private:
		std::string	_name;
		AMateria *_inventory[4];
};

#endif