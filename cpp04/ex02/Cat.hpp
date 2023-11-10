#ifndef CAT_HPP
# define CAT_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal {

private :
	Brain	*brain;

public :
	Cat(void);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat(void);
	virtual AAnimal &operator=(const AAnimal &rhs);

	virtual void		setIdeas(const std::string newIdea, int index);
	virtual	std::string	getIdeas(int index) const;
	virtual void		makeSound() const;
};

#endif