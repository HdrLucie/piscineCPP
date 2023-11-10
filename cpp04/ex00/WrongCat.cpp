#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() 
{
	if (MSG)
		std::cout << "Wrong Cat constructor called" << std::endl;
	this->_type = "Wrong Cat";
	return ;
}

WrongCat::~WrongCat(void)
{
	if (MSG)
		std::cout << "Wrong Cat destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	if (MSG)
		std::cout << "Wrong cat copy constructor called" << std::endl;
	this->_type = copy._type;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Coin, coin, coin, coin... Oh god, why this cat make coin-coin ?" << std::endl;
	return ;
}