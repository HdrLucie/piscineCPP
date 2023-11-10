#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class	Form;

class	Bureaucrat {

private :
	const std::string	_name;
	int					_grade;

public :
	Bureaucrat(std::string const &name = std::string("Dwight"), int const grade = 150);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat	&operator=(const Bureaucrat &rhs);
	virtual ~Bureaucrat(void);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;

	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form &formulaire) const;
	
	class	gradeTooHighException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
	
	class gradeTooLowException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif