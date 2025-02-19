#include "Intern.hpp"

Intern::Intern()
{
	//std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern(const Intern& param)
{
	//std::cout << "Intern: Copy constructor called" << std::endl;
	(void)param;
}

Intern& Intern::operator=(const Intern& param)
{
	//std::cout << "Intern: Copy assignment operator called" << std::endl;
	if (this != &param)
		(void)param;
	return (*this);
}

Intern::~Intern()
{
	//std::cout << "Intern: Default destructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string	defaultFormName[3] = {"shrubbery request", "robotomy request", "presidential request"};
	AForm*	(*_formCreators[3])(std::string) = {ShrubberyCreationForm::create, RobotomyRequestForm::create, PresidentialPardonForm::create};
	for (int i = 0; i < 3; i++)
	{
		if (formName == defaultFormName[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (_formCreators[i](target));
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	throw Intern::UnknownFormException();
}
