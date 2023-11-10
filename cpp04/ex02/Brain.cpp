#include "Brain.hpp"

Brain::Brain(void)
{
	if (MSG)
	{
		std::cout << "Brain constructor called" << std::endl;
	}
	for (int i = 0; i < 100; i++)
	{
		if (i % 4 == 0)
			this->ideas[i] = "I'm hungry !";
		else if (i % 4 == 1)
			this->ideas[i] = "I'm tired... Go sleep";
		else if (i % 4 == 2)
			this->ideas[i] = "Bored... Bites your feet";
		else if (i % 4 == 3)
			this->ideas[i] = "Shows sign of affection";
	}
	return ;
}

Brain::~Brain(void)
{
	if (MSG)
		std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &copy)
{
	if (MSG)
		std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = copy.ideas[i];
	return ;
}

void	Brain::setIdeas(const std::string newIdea, int index)
{
	this->ideas[index] = newIdea;
}

std::string	Brain::getIdeas(int index) const
{
	return (this->ideas[index]);
}

Brain   &Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.getIdeas(i);
	}
	return (*this);
}
