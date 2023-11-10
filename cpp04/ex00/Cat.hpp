#ifndef CAT_HPP
# define CAT_HPP

#ifndef	MSG
# define MSG 1
#endif

#include "Animal.hpp"

class	Cat : public Animal {

private :

public :
	Cat(void);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &rhs);
	virtual ~Cat(void);

	virtual void	makeSound() const;
};

#endif