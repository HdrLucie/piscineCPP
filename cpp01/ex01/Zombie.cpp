#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	Zombie::_name = name;
}

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Died again..." << std::endl;
	return ;
}