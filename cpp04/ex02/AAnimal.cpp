#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    if (MSG)
    {
        std::cout << "AAnimal constructor called" << std::endl;
    }
	this->_type = "Default type";
    return ;
}

AAnimal::~AAnimal(void)
{
    if (MSG)
        std::cout << "AAnimal destructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    this->_type = copy._type;
    return ;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->_type);
}

void    AAnimal::makeSound () const
{
    std::cout << "Oh god, what animal is that !?" << std::endl;
    return ;
}