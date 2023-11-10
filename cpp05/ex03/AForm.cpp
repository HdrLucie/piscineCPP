#include "AForm.hpp"

AForm::AForm(std::string const &name, bool isSigned, int const toSign, int const toExecute) : 
	_name(name), _isSigned(isSigned), 
	_gradeToSign(toSign), _gradeToExecute(toExecute)
{
	if (MSG)
		std::cout << "AForm constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw AForm::gradeFormTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw AForm::gradeFormTooLowException();
	return ;
}

AForm::AForm(const AForm &copy) : 
	_name(copy._name), _isSigned(copy._isSigned),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	if (MSG)
		std::cout << "AForm copy constructor called" << std::endl;
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw AForm::gradeFormTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToExecute > 150)
		throw AForm::gradeFormTooLowException();
	return ;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::~AForm(void)
{
	if (MSG)
		std::cout << "AForm destructor called" << std::endl;
	return ;
}

const std::string	&AForm::getName(void) const 
{
	return (this->_name);
}

const bool	&AForm::getIsSigned(void)
{
	return (this->_isSigned);
}

const int	&AForm::getToExecute(void) const
{
	return (this->_gradeToExecute);
}

const int	&AForm::getToSign(void) const
{
	return (this->_gradeToSign);
}

void	AForm::setStatusForm(const int status)
{
	this->_isSigned = status;
	return ;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned)
		throw AForm::isAlreadySigned();
	else if (bureaucrat.getGrade() > this->getToSign())
		throw Bureaucrat::gradeTooLowException();
	else
		this->_isSigned = 1;
	return ;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << "AForm" << std::endl
	<< "name: " << rhs.getName() << std::endl
	<< "grade to sign : " << rhs.getToSign() << std::endl
	<< "grade to execute : " << rhs.getToExecute() << std::endl;
	return o;
}

/**************
 * EXCEPTIONS *
 **************/

const char *AForm::gradeFormTooHighException::what(void) const throw()
{
	return ("Grade form you set is too high.");	
}

const char *AForm::gradeFormTooLowException::what(void) const throw()
{
	return ("Grade form you set is too low.");
}

const char *AForm::isAlreadySigned::what(void) const throw()
{
	return ("Form is already signed.");
}

const char *AForm::isNotSignedException::what(void) const throw()
{
	return ("can't execute because form isn't signed");
}