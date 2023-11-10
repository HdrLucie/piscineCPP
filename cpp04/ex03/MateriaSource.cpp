#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource(), _tmpInventary()
{
	if (MSG)
		std::cout << "MateriaSource constructor called" << std::endl;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	if (MSG)
		std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy), _tmpInventary()
{
	std::cout << "Materia source" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (copy._tmpInventary[i])
			this->_tmpInventary[i] = copy._tmpInventary[i]->clone();
	}
	return ;
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_tmpInventary[i];
			this->_tmpInventary[i] = NULL;
			if (rhs._tmpInventary[i])
				this->_tmpInventary[i] = rhs._tmpInventary[i];
		}
	}
	return (*this);
}

void    MateriaSource::learnMateria(AMateria *m)
{
	std::cout << m->getType() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (i < 4)
			this->_tmpInventary[i] = m;
	}
	return ;
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4 && this->_tmpInventary[i]; i++)
	{
		if (!this->_tmpInventary[i]->getType().compare(type))
			return (this->_tmpInventary[i]->clone());	
	}
	return (NULL);
}