#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#ifndef	MSG
# define MSG 1
#endif

#include <string>
#include <iostream>

class	Animal {

protected :

	std::string	_type;

public : 
	Animal(void);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal(void);

	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

std::ostream & operator<<(std::ostream &o, const Animal &rhs);

#endif