#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure&);         
		Cure& operator=(const Cure&);
		~Cure();
	
		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif