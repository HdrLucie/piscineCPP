#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
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

Cat::Cat(const Cat &copy) : AAnimal(copy) {
	if (MSG)
		std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
	brain = new Brain(*copy.brain);
	for (int i = 0; i < 100; i++)
		setIdeas(copy.getIdeas(i), i);
	return ;
}

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

AAnimal &Cat::operator=(const AAnimal &rhs)
{
	if (MSG)
		std::cout << "Operator overload cat animal called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		std::cout << this->_type << std::endl;
		for (int i = 0; i < 100; i++)
			setIdeas(rhs.getIdeas(i), i);
	}
	return (*this);
}

void	Cat::setIdeas(const std::string newIdea, int index)
{
	this->brain->setIdeas(newIdea, index);
	return ;
}


std::string Cat::getIdeas(int index) const
{
	return (this->brain->ideas[index]);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow meow meow meow... Ronronronron..." << std::endl;
}