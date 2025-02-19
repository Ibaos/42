#include "Form.hpp"

Form::Form(): _name("randomForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	//std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(std::string name): _name(name), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	//std::cout << "Form: Parameter constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	//std::cout << "Form: Parameter constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw GradeTooLowException();
	}
	else if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw GradeTooHighException();
	}
}

Form::Form(const Form& param): _name(param._name), _isSigned(param._isSigned), _gradeToSign(param._gradeToSign), _gradeToExecute(param._gradeToExecute)
{
	//std::cout << "Form: Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& param)
{
	//std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &param)
	{
		_isSigned = param._isSigned;
	}
	return (*this);
}

Form::~Form()
{
	//std::cout << "Form: Default destructor called" << std::endl;
}

const std::string	Form::getName() const
{
	return (_name);
}

bool				Form::getIsSigned() const
{
	return (_isSigned);
}

unsigned int		Form::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int		Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void				Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	if (_isSigned)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << _name << " because the form is already signed" << std::endl;
		throw FormAlreadySigned();
	}
	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &right_value)
{
	os << "Form: " << right_value.getName() << " is ";
	if (right_value.getIsSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires a grade of " << right_value.getGradeToSign() << " to be signed and a grade of " << right_value.getGradeToExecute() << " to be executed!" << std::endl;
	return (os);
}
