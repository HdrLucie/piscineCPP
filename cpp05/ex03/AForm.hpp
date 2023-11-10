#ifndef AFORM_HPP
# define AFORM_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {

private :

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public :

	AForm(std::string const &name = std::string("Dwight"), bool isSigned = 0, int const toSign = 150, int const toExecute = 150);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm(void);

	virtual void		beSigned(const Bureaucrat &bureaucrat) = 0;
	virtual void		execute(const Bureaucrat &executor) = 0;
	
	const std::string	&getName(void) const;
	const bool			&getIsSigned(void);
	const int			&getToSign(void) const;
	const int			&getToExecute(void) const;

	void				setStatusForm(const int status);

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
	class	isNotSignedException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif