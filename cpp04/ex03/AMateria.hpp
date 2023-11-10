#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria	{

protected:
	std::string	type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria(void);

	std::string const 	&getType(void) const;
	virtual	AMateria 	*clone(void) const = 0;
	virtual void 		use(ICharacter &target) const;
};

std::ostream	&operator<<(std::ostream &o, AMateria const &rhs);

#endif