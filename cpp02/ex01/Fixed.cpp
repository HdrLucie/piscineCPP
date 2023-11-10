#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : fixedPoint (0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = intValue * pow(2, this->fractionalPoint);
	return ;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(floatValue * (pow(2, this->fractionalPoint)));
	return ;
}

Fixed::Fixed(const Fixed &copyConstructor)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = copyConstructor.fixedPoint;
	return ;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->fixedPoint = rhs.fixedPoint;
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->fractionalPoint);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (pow(2, this->fractionalPoint)));
}

std::ostream & operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}