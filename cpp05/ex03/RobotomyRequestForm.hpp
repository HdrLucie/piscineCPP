#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	RobotomyRequestForm : public AForm {

private :
	std::string	_target;

public : 
	RobotomyRequestForm(std::string const &target = std::string("defaultTarget"));
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm  &operator=(const RobotomyRequestForm &rhs);
	virtual ~RobotomyRequestForm(void);

	std::string const	&getTarget(void) const;
	virtual void		beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor);
};

#endif