#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(unsigned int grade);
		Bureaucrat(unsigned int grade, std::string name);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm& form);
		class			GradeTooHighException: public std::exception { 
			virtual const char* what() const throw() { return "Grade too high!"; }
			};
		class			GradeTooLowException: public std::exception { 
			virtual const char* what() const throw() { return "Grade too low!"; }
			};
		void	executeForm(AForm const & form);
	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &right_value);

#endif