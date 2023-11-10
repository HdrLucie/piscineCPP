#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (MSG)
		std::cout << "Ice constructor called" << std::endl;
	return ;
}

Ice::~Ice()
{
	if (MSG)
		std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice &copy) : AMateria(copy.type)
{
	return ;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria    *Ice::clone(void) const 
{
	return (new Ice(*this));
}

void    Ice::use(ICharacter &target) const
{
	std::cout << this->type << " : * shoots an ice bolt at ";
	target.getName();
	std::cout << " *";
	return ;
}