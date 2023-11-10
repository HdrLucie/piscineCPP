#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

#include <iostream>
#include "Array.hpp"

class   testClass {

private : 
	int	_randomValue;

public :
	testClass(void) {
		
		std::cout << "TestClass constructor called" << std::endl;
		this->_randomValue = 10;
		return ;
	}
	~testClass(void) {
		std::cout << "TestClass destructor called" << std::endl;
		return ;
	}
	void	setValue(int newValue) {
		this->_randomValue = newValue;
		return ;
	}
	int		getValue() const {
		return (this->_randomValue);
	}
};

#endif