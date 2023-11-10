#include "easyfind.hpp"
#include <list>
#include <queue>
#include <time.h>

int main(void)
{
	{
		std::cout << "test with queue" << std::endl;

		std::deque<int> queueInt(3, 100);
		try
		{
			std::cout << ::easyfind(queueInt, 100) << std::endl;
			std::cout << ::easyfind(queueInt, 45) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl; 
		}
	}

	{
		std::cout << "Test with list" << std::endl;

		int				listNumbers[10] = {-34, 5, 0, 29, 32, 4, 1212, 4354, 97, 176};
		std::list<int>	listInt(listNumbers, listNumbers + sizeof(listNumbers) / sizeof(int));
		try 
		{
			std::cout << ::easyfind(listInt, 5) << std::endl;
			std::cout << ::easyfind(listInt, 343) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}