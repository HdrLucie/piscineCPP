#include "Bureaucrat.hpp"
#include "Form.hpp"

void	thirdTest(void)
{
	try {

		Bureaucrat	b("Kelly", 10);
		Form		f("Extra form", 0, 170, 0);
		
		std::cout << b << std::endl;
		std::cout << f << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void    secondTest(void)
{
	try {

		Bureaucrat	b("Michael", 1);
		Form		f("Nothing Important...", 0, 1, 1);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
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
		
		Bureaucrat  b("Dwight", 17);
		Form		f("paperForm", 0, 15, 10);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);		
		b.incrementGrade();
		b.signForm(f);
		b.incrementGrade();
		b.signForm(f);
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