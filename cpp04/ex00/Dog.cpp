#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	if (MSG)
		std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::~Dog(void)
{
	if (MSG)
		std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	if (MSG)
		std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;
	return ;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (MSG)
		std::cout << "Dog overload operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void    Dog::makeSound(void) const
{
	std::cout << "Waf waf waf waf..." << std::endl;
	return ;
}