#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen		Karen;
	std::string	level;

	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cout << "No complaint ? Enter one..." << std::endl;
		return (1);
	}
	level = argv[1];
	Karen.complain(level);
	return (0);
}