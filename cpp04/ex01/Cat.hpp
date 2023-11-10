#ifndef CAT_HPP
# define CAT_HPP

#ifndef	MSG
# define MSG 1
#endif

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {

private :
	Brain	*brain;

public :
	Cat(void);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &rhs);
	~Cat(void);
	virtual Animal &operator=(const Animal &rhs);

	virtual void		setIdeas(const std::string newIdea, int index);
	virtual	std::string	getIdeas(int index) const;
	virtual void		makeSound() const;
};

std::ostream & operator<<(std::ostream &o, const Cat &rhs);

#endif