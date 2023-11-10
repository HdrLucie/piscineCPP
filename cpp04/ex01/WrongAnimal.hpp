#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#ifndef	MSG
# define MSG 1
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
	virtual	void	makeSound() const;
};

#endif