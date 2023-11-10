#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "testClass.hpp"

template <class T>
class Array {

private :
	unsigned int	_size;
	T				*tab;
public : 
	Array(void) : _size(0)
	{
		std::cout << "Construction with no parameter" << std::endl;
		this->tab = new T[_size];
		this->_size = 0;
		return ;		
	}
	Array(unsigned int n) {
		std::cout << "Construction with an unsigned int" << std::endl;
		this->_size = n;
		this->tab = new T[n];
		for (unsigned int i = 0; i < n ; i++)
			this->tab[i] = 0;
		return ;		
	}
	Array(const Array<T> &copy) {
		std::cout << "Copy constructor called" << std::endl;
		this->_size = copy.size();
		this->tab = new T[_size];
		for (unsigned int i = 0; i < this->_size ; i++)
			this->tab[i] = 0;
		return ;		
	}
	Array	&operator=(const Array<T> &rhs) {
		std::cout << "Assignement operator called" << std::endl;
		if (this != &rhs)
		{
			delete[] tab;
			this->_size = rhs._size;
			this->tab = new T[_size];
			for (unsigned int i = 0; i < this->_size ; i++)
				this->tab[i] = 0;
		}
		return (*this);
	}
	T 		&operator[](unsigned int i) {
		if (i > this->_size - 1)
			throw Array::indexException();
		return (this->tab[i]);
	}
	~Array(void) {
		std::cout << "Destructor called" << std::endl;
		delete[] tab;
	}

	unsigned int	size(void) const {
		return (this->_size);
	}
	class	indexException : public std::exception
	{
		public : 
			virtual const char * what() const throw()
			{
				return ("Wrong index");
			}
	};
};

#endif