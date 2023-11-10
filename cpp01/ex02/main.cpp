#include <iostream>

int main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string		&stringREF = string;

	std::cout << "The memory address of the string variable : " << &string << std::endl;
	std::cout << "The memory address of the string variable : " << &stringPTR << std::endl;
	std::cout << "The memory address of the string variable : " << &stringREF << std::endl;

	std::cout << "The memory address of the string variable : " << string << std::endl;
	std::cout << "The memory address of the string variable : " << *stringPTR << std::endl;
	std::cout << "The memory address of the string variable : " << stringREF << std::endl;
	return (0);
}