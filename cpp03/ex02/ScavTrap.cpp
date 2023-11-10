#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "Default constructor ScavTrap called" << std::endl;
	this->_name = name;
	this->_lifePoints = 100;
	this->_energyPoints = 50;
	this->_attackDG = 20;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Default destructor ScavTrap called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	this->_name = copy._name;
	this->_lifePoints = copy._lifePoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDG = copy._attackDG;
	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &rhs)
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

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoints > 0 || this->_lifePoints > 0)
		std::cout << "I'M IN GAAAAATE KEEEEEEPER MODE" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0 || this->_lifePoints == 0)
	{
		std::cout << this->_name << " can't attack, energy point : " << this->_energyPoints << " & life points : " << this->_lifePoints << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDG << " points of damage" << std::endl; 
}