#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
};

#endif