#include "Base.hpp"

int	main(void)
{
	Base	*ptr;

	ptr = generate();
	if (ptr == NULL)
		std::cout << "Class not instantiated" << std::endl;
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}