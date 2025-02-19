#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	//std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	//std::cout << "RobotomyRequestForm: Parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& param): AForm(param)
{
	//std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& param)
{
	//std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		AForm::operator=(param);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm: Default destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "* drilling noises *" << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
