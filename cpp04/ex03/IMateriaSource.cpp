#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	if (MSG)
		std::cout << "IMateriaSource constructor called" << std::endl;
	return ;
}

IMateriaSource::~IMateriaSource(void)
{
	if (MSG)
		std::cout << "IMateriaSource destructor called" << std::endl;
	return ;
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	(void)copy;
	return ;
}

IMateriaSource  &IMateriaSource::operator=(const IMateriaSource &rhs)
{
	(void)rhs;
	return (*this);
}