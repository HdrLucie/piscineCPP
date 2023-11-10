#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void	fourthTest(void)
{
	try {

		Bureaucrat	bureaucrat("Michael", 70);
		Intern		intern;
		AForm		*form;

		form = intern.makeForm("fake form", "The Office");
		if (!form)
			return ;
		std::cout << form->getName() << std::endl;
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	thirdTest(void)
{
	try {

		Bureaucrat	bureaucrat("Michael", 46);
		Intern		intern;
		AForm		*form;

		form = intern.makeForm("robotomy request", "The Office");
		std::cout << form->getName() << std::endl;
		std::cout << bureaucrat << std::endl;
		if (form != NULL)
		{
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			bureaucrat.incrementGrade();
			bureaucrat.signForm(*form);
			delete form;
		}
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void    secondTest(void)
{
	try 
	{
		Bureaucrat	bureaucrat("Michael", 5);
		Intern		intern;
		AForm		*form;

		form = intern.makeForm("presidential pardon", "The Office");
		std::cout << form->getName() << std::endl;
		std::cout << bureaucrat << std::endl;
		if (form != NULL)
		{
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			bureaucrat.incrementGrade();
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception const &e) {

		std::cerr << e.what() << std::endl;
	}
	return ;
}

void    firstTest(void)
{

	try 
	{
		Bureaucrat	bureaucrat("Michael", 1);
		Intern		intern;
		AForm		*form;

		form = intern.makeForm("shrubbery creation", "maison");
		std::cout << bureaucrat << std::endl;
		if (form != NULL)
		{
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

int main(void)
{
	std::cout << "WELCOME TO THE OFFICE (that's what she said...)" << std::endl;
	firstTest();
	std::cout << "\n- - - - - - - - - - - - - - -\n" << std::endl;
	secondTest();
	std::cout << "\n- - - - - - - - - - - - - - -\n" << std::endl;
	thirdTest();
	std::cout << "\n- - - - - - - - - - - - - - -\n" << std::endl;
	fourthTest();
	return (0);
}