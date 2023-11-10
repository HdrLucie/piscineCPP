#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap    Jonathan("Jonathan Joestar");
	ScavTrap	Joseph("Joseph Joestar");
	FragTrap	Jotaro("Jotaro Joestar");
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		    break ;
		if (input != "attack" && input != "repaire" && input != "take damage" && input != "exit" && input != "gate keeper" && input != "high fives")
			std::cout << "Wrong input, please enter 'attack', 'repaired', 'take damage', 'exit', 'gate keeper' or 'high fives'!" << std::endl;
		else if (input == "attack") {
			Jonathan.attack("Dio");
			Joseph.attack("Santana");
			Jotaro.attack("Dio");
		}
		else if (input == "repaire") {
			Jonathan.beRepaired(10);
			Joseph.beRepaired(20);
			Jotaro.beRepaired(50);
		}
		else if (input == "take damage") {
			Jonathan.takeDamage(20);
			Joseph.takeDamage(10);
			Jotaro.takeDamage(5);
		}
		else if (input == "gate keeper")
			Joseph.guardGate();
		else if (input == "high fives")
			Jotaro.highFivesGuys();
		if (input == "exit")
			break ;
	}
	return (0);
}