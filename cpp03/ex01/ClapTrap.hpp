#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap {

protected :
	std::string		_name;
	unsigned int	_lifePoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDG;
public	:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap & copy);
	ClapTrap &operator=(const ClapTrap & rhs);
	~ClapTrap(void);

	void	attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif