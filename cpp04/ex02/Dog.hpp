#ifndef DOG_HPP
# define DOG_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {

private	:
	Brain	*brain;
public :

	Dog(void);
	Dog(const Dog &copy);
	Dog &operator=(const Dog &rhs);
	virtual ~Dog(void);
	virtual AAnimal	&operator=(const AAnimal &rhs);

	virtual void		setIdeas(const std::string newIdea, int index);
	virtual	std::string	getIdeas(int index) const;
	virtual void		makeSound(void) const;
};

#endif