#include    "Karen.hpp"

void	Karen::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	int			index;
	const char	arg[5] = "WIDE";
	index = 0;
	while (index < 4)
	{
		if (arg[index] == level[0])
		{
			void	(Karen::*whichComplaint)(void) = f_level[index];
			(this->*whichComplaint)();
		}
		index++;
	}
}

Karen::Karen()
{
	this->f_level[0] = &Karen::warning;
	this->f_level[1] = &Karen::info;
	this->f_level[2] = &Karen::debug;
	this->f_level[3] = &Karen::error;
	return ;
}

Karen::~Karen()
{
	return ;
}