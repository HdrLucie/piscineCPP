#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _lifePoints(10), _energyPoints(10), _attackDG(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	_name = copy._name;
	_lifePoints = copy._lifePoints;
	_energyPoints = copy._energyPoints;
	_attackDG = copy._attackDG;
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &rhs)
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

void    ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_lifePoints == 0)
	{
		std::cout << this->_name << " can't attack, energy point : " << this->_energyPoints << " & life points : " << this->_lifePoints << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDG << " points of damage" << std::endl; 
	return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0 || this->_lifePoints == 0)
	{
		std::cout << this->_name << " can't be repaired, energy point : " << this->_energyPoints << " & life points : " << this->_lifePoints << std::endl;
		return ;
	}
	this->_energyPoints -= 1;	
	std::cout << "Life points before heal : " << this->_lifePoints << std::endl;
	this->_lifePoints += amount;
	std::cout << "Life points after heal : " << this->_lifePoints << std::endl;
	return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_lifePoints > 0)
	{
		std::cout << "Life points before FIGHT : " << this->_lifePoints << std::endl;
		if (amount >= this->_lifePoints)
		{
			_lifePoints = 0;
			std::cout << "Life points : " << this->_lifePoints << "\nYOU LOST THE FIGHT !" << std::endl;
			return ;
		}
		this->_lifePoints -= amount;
		std::cout << "Life points after FIGHT : " << this->_lifePoints << std::endl;
	}
	else
		std::cout << "You want to hit a corpse (" << this->_name << ") ?" << std::endl;
	return ;
}