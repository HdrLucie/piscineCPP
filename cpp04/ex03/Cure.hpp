#ifndef CURE_HPP
# define CURE_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

private :

public :
	Cure(void);
	Cure(const Cure &copy);
	Cure &operator=(const Cure &rhs);
	virtual ~Cure(void);

	AMateria	*clone(void) const;
	void		use(ICharacter &target) const;
};

#endif 