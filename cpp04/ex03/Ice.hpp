#ifndef ICE_HPP
# define ICE_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Ice : public AMateria {

private :

public : 
	Ice(void);
	Ice(const Ice &copy);
	Ice &operator=(const Ice &rhs);
	virtual ~Ice(void);

	AMateria	*clone(void) const;
	void 		use(ICharacter &target) const;
};

#endif