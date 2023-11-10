#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

/***************************************************************************************
 * RHS : RIGHT-HAND-SIDE, REPRESENT THE OBJECT ON THE RIGHT HAND SIDE OF THE OPERATOR. *
 ***************************************************************************************/

class   Fixed {

private :
		int					fixedPoint;
		static const int	fractionnalInt = 8;
public :
	Fixed(void);
	Fixed(const Fixed &copyPoint);
	Fixed &operator=(const Fixed &rhs);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif