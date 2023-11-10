#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

#ifndef	MSG
# define MSG 0
#endif

class	AMateria;

class	ICharacter {

public :
	ICharacter(void);
	ICharacter(const ICharacter &copy);
	ICharacter &operator=(const ICharacter &rhs);
	virtual	~ICharacter(void);

	virtual	std::string	const &getName() const = 0;
	virtual	void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter &target) = 0;
};

#endif