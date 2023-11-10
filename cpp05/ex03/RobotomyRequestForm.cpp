#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : 
AForm("Robotomy Request Form", 0, 72, 45), _target(target)
{
	if (MSG)
		std::cout << "Robotomy Request constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
AForm(copy), _target(copy._target)
{
	if (MSG)
		std::cout << "Robotomy request copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (MSG)
		std::cout << "Robotomy Request destructor called" << std::endl;
	return ;
}

std::string	const &RobotomyRequestForm::getTarget(void) const 
{
	return (this->_target);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
		throw RobotomyRequestForm::isAlreadySigned();
	else if (bureaucrat.getGrade() > this->getToSign())
		throw Bureaucrat::gradeTooLowException();
	else
		this->setStatusForm(1);
	return ;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor)
{
	if (this->getIsSigned() != 1)
		throw RobotomyRequestForm::isNotSignedException();
	else if (executor.getGrade() > this->getToExecute())
		throw Bureaucrat::gradeTooLowException();
	else
	{
        if (std::rand() % 2)
        {
            std::cout << "*Drilling noises...* Oh... Am I at the dentist ? Oh.. God, no !!!! " << std::endl
            << this->getTarget() << " has been successfully robotomized !" << std::endl;
        }
        else
            std::cout << "Robotomy failed. Come another day." << std::endl;
    }
	return ;
}