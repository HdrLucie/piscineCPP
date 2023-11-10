#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap    Jonathan("Jonathan Joestar");
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		    break ;
		if (input != "attack" && input != "repaire" && input != "take damage" && input != "exit")
			std::cout << "Wrong input, please enter 'attack', 'repaire', 'take damage' or 'exit'!" << std::endl;
		else if (input == "attack")
			Jonathan.attack("Dio");
		else if (input == "repaire")
			Jonathan.beRepaired(10);
		else if (input == "take damage")
			Jonathan.takeDamage(10);
		if (input == "exit")
			break ;
	}
	return (0);
}