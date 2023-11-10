#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	if (MSG)
		std::cout << "ICharacter constructor called" << std::endl;
	return ;
}

ICharacter::~ICharacter(void)
{
	if (MSG)
		std::cout << "ICharacter destructor called" << std::endl;
	return ;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	(void)copy;
	return ;
}

ICharacter  &ICharacter::operator=(const ICharacter &rhs)
{
	(void)rhs;
	return (*this);
}