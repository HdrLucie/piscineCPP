#ifndef	INTERN_HPP
# define INTERN_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class	AForm;
class	Intern;

typedef	AForm* (Intern::*moldForm)(const std::string&);

class	Intern {

private : 
	AForm	*makeShrubberyForm(std::string const &target);
	AForm	*makePresidentialForm(std::string const &target);
	AForm	*makeRobotomyForm(std::string const &target);

	static	moldForm	form[3];
public :
	Intern(void);
	Intern(const Intern &copy);
	Intern &operator=(const Intern &rhs);
	virtual ~Intern(void);

	AForm	*makeForm(std::string const &nameForm, std::string const &target);
};

#endif