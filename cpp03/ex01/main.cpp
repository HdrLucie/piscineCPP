#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap    Jonathan("Jonathan Joestar");
	ScavTrap	Joseph("Joseph Joestar");
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		    break ;
		if (input != "attack" && input != "repaire" && input != "take damage" && input != "exit" && input != "gate keeper")
			std::cout << "Wrong input, please enter 'attack', 'repaired', 'take damage', 'gate keeper' or 'exit'!" << std::endl;
		else if (input == "attack") {
			Jonathan.attack("Dio");
			Joseph.attack("Santana");
		}
		else if (input == "repaire") {
			Jonathan.beRepaired(10);
			Joseph.beRepaired(20);
		}
		else if (input == "take damage") {
			Jonathan.takeDamage(20);
			Joseph.takeDamage(10);
		}
		else if (input == "gate keeper")
			Joseph.guardGate();
		if (input == "exit")
			break ;
	}
	return (0);
}