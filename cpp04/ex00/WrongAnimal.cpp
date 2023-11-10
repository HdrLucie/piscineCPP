#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	if (MSG)
		std::cout << "Wrong Animal constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	if (MSG)
		std::cout << "Wrong Animal destructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	if (MSG)
		std::cout << "Wrong animal copy constructor called" << std::endl;
	this->_type = copy._type;
	return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void    WrongAnimal::makeSound() const
{
	std::cout << "ferijghrhghrigkhrvjhbvjrsgbjkghhifgh... Something Wrong... Strange animal" << std::endl;
	return ;
}