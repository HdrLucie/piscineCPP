#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (MSG)
		std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::~Cure(void)
{
	if (MSG)
		std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure::Cure(const Cure &copy) : AMateria(copy.type)
{
	return ;
}

Cure	&Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

AMateria	*Cure::clone(void) const 
{
	return (new Cure(*this));
}

void    Cure::use(ICharacter &target) const
{
	std::cout << this->type << " : * heals ";
	target.getName();
	std::cout << "'s wounds *";
	return ;
}