#include "Form.hpp"

Form::Form(std::string const &name, bool isSigned, int const toSign, int const toExecute) : 
	_name(name), _isSigned(isSigned), 
	_gradeToSign(toSign), _gradeToExecute(toExecute)
{
	if (MSG)
		std::cout << "Form constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::gradeFormTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::gradeFormTooLowException();
	return ;
}

Form::Form(const Form &copy) : 
	_name(copy._name), _isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	if (MSG)
		std::cout << "Form copy constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::gradeFormTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToExecute > 150)
		throw Form::gradeFormTooLowException();
	return ;
}

Form	&Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

Form::~Form(void)
{
	if (MSG)
		std::cout << "Form destructor called" << std::endl;
	return ;
}

const std::string	&Form::getName(void) const 
{
	return (this->_name);
}

const bool	&Form::getIsSigned(void)
{
	return (this->_isSigned);
}

const int	&Form::getToExecute(void) const
{
	return (this->_gradeToExecute);
}

const int	&Form::getToSign(void) const
{
	return (this->_gradeToSign);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw Form::isAlreadySigned();
	else if (bureaucrat.getGrade() > this->getToSign())
		throw Bureaucrat::gradeTooLowException();
	else
		this->_isSigned = 1;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "\n- - - - - - - - - - - - - - -\nINFORMATIONS FORM\n" << std::endl
	<< "name: " << rhs.getName() << std::endl
	<< "grade to sign : " << rhs.getToSign() << std::endl
	<< "grade to execute : " << rhs.getToExecute() << std::endl;
	return o;
}

/**************
 * EXCEPTIONS *
 **************/

const char *Form::gradeFormTooHighException::what(void) const throw()
{
	return ("Grade form you set is too high.");	
}

const char *Form::gradeFormTooLowException::what(void) const throw()
{
	return ("Grade form you set is too low.");
}

const char *Form::isAlreadySigned::what(void) const throw()
{
	return ("Form is already signed.");
}