#ifndef FORM_HPP
# define FORM_HPP

#ifndef MSG
# define MSG 0
#endif 

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

private :

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public :

	Form(std::string const &name = std::string("Dwight"), bool isSigned = 0, int const toSign = 150, int const toExecute = 150);
	Form(const Form &copy);
	Form &operator=(const Form &rhs);
	virtual ~Form(void);

	void		beSigned(const Bureaucrat &bureaucrat);
	const std::string	&getName(void) const;
	const bool			&getIsSigned(void);
	const int			&getToSign(void) const;
	const int			&getToExecute(void) const;

	class	gradeFormTooHighException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
	class	gradeFormTooLowException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
	class	isAlreadySigned : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif