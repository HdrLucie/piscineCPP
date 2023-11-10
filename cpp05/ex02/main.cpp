#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "limits"

void	thirdTest(void)
{
	try {

		Bureaucrat	b("Kelly", 46);
		RobotomyRequestForm	f("Andy");
		
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		b.incrementGrade();
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void    secondTest(void)
{
	try {

		Bureaucrat	b("Michael", 1);
		ShrubberyCreationForm	f("Shrubbery Creation Form");
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		b.decrementGrade();
		b.signForm(f);		
	}
	catch (std::exception const &e) {

		std::cerr << e.what() << std::endl;
	}
	return ;
}

void    firstTest(void)
{
	try {
		Bureaucrat  b("Dwight", 6);
		PresidentialPardonForm	f("Michael");
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);		
		b.incrementGrade();
		b.signForm(f);
		b.executeForm(f);
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
	return (0);
}