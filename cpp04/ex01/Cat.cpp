#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	if (MSG)
		std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain();
	return ;
}

Cat::~Cat(void)
{
	if (MSG)
		std::cout << "Cat destructor called" << std::endl;
	delete brain;
	return ;
}

Cat::Cat(const Cat &copy) : Animal(copy) 
{
	if (MSG)
		std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
	brain = new Brain(*copy.brain);
	for (int i = 0; i < 100; i++)
		setIdeas(copy.getIdeas(i), i);
	return ;
}

/*
** Shallow copy share the same address in the memory,
** to make a deep copy we have to realloc. Thus if a variable
** is modified in a copy, the other value isn't modified.
** Deep copy is a good practice when dynamic allocation is used.
** When I make deep copy (with new), create the new heap location
** and then copies the value of obj content to new heap location.
** src : https://owlcation.com/stem/Copy-Constructor-shallow-copy-vs-deep-copy
** https://www.mylearningmania.com/2021/02/deep-and-shallow-copy-in-cpp.html?m=1
*/

Cat &Cat::operator=(const Cat &rhs)
{
	if (MSG)
		std::cout << "Operator overload cat called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		for (int i = 0; i < 100; i++)
			setIdeas(rhs.getIdeas(i), i);
	}
	return (*this);
}

Animal &Cat::operator=(const Animal &rhs)
{
	if (MSG)
		std::cout << "Operator overload cat animal called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		for (int i = 0; i < 100; i++)
			setIdeas(rhs.getIdeas(i), i);
	}
	return (*this);
}

std::string Cat::getIdeas(int index) const
{
	return (this->brain->getIdeas(index));
}

void	Cat::setIdeas(const std::string newIdea, int index)
{
	this->brain->setIdeas(newIdea, index);
	return ;
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow meow meow... Ronronronron..." << std::endl;
}