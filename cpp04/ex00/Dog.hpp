#ifndef DOG_HPP
# define DOG_HPP

#ifndef	MSG
# define MSG 1
#endif

#include "Animal.hpp"

class	Dog : public Animal {

private	:

public :

	Dog(void);
	Dog(const Dog &copy);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog(void);

	virtual void	makeSound(void) const;
};

#endif