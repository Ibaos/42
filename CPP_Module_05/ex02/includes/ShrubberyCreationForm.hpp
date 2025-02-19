#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
};

#endif