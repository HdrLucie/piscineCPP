#include "Fixed.hpp"

Fixed::Fixed(void): fixedPoint (0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &copyPoint)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = copyPoint.fixedPoint;
	return ;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->fixedPoint = rhs.fixedPoint;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
	return ;
}