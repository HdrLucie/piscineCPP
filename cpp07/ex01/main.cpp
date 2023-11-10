#include "iter.hpp"

int	main(void)
{
	{
		std::cout << "- - - - - - - \n   INT TAB\n- - - - - - - " << std::endl;
		int	tab[5] = {-5, -12, 54, 23, 0};
		iter(tab, 5, function);
	}
	{
		std::cout << "- - - - - - - \nSTRING TAB\n- - - - - - - " << std::endl;
		std::string	tab[5] = {"Coucou", "les", "p'tis", "potes", "!"};
		iter(tab, 5, function);
	}
	{
		std::cout << "- - - - - - - \nEMPTY TAB\n- - - - - - - " << std::endl;
		int	tab[0];
		iter(tab, 0, function);
	}
	return (0);
}