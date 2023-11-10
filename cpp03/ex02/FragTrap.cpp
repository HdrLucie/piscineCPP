#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor FragTrap called" << std::endl;

	this->_name = name;
	this->_lifePoints = 100;
	this->_energyPoints = 100;
	this->_attackDG = 30;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Default destructor FragTrap called" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	this->_name = copy._name;
	this->_lifePoints = copy._lifePoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDG = copy._attackDG;
	return ;
}

FragTrap & FragTrap::operator=(const FragTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_lifePoints = rhs._lifePoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDG = rhs._attackDG;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Give me high fives !" << std::endl;
}