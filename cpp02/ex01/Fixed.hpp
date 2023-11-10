#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class   Fixed {

private :
	int             	fixedPoint;
	static const int	fractionalPoint = 8;
public :
	Fixed(void);
	Fixed(const Fixed &copyConstructor);
	Fixed &operator=(const Fixed &rhs);
	Fixed(const int intValue);
	Fixed(const float floatValue);
	~Fixed(void);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, const Fixed &rhs);

#endif