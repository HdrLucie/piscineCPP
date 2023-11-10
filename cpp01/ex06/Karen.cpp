#include "Karen.hpp"

Karen::Karen()
{
	this->f_tab[0] = &Karen::debug;
	this->f_tab[1] = &Karen::info;
	this->f_tab[2] = &Karen::warning;
	this->f_tab[3] = &Karen::error;
	return ;
}

Karen::~Karen()
{
	return ;
}

void	Karen::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Karen::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Karen::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Karen::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Karen::printComplaint(int indexLevel)
{
	int	i;

	i = 4;
	while (indexLevel < i)
	{
		void	(Karen::*whichComplaint)(void) = f_tab[indexLevel];
		(this->*whichComplaint)();
		indexLevel++;
	}
}

void    Karen::complain(std::string level)
{
	const char	str[5] = "DIWE";
	int	level_index;

	level_index = 0;
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
		level_index = 4;
	else
	{
		while (str[level_index] && str[level_index] != level[0])
			level_index++;
	}
	switch (level_index)
	{
		case 0 :
			printComplaint(0);
		break;
		case 1 :
			printComplaint(1);
		break;
		case 2 :
			printComplaint(2);
		break;
		case 3 :
			printComplaint(3);
		break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}