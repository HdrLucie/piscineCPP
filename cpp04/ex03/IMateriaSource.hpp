#ifndef	IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

#ifndef	MSG
# define MSG 0
#endif

class	AMateria;

class	IMateriaSource {

private :

public :
	IMateriaSource(void);
	IMateriaSource(const IMateriaSource &copy);
	IMateriaSource	&operator=(const IMateriaSource &rhs);
	virtual ~IMateriaSource();

	virtual	void		learnMateria(AMateria *m) = 0;
	virtual	AMateria	*createMateria(std::string const &type) = 0;
};

#endif