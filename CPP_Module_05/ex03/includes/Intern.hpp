#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		Intern& operator=(const Intern&);
		~Intern();
		AForm*	makeForm(std::string formName, std::string target);
		class	UnknownFormException: public std::exception { 
			virtual const char* what() const throw() { return "Unknown form!"; }
		};
};

#endif