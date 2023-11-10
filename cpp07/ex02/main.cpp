#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "testClass.hpp"

#define MAX_VAL 10

int main (void)
{
	Array<int> 			intTab(5);
	Array<int> 			copyTab(intTab);
	Array<std::string>	emptyArray;
	Array<int>			test(0);
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		const int value = rand();
		intTab[i] = value;
		copyTab[i] = value;
	}
	for (unsigned int i = 0; i < intTab.size(); i++)
		std::cout << "intTab[i] : " << intTab[i] << " | Copy[i] : " << copyTab[i] << std::endl;
	try {
		
		std::cout << "Try change index" << std::endl;
		intTab[6] = 12;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << std::endl;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	return (0);
}