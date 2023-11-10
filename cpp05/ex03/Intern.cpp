#include "Intern.hpp"

moldForm    Intern::form[3] = {
	&Intern::makeShrubberyForm,
	&Intern::makePresidentialForm,
	&Intern::makeRobotomyForm
};

Intern::Intern(void)
{
	if (MSG)
		std::cout << "Inter constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &copy)
{
	if (MSG)
		std::cout << "Intern copy constructor called" << std::endl;
	(void)copy;
	return ;
}

Intern  &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	if (MSG)
		std::cout << "Intern destructor called" << std::endl;
	return ;
}

AForm   *Intern::makeForm(std::string const &nameForm, std::string const &target)
{
	std::string name[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	
	for (int i = 0; i < 3; i++)
	{
		if (nameForm == name[i])
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return ((this->*form[i])(target));
		}
	}
	std::cout << "Wrong form input..." << std::endl;
	return (NULL);
}

AForm   *Intern::makeRobotomyForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm   *Intern::makePresidentialForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeShrubberyForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}