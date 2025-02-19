#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	//std::cout << "Ice: Default constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& param)
{
	//std::cout << "Ice: Default copy constructor called" << std::endl;
	_type = param._type;
}

Ice& Ice::operator=(const Ice& param)
{
	//std::cout << "Ice: Copy assignment operator called" << std::endl;
	_type = param._type;
	return (*this);
}

Ice::~Ice()
{
	//std::cout << "Ice: Default destructor called" << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	//std::cout << "Ice: Clone called" << std::endl;
	return (new Ice());
}
