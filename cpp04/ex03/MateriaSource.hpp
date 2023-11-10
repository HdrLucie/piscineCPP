#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#ifndef	MSG
# define MSG 0
#endif

#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

class	AMateria;

class	MateriaSource : public IMateriaSource {

private :
	AMateria	*_tmpInventary[4];
public :
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	MateriaSource	&operator=(const MateriaSource &rhs);
	virtual ~MateriaSource(void);

	virtual	void		learnMateria(AMateria *m);
	virtual	AMateria	*createMateria(std::string const &type);
};

#endif