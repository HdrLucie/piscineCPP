#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#ifndef	MSG
# define MSG 0
#endif

#include <iostream>
#include <string>

class	WrongAnimal	{

protected:

	std::string	type;

public:

	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual	~WrongAnimal(void);

	std::string		getType() const;
	void	makeSound() const;
};

#endif