#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	//std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	//std::cout << "PresidentialPardonForm: Parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& param): AForm(param)
{
	//std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& param)
{
	//std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		AForm::operator=(param);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm: Default destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

AForm*	PresidentialPardonForm::create(std::string target)
{
	return (new PresidentialPardonForm(target));
}