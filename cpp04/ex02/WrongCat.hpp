#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

private :

public :
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat(void);

	virtual	void	makeSound() const;
};

#endif