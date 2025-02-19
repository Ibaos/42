#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice&);         
		Ice& operator=(const Ice&);
		~Ice();

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif