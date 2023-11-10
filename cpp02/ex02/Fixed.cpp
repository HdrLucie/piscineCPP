#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPoint(0)
{
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed::Fixed(const Fixed &copyConstructor)
{
	fixedPoint = copyConstructor.fixedPoint;
	return ;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->fixedPoint = rhs.fixedPoint;
	return (*this);
}

std::ostream & operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed::Fixed(const int intValue)
{
	this->fixedPoint = intValue * pow(2, this->fractionalPoint);
	return ;
}

Fixed::Fixed(const float floatValue)
{
	this->fixedPoint = roundf(floatValue * (pow(2, this->fractionalPoint)));
	return ;
}

int	Fixed::toInt(void) const
{
	return (this->fixedPoint >> this->fractionalPoint);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (pow(2, this->fractionalPoint)));
}

/***********************************
*       Arithmetic operators	   *
***********************************/

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

/*************************
* COMPARAISON OPERATORS *
*************************/

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->fixedPoint > rhs.fixedPoint);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->fixedPoint < rhs.fixedPoint);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->fixedPoint >= rhs.fixedPoint);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->fixedPoint >= rhs.fixedPoint);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->fixedPoint == rhs.fixedPoint);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->fixedPoint != rhs.fixedPoint);
}

/*********************************
* INCREMENT/DECREMENT OPERATORS *
*           ~FIXED();           *
*********************************/

Fixed 	& Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

Fixed	& Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	oldValue(*this);
	++(*this);
	return (oldValue);
}

Fixed	Fixed::operator--(int)
{
	Fixed	oldValue(*this);
	--(*this);
	return (oldValue);
}

/*************
* FUNCTIONS *
*************/

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs.toFloat() < rhs.toFloat())
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.toFloat() < rhs.toFloat())
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs.toFloat() > rhs.toFloat())
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.toFloat() > rhs.toFloat())
		return (lhs);
	return (rhs);
}