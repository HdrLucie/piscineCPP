#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon()
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
	if (weapon.getType() == "")
		std::cout << "There is no weapon" << std::endl;
	this->_weapon = &weapon;
}

void    HumanB::attack() const
{
	std::cout << HumanB::_name << " attacks with their " << HumanB::_weapon->getType() << std::endl;
}