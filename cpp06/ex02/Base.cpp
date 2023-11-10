#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Identify with reference" << std::endl;
	try
	{
		A& a = dynamic_cast<A &>(p);
		std::cout << "Actual type of the object is 'A'" << std::endl;
		(void)a;
	}
	catch (...)
	{
		try
		{
			B& b = dynamic_cast<B &>(p);
			std::cout << "Actual type of the object is 'B'" << std::endl;
			(void)b;
		}
		catch (...)
		{
			try
			{
				C& c = dynamic_cast<C &>(p);
				std::cout << "Actual type of the object is 'C'" << std::endl;
				(void)c;
			}
			catch (...)
			{
				std::cout << "Dynamic_cast failed" << std::endl;
			}
		}
	}	
}

void	identify(Base *p)
{
	std::cout << "Identify with pointer" << std::endl;
	if (A *a = dynamic_cast<A *>(p))
		std::cout << "Actual type of the object is 'A'" << std::endl;
	else if (B *b = dynamic_cast<B *>(p))
		std::cout << "Actual type of the object is 'B'" << std::endl;
	else if (C *c = dynamic_cast<C *>(p))
		std::cout << "Actual type of the object is 'C'" << std::endl;
	else
		std::cout << "Dynamic_cast failed" << std::endl;
	return ;
}

Base	*generate(void)
{
	int	valueTime;
	srand(time(NULL));

	valueTime = std::rand() % 3;
	if (valueTime == 0)
	{
		std::cout << "A is instantiated" << std::endl;
		return (new	A);
	}
	else if (valueTime == 1)
	{
		std::cout << "B is instantiated" << std::endl;
		return (new B);
	}
	else if (valueTime == 2)
	{
		std::cout << "C is instantiated" << std::endl;
		return (new C);
	}
	return (NULL);
}