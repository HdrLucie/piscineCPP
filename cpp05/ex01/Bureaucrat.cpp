#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, const int grade) : _name(name), _grade(grade)
{
	if (MSG)
		std::cout << "Bureaucrat constructor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::gradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::gradeTooLowException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	if (MSG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	if (MSG)
		std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int	&Bureaucrat::getGrade(void) const 
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "Incrementation " << std::endl;
	if (this->_grade == 1)
		throw Bureaucrat::gradeTooHighException();
	this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementation" << std::endl;
	if (this->_grade == 150)
		throw Bureaucrat::gradeTooLowException();
	this->_grade++;
	return ;
}

void	Bureaucrat::signForm(Form &formulaire) const
{
	try {

		formulaire.beSigned(*this);
		std::cout << this->getName() << " signed " << formulaire.getName() << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << this->getName() << " couldn't sign " << formulaire.getName() << " because : " << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "\n- - - - - - - -\n INFORMATIONS\n" << std::endl
	<< "name : " << rhs.getName() << std::endl
	<< "grade : " << rhs.getGrade() << std::endl;
	std::cout << "- - - - - - - -" << std::endl;
	return o;
}

/**************
 * EXCEPTIONS *
 **************/

const char *Bureaucrat::gradeTooHighException::what(void) const throw()
{
	return ("Grade you set is too high.");	
}

const char *Bureaucrat::gradeTooLowException::what(void) const throw()
{
	return ("Grade you set is too low.");
}