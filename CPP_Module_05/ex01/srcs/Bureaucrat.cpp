#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("Unnamed"), _grade(150)
{
	//std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade): _name("Unnamed"), _grade(grade)
{
	//std::cout << "Bureaucrat: Constructor with grade called" << std::endl;
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
	
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string name): _name(name), _grade(grade)
{
	//std::cout << "Bureaucrat: Constructor with grade and name called" << std::endl;
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& param): _name(param._name), _grade(param._grade)
{
	//std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& param)
{
	//std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		_grade = param._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat: Default destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.getIsSigned())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because the form is already signed." << std::endl;
		throw Form::FormAlreadySigned();
	}
	form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &right_value)
{
	os << right_value.getName() << ", bureaucrat grade " << right_value.getGrade();
	return (os);
}
