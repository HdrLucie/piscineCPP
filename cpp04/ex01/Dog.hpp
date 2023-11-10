#ifndef DOG_HPP
# define DOG_HPP

#ifndef	MSG
# define MSG 1
#endif

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {

private	:
	Brain	*brain;
public :

	Dog(void);
	Dog(const Dog &copy);
	Dog &operator=(const Dog &rhs);
	~Dog(void);
	virtual Animal	&operator=(const Animal &rhs);

	virtual void		setIdeas(const std::string newIdea, int index);
	virtual	std::string	getIdeas(int index) const;
	virtual void		makeSound(void) const;
};

#endif