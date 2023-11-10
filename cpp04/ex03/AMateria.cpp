#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
    if (MSG)
        std::cout << "AMateria constructor called" << std::endl;
    return ;
}

AMateria::~AMateria(void)
{
    if (MSG)
        std::cout << "AMateria destructor called" << std::endl;
    return ;
}

AMateria::AMateria(const AMateria &copy) : type(copy.type)
{
    if (MSG)
        std::cout << "AMateria copy constructor called" << std::endl;
    return ;
}

AMateria    &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

std::string const   &AMateria::getType(void) const
{
    return (this->type);
}

void    AMateria::use(ICharacter &target) const
{
	std::cout << this->type << " : * use AMateria to " << target.getName() << std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &o, AMateria const &rhs)
{
	o << "AMateria:" << std::endl << "type: " << rhs.getType() << std::endl;
	return (o);
}