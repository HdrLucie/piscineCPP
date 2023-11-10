#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie  *zombie;
	int		i;

	i = 0;
	zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		i++;
	}
	return (zombie);
}