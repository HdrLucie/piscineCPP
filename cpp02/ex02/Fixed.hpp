#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

#define	TRUE 1
#define FALSE 2

class	Fixed {

private:
	int					fixedPoint;
	static const int	fractionalPoint = 8;	
public:
	Fixed(void);
	Fixed(const float floatValue);
	Fixed(const int intValue);
	Fixed(const Fixed &src);
	~Fixed(void);
	Fixed	&operator=(const Fixed &rhs);
	float	toFloat(void) const;
	int		toInt(void) const;

	/***********************************
 	*       Arithmetic operators	   *
 	***********************************/

	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	/*************************
 	* COMPARAISON OPERATORS *
 	*************************/

 	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	/*********************************
 	* INCREMENT/DECREMENT OPERATORS *
	*********************************/

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int value);
	Fixed	operator--(int value);

	/*************
 	* FUNCTIONS *
 	*************/
 	static Fixed		&min(Fixed &lhs, Fixed &rhs);
	const static Fixed	&min(const Fixed &lhs, const Fixed &rhs);
	static Fixed		&max(Fixed &lhs, Fixed &rhs);
	const static Fixed	&max(const Fixed &lhs, const Fixed &rhs);
	
};

std::ostream & operator<<(std::ostream &o, const Fixed &rhs);

#endif