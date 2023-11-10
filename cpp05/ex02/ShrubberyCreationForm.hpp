#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	ShrubberyCreationForm : public AForm {

private :
	std::string	_target;

public : 
	ShrubberyCreationForm(std::string const &target = std::string("defaultTarget"));
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &rhs);
	virtual ~ShrubberyCreationForm(void);

	std::string const	&getTarget(void) const;
	virtual void		beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor);
};

#endif