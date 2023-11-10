#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <string>

/*
** The keyword typename was introduced to specify that the identifier that follows is a type.
*/

class	notFoundException : public std::exception
{
	public :
		virtual const char * what() const throw()
		{
			return ("Occurence not found");
		}
};

template <class T>
int const	&easyfind(T container, int valueToFind)
{
	typename T::iterator	iterator;
	
	iterator = find(container.begin(), container.end(), valueToFind);
	if (iterator == container.end())
		throw notFoundException();
	return (*iterator);
}

#endif