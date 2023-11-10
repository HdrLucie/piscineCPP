#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <class T>
void	function(T i)
{
	std::cout << i << std::endl;
}

template <class T>
void    iter(T tab[], size_t size, void (function)(T i))
{
	for (size_t j = 0; j < size; j++)
		function(tab[j]);
}

#endif