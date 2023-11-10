#include "Data.hpp"

Data::Data(int value) : _value(value)
{
	if (MSG)
		std::cout << "Data constructor called" << std::endl;
	return ;
}

Data::~Data(void)
{
	if (MSG)
		std::cout << "Data destructor called" <<std::endl;
	return ;
}

Data::Data(const Data &src) : _value(src._value)
{
	if (MSG)
		std::cout << "Data copy constructor called" << std::endl;
	return ;
}

int	Data::getValue() const
{
	return (this->_value);
}

Data	&Data::operator=(const Data &rhs)
{
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

uintptr_t	Data::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Data::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}