#include "Karen.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	Karen       Karen;
	std::string level;

	(void)argv;
	if (argc != 1)
		return (0);
	while (1)
	{
		std::getline(std::cin, level);
		if (std::cin.eof())
		    break ;
		if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		    std::cout << "Wrong level input !" << std::endl;
		if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
			Karen.complain(level);
	}
	return (0);
}