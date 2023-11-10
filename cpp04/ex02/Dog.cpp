#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	if (MSG)
		std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->brain = new Brain();
	return ;
}

Dog::~Dog(void)
{
	if (MSG)
		std::cout << "Dog destructor called" << std::endl;
	delete brain;
	return ;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	if (MSG)
		std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;
	brain = new Brain(*copy.brain);
	for (int i = 0; i < 100; i++)
		setIdeas(copy.getIdeas(i), i);
	return ;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (MSG)
		std::cout << "Operator overload dog called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		for (int i = 0; i < 100; i++)
			setIdeas(rhs.getIdeas(i), i);
	}
	return (*this);
}

AAnimal &Dog::operator=(const AAnimal &rhs)
{
	if (MSG)
		std::cout << "Operator overload dog called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		for (int i = 0; i < 100; i++)
			setIdeas(rhs.getIdeas(i), i);
	}
	return (*this);
}

std::string Dog::getIdeas(int index) const
{
	return (this->brain->getIdeas(index));
}

void	Dog::setIdeas(const std::string newIdea, int index)
{
	this->brain->setIdeas(newIdea, index);
	return ;
}

void    Dog::makeSound(void) const
{
	std::cout << "Waf waf waf waf..." << std::endl;
	return ;
}