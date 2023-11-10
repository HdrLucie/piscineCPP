#include "Span.hpp"
#include <limits>

Span::Span(unsigned int amount) : _N(amount), _size(0), _tab()
{
	if (MSG)
		std::cout << BL << "Span constructor called" << NC << std::endl;
	return ;
}

Span::~Span(void)
{
	if (MSG)
		std::cout << BL << "Span destructor called" << NC << std::endl;
	return ;
}

Span    &Span::operator=(const Span &rhs)
{
	if (MSG)
		std::cout << BL << "operator overload called" << NC << std::endl;
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

unsigned int	Span::getSize() const
{
	return (this->_size);
}

int	Span::getValue(unsigned int i) const
{
	return (this->_tab[i]);
}

int	Span::longestSpan()
{
	if (getSize() < 2)
		throw	Span::spanException();
	else
	{
		return (static_cast<int>(*std::max_element(this->_tab.begin(), this->_tab.end()) 
			- *std::min_element(this->_tab.begin(), this->_tab.end())));
	}
}

int	Span::shortestSpan()
{
	unsigned int				tmpDiff;
	unsigned int				i;
	std::vector<int>			it;
	unsigned int				a;
	unsigned int				b;

	a = 0;
	b = 0;
	i = 0;
	if (getSize() < 2)
		throw	Span::spanException();
	tmpDiff = std::numeric_limits<int>::max();
	it.begin() = this->_tab.begin();
	std::sort(this->_tab.begin(), this->_tab.end());
	while (i < getSize() - 1)
	{
		if (tmpDiff > static_cast<unsigned int>(this->_tab[i + 1] - this->_tab[i]))
			tmpDiff = static_cast<unsigned int>(this->_tab[i + 1] - this->_tab[i]);
		i++;
	}
	return (tmpDiff);
}

void	Span::addNumber(int nbToAdd)
{
	if (getSize() >= this->_N)
		throw Span::tooMuchNumberException();
	_tab.push_back(nbToAdd);
	this->_size++;
	return ;
}

int	Span::getMaxValue() const
{
	return (static_cast<int>(*std::max_element(this->_tab.begin(), this->_tab.end())));
}

int	Span::getMinValue() const
{
	return (static_cast<int>(*std::min_element(this->_tab.begin(), this->_tab.end())));
}

std::ostream	&operator<<(std::ostream &o, Span const &rhs)
{
	for (unsigned int i = 0; i < rhs.getSize(); i++)
		o << GR << rhs.getValue(i) << " " << NC;
	o << GRN << "\nMax value : " << NC << rhs.getMaxValue() << std::endl;
	o << GRN << "Min value : " << NC << rhs.getMinValue() << std::endl;
	return (o);
}