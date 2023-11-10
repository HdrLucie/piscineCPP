#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	PresidentialPardonForm : public AForm {

private :
	std::string	_target;

public : 
	PresidentialPardonForm(std::string const &target = std::string("defaultTarget"));
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm  &operator=(const PresidentialPardonForm &rhs);
	virtual ~PresidentialPardonForm(void);

	std::string const	&getTarget(void) const;
	virtual void		beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor);
};

#endif