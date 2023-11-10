#ifndef SPAN_HPP
# define SPAN_HPP

#ifndef MSG
# define MSG 1
#endif

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define GR "\e[0;90m"
#define BL "\e[0;30m"

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

class	Span {

private :
	unsigned int		_N;
	unsigned int		_size;		
	std::vector<int>	_tab;

public :
	Span(unsigned int amount);
	Span(const Span &copy);
	Span	&operator=(const Span &rhs);
	~Span(void);

	void			addNumber(int nbToAdd);
	int				shortestSpan();
	int				getMaxValue() const;
	int				getMinValue() const;
	int				getValue(unsigned int i) const;
	unsigned int	getSize() const;
	int				longestSpan();

	template <typename Iter1>
	void	addNumbers(Iter1 first, Iter1 last)
	{
		if (getSize() == this->_N || std::distance(first, last) + getSize() > _N)
			throw Span::tooMuchNumberException();
		this->_tab.insert(_tab.end(), first, last);
		this->_size += std::distance(first, last);		
	}
	class	tooMuchNumberException : public std::exception
	{
		public :
			virtual const char * what() const throw()
			{
				return ("Too much numbers.");
			}
	};
	class	spanException : public std::exception
	{
		public :
			virtual const char * what() const throw()
			{
				return ("No span can be found.");
			}
	};
};

std::ostream	&operator<<(std::ostream &o, Span const &rhs);

#endif