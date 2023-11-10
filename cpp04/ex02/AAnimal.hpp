#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <string>
#include <iostream>

#include "Brain.hpp"

class	AAnimal {

protected :

	std::string	_type;

public : 
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal(void);

	virtual void		setIdeas(const std::string newIdea, int index) = 0;
	virtual std::string	getIdeas(int index) const = 0;
	std::string			getType(void) const;
	virtual void		makeSound(void) const = 0;
};

std::ostream & operator<<(std::ostream &o, const AAnimal &rhs);

#endif