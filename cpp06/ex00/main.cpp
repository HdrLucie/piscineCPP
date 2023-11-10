#include "Conversion.hpp"
#include <iostream>
#include <limits>
#include <cctype>
#include <string>

int	checkInput(char *str)
{
	std::string	input;
	size_t		sizeInput;
	std::string	weirdInputs [6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int	counter;

	input = str;
	sizeInput = input.size();	
	counter = 0;
	if (input.size() == 0)
		return (1);
	for (int i = 0; i < 6; i++)
		if (input == weirdInputs[i])
			return (0);
	if (sizeInput == 1 && std::isprint(input[0]))
		return (0);
	for (size_t i = 0; i < sizeInput; i++)
	{
		if (input[i] == '-' || input[i] == '+')
			counter++;
		if (counter > 1)
			return (1);
	}
	counter = 0;
	for (size_t i = 0; i < sizeInput; i++)
	{
		if (input[i] == '.')
			counter++;
		if (counter > 1 || input[0] == '.')
			return (1);
	}
	counter = 0;
	for (size_t i = 0; i < sizeInput; i++)
	{
		if ((std::isalpha(input[i]) && input[i] != 'f' && input[i] != '.'
			&& input[i] != '-' && input[i] != '+'))
			counter++;
		if (counter >= 1 || (input[i] == 'f' && i != sizeInput - 1))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	input;
	if (argc != 2)
	{
		std::cout << "Wrong number of args" << std::endl;
		return (1);
	}
	else if (checkInput(argv[1]))
	{
		std::cout << "Wrong input format" << std::endl;
		return (1);
	}
	else
	{
		input = argv[1];
		Conversion conversion(input);
		conversion.printConvert();
	}
	return (0);
}