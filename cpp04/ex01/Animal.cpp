#include "Animal.hpp"

Animal::Animal(void)
{
	if (MSG)
		std::cout << "Animal constructor called" << std::endl;
	this->_type = "Default type";
	return ;
}

Animal::~Animal(void)
{
	if (MSG)
		std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &copy)
{
	if (MSG)
		std::cout << "Animal copy constructor called" << std::endl;
	this->_type = copy._type;
	return ;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (MSG)
		std::cout << "Animal operator overload called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void    Animal::makeSound () const
{
	std::cout << "Oh god, what animal is that !?" << std::endl;
	return ;
}