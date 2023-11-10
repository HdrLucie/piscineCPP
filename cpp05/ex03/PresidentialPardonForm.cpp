#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : 
AForm("Presidential Pardon Form", 0, 25, 5), _target(target)
{
	if (MSG)
		std::cout << "Presidential pardon constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
AForm(copy), _target(copy._target)
{
	if (MSG)
		std::cout << "Presidential pardon copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (MSG)
		std::cout << "Presidential Pardon destructor called" << std::endl;
	return ;
}

std::string	const &PresidentialPardonForm::getTarget(void) const 
{
	return (this->_target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
		throw PresidentialPardonForm::isAlreadySigned();
	else if (bureaucrat.getGrade() > this->getToSign())
		throw Bureaucrat::gradeTooLowException();
	else
		this->setStatusForm(1);
	return ;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor)
{
	if (this->getIsSigned() != 1)
		throw PresidentialPardonForm::isNotSignedException();
	else if (executor.getGrade() > this->getToExecute())
		throw Bureaucrat::gradeTooLowException();
	else
		std::cout << this->_target << " have been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}