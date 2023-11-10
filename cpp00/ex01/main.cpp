#include "Contact.hpp"
#include "PhoneBook.hpp"

int main (void)
{
	int			index;
	PhoneBook	listContact;
	std::string	input;

	index = 1;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			listContact.addContact();
		else if (input == "SEARCH")
		{
			listContact.searchInfo();
			std::cout << "ENTER INDEX" << std::endl;
			listContact.trackInfo();
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Wrong input" << std::endl;
	}
	return (0);
}