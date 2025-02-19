#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(std::string name);
		Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

		const std::string	getName() const;
		bool				getIsSigned() const;
		unsigned int		getGradeToSign() const;
		unsigned int		getGradeToExecute() const;
		void				beSigned(Bureaucrat& bureaucrat);
		class			GradeTooHighException: public std::exception { 
			virtual const char* what() const throw() { return "Grade too high!"; }
			};
		class			GradeTooLowException: public std::exception { 
			virtual const char* what() const throw() { return "Grade too low!"; }
			};
		class			FormAlreadySigned: public std::exception { 
			virtual const char* what() const throw() { return "Form is already signed!"; }
			};
	private:
		const std::string	_name;	
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &right_value);

#endif