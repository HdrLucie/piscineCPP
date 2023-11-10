#include "Character.hpp"

Character::Character(std::string const &name) : ICharacter(), _name(name), _inventory()
{
	if (MSG)
		std::cout << "Character constructor called" << std::endl;
	return ;
}

Character::~Character(void)
{
	if (MSG)
	{
		std::cout << "Character destcrutor called" << std::endl;
	}
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (_inventory[i])
	// 		delete _inventory[i];
	// }
	return ;
}

Character::Character(const Character &copy) : ICharacter(copy), _name(copy._name), _inventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return ;
}

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i];
		}
	}
	return (*this);
}

std::string	const &Character::getName() const 
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	// std::cout << "TYPE : " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (i < 4)
			this->_inventory[i] = m;
	}
	return ;
}

void	Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_inventory[idx])
	{
		std::cout << "INDEX :" << idx << std::endl;
		std::cout << this->_name << ": "; 
		this->_inventory[idx]->use(target);
		std::cout << "\n";
	}
	return ;
}

std::string const	&Character::getInformation(int const idx) const
{
	if (this->_inventory[idx])
		return this->_inventory[idx]->getType();
	return (Character::_emptyType);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	int	idx;

	o << "Character:" << std::endl << "name: " << rhs.getName() << std::endl << "inventory: " << std::endl;
	for (idx = 0 ; idx < 4 ; ++idx)
		o << " [" << idx << "] " << rhs.getInformation(idx) << std::endl;
	return o;
}