#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		bool		_isEquiped;
	public:
		AMateria();
		AMateria(const AMateria& param);
		AMateria& operator=(const AMateria& param);
		AMateria(std::string const & type);
		virtual ~AMateria();
		bool getIsEquiped() const;
		void setIsEquiped(bool isEquiped);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif