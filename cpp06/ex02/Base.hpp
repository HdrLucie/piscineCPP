#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <exception>

class	Base {

public :
	virtual ~Base(void);

};

void	identify(Base *p);
void	identify(Base &p);
Base	*generate(void);

#endif