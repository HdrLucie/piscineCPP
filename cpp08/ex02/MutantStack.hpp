#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

/*
** By default by inheriting from the stack, I have access to the deque container
** Here I build my class with list, so I have access to list iterators.
** Template functions are therefore functions which can work on objects whose type
** is a generic type (ie any type), or which can be parameterized by an integral 
** type constant. Template classes are classes that contain members whose type
** is generic or that depend on an integral parameter.
** If I call the member function pop, pop function calls pop_back of the underlying
** container object. Same for all members functions : empty, size, top and pop.
*/

template <typename T, typename C>
class   MutantStack : public std::stack<T, C> {

private :

public :
	MutantStack() {};
	MutantStack(const MutantStack<T, C>& src) { *this = src; }
	MutantStack<T, C>& operator=(const MutantStack<T, C>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {};

	typedef typename std::stack<T, C>::container_type c_type;
	typedef typename c_type::iterator iterator;
	typedef typename c_type::const_iterator const_iterator;
	typedef typename c_type::reverse_iterator reverse_iterator;
	typedef typename c_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return (this->c.begin());}
	iterator end() { return (this->c.end());}
	const_iterator begin() const {return (this->c.begin());}
	const_iterator end() const { return (this->c.end());}

	reverse_iterator rbegin() {return (this->c.rbegin());}
	reverse_iterator rend() { return (this->c.rend());}
	const_reverse_iterator rbegin() const {return (this->c.rbegin());}
	const_reverse_iterator rend() const { return (this->c.rend());}
};

#endif