#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	Zombie		*zombie;
	std::string	name;
	int			nbOfZombie;
	int			i;

	nbOfZombie = 0;
	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
	{
		std::cout << "WRONG ARGUMENTS" << std::endl;
		return (0);
	}
	while (argv[1][i])
	{
		if (!std::isdigit(argv[1][i]))
		{
			std::cout << "WRONG INPUT" << std::endl;
			return (0);
		}
		i++;
	}
	nbOfZombie = std::atoi(argv[1]);
	name = argv[2];
	zombie = zombieHorde(nbOfZombie, name);
	i = 0;
	while (i < nbOfZombie)
	{
		zombie[i].announce();
		i++;
	}
	delete [] zombie;
	return (0);
}