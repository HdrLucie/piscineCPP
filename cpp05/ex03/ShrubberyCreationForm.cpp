#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : 
AForm("Shrubbery Creation Form", 0, 145, 137), _target(target)
{
	if (MSG)
		std::cout << "Shrubbery Creation constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
AForm(copy), _target(copy._target)
{
	if (MSG)
		std::cout << "Shrubbery creation copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (MSG)
		std::cout << "Shrubbery Creation destructor called" << std::endl;
	return ;
}

std::string	const &ShrubberyCreationForm::getTarget(void) const 
{
	return (this->_target);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned())
		throw ShrubberyCreationForm::isAlreadySigned();
	else if (bureaucrat.getGrade() > this->getToSign())
		throw Bureaucrat::gradeTooLowException();
	else
		this->setStatusForm(1);
	return ;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	std::ofstream   ofs;
	std::string     filename;
	if (this->getIsSigned() != 1)
		throw ShrubberyCreationForm::isNotSignedException();
	else if (executor.getGrade() > this->getToExecute())
		throw Bureaucrat::gradeTooLowException();
	else
	{
		ofs.open(this->_target.append("_shrubbery").c_str(), std::ios::out | std::ios::app);
		if (ofs.is_open())
		{
			ofs << "                 # #### ####			" << std::endl;
        	ofs << "               ### \\/#|### |/####		" << std::endl;
        	ofs << "              ##\\/#/ \\||/##/_/##/_#	" << std::endl;
        	ofs << "            ###  \\/###|/ \\/ # ###	" << std::endl;
        	ofs << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        	ofs << "         ## #### # \\ #| /  #### ##/##	" << std::endl;
        	ofs << "          __#_--###`  |{,###---###-~	" << std::endl;
        	ofs << "                    \\ }{				" << std::endl;
        	ofs << "                     }}{				" << std::endl;
        	ofs << "                     }}{				" << std::endl;
        	ofs << "                     {{}				" << std::endl;
        	ofs << "               , -=-~{ .-^- _			" << std::endl;
		}
		ofs.close();
	}

	return ;
}