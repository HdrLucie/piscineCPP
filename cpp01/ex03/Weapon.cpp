#include "Weapon.hpp"

const   std::string& Weapon::getType()
{
	return (Weapon::_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string string)
{
	this->_type = string;
	return ;
}

Weapon::~Weapon()
{
	return ;
}