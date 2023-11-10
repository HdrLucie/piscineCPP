#ifndef BRAIN_HPP
# define BRAIN_HPP

#ifndef	MSG
# define MSG 1
#endif

#include <string>
#include <iostream>

class	Brain {

protected :

public :
	Brain(void);
	virtual ~Brain(void);
	Brain(const Brain &copy);
	Brain &operator=(const Brain &rhs);
	std::string ideas[100];

	virtual std::string	getIdeas(int index) const;
	virtual void		setIdeas(const std::string newIdea, int index);
};

#endif