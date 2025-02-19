#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);         
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
    private:
		AMateria *learned[4];
};

#endif