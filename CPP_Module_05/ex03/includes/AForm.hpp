#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		AForm(std::string name);
		AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

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
		class			FormNotSigned: public std::exception { 
			virtual const char* what() const throw() { return "Form needs to be signed to be executed!"; }
			};
		class			FileNotOpenException: public std::exception { 
			virtual const char* what() const throw() { return "File cannot be open!"; }
			};
		virtual void	execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string	_name;	
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &right_value);

#endif