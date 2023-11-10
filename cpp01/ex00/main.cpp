#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie;

	std::cout << "With function newZombie" << std::endl;
	zombie = newZombie("Michael");
	zombie->announce();
	delete zombie;

	std::cout << "With function randomChump" << std::endl;
	randomChump("Dwight");
	return (0);
}