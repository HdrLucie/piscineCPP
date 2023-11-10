#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	if (MSG)
		std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::~Cat(void)
{
	if (MSG)
		std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	if (MSG)
		std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
	return ;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (MSG)
		std::cout << "Cat overload called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow meow meow meow... Ronronronron..." << std::endl;
}