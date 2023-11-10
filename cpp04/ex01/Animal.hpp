#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#ifndef	MSG
# define MSG 1
#endif

#include <string>
#include <iostream>

#include "Brain.hpp"

/*
** Virtual can be used only with polymorphism.
** Allow to execute the derived class's version of the function
*/

class	Animal {

protected :

	std::string	_type;

public : 
	Animal(void);
	Animal(const Animal &copy);
	virtual Animal &operator=(const Animal &rhs);
	virtual ~Animal(void);

	virtual void		setIdeas(const std::string newIdea, int index) = 0;
	virtual std::string	getIdeas(int index) const = 0;
	std::string			getType(void) const;
	virtual void		makeSound(void) const;
};

std::ostream & operator<<(std::ostream &o, const Animal &rhs);

#endif