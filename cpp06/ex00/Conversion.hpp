#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#ifndef	MSG
# define MSG 1
#endif

#include <string>
#include <iostream>
#include <cctype>
#include <limits>

class	Conversion {

private :
	std::string			_inputToConvert;
	int					_type;
	int					_intValue;
	float				_floatValue;
	double				_doubleValue;
	char				_charValue;

public :
	Conversion(std::string &input);
	Conversion(const Conversion &src);
	Conversion	&operator=(const Conversion &rhs);
	virtual ~Conversion(void);

	void	printConvert();
	void	printInt(double value);
	void	printFloat(double value);
	void	printChar();
	void	printDouble(double value);
	int	whichType();
};

std::ostream & operator<<(std::ostream &o, const Conversion &rhs);


#endif