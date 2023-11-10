#include "Span.hpp"
#include <time.h>
#include <stdlib.h>
#include <list>

int main(void)
{
	{
		Span    span(4);
	
		try 
		{
			std::cout << RED << "\nBasic test" << NC << std::endl;
			span.addNumber(-10);
			span.addNumber(2);
			span.addNumber(-35);
			span.addNumber(1);
			std::cout << span << std::endl;
			std::cout << CYN << "longest span : " << NC << span.longestSpan() << std::endl;
			std::cout << CYN << "shortest span : " << NC << span.shortestSpan() << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span    span(1);
	
		try 
		{
			std::cout << RED << "\nNo span possible" << NC << std::endl;
			span.addNumber(-10);
			std::cout << span << std::endl;
			std::cout << CYN << "longest span : " << NC << span.longestSpan() << std::endl;
			std::cout << CYN << "shortest span : " << NC << span.shortestSpan() << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span span(5);
		try
		{
			std::cout << RED << "\nTest to much numbers" << NC << std::endl;
			int myints[] = {16,2,77,28,10,57,78};
			std::vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );	
			span.addNumbers(v1.begin(), v1.end());
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span	span(10);
		try 
		{
			std::cout << RED << "\nTest with addNumberS" << NC << std::endl;
			int myints[] = {16,2,77,28,10,57,78};
			std::vector<int> v1 (myints, myints + sizeof(myints) / sizeof(int) );	
			span.addNumbers(v1.begin(), v1.end());
			std::cout << span << std::endl;
			int	listNumbers[3] = {-34, 5, 0};
			std::list<int>	listInt(listNumbers, listNumbers + sizeof(listNumbers) / sizeof(int));
			span.addNumbers(listInt.begin(), listInt.end());
			std::cout << span << std::endl;
			std::cout << CYN << "longest span : " << NC << span.longestSpan() << std::endl;
			std::cout << CYN << "shortest span : " << NC << span.shortestSpan() << NC << std::endl;
			int myints3[] = {-11};
  			std::vector<int> v3 (myints3, myints3 + sizeof(myints3) / sizeof(int) );	
			span.addNumbers(v3.begin(), v3.end());
			std::cout << span << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << RED << "\nTest with 10 000 values\n" <<  NC << std::endl;
		Span span(10000);
		try 
		{
			srand(time(NULL));
			for (unsigned int i = 0; i < 10000; i++)
			{
				unsigned int value = rand() % 100000;
				span.addNumber(value);
			}
			std::cout << span << std::endl;
			std::cout << CYN << "longest span : " << NC << span.longestSpan() << std::endl;
			std::cout << CYN << "shortest span : " << NC << span.shortestSpan() << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}