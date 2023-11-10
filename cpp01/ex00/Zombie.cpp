#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName()
{
	return (Zombie::_name);
}

Zombie::Zombie(std::string name)
{
	_name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead." << std::endl;
	return ;
}