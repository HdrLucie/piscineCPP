#include "Bureaucrat.hpp"
#include <climits>

void	fifthTest(void)
{
	try {

		Bureaucrat	b("Jim", INT_MIN);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;		
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	fourthTest(void)
{
	try {

		Bureaucrat	b("Kelly", INT_MAX);
		std::cout << b  << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;		
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	thirdTest(void)
{
	try {

		Bureaucrat	b("Pam", 110);

		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void	secondTest(void)
{
	try {

		Bureaucrat	b("Michael", 1);

		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception const &e) {

		std::cerr << e.what() << std::endl;
	}
	return ;
}

void	firstTest(void)
{
	try {
		
		Bureaucrat  b("Dwight", 22);

		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
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
	secondTest();
	thirdTest();
	fourthTest();
	fifthTest();
	return (0);
}