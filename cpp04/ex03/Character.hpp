#ifndef	CHARACTER_HPP
# define CHARACTER_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {

private:
	std::string	_name;
	AMateria	*_inventory[4];
	std::string const	_emptyType;
public:

	Character(std::string const &name);
	virtual ~Character();
	Character(const Character &copy);
	Character &operator=(const Character &rhs);

	std::string const &getName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);
	std::string const	&getInformation(int const idx) const;

};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif