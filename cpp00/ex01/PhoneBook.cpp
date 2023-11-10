/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:16:09 by hlucie            #+#    #+#             */
/*   Updated: 2022/01/13 18:34:39 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"  

PhoneBook::PhoneBook(void) : nbContact(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addContact()
{
	if (nbContact == 8)
		nbContact = 0;
	phoneBook[nbContact++].getInfo();
}

int	PhoneBook::trackInfo()
{
	std::string	input;
	int			index;
	int			i;

	i = 0;
	index = 1;
	std::getline(std::cin, input);
	if (input.empty())
		return (1);
	index = std::atoi(input.c_str());
	if (index < 0 || index > 7)
	{
		std::cout << "WRONG INDEX" << std::endl;
		return (0);
	}
	while (input[i])
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "WRONG INPUT" << std::endl;
			return (0);
		}
		i++;
	}
	index = std::atoi(input.c_str());
	if (phoneBook[index].getFirstName().empty() && phoneBook[index].getLastName().empty()
	&& phoneBook[index].getNickName().empty() && phoneBook[index].getPhoneNumber().empty()
	&& phoneBook[index].getDarkSecret().empty())
	{
		std::cout << "WRONG INDEX" << std::endl;
		return (0);
	}
	std::cout << phoneBook[index].getFirstName() << std::endl;		
	std::cout << phoneBook[index].getLastName() << std::endl;		
	std::cout << phoneBook[index].getNickName() << std::endl;		
	std::cout << phoneBook[index].getPhoneNumber() << std::endl;		
	std::cout << phoneBook[index].getDarkSecret() << std::endl;
	return (0);	
}

void	cutInfo(std::string str)
{
	std::string	tmp;

	tmp = str;
	tmp.replace(9, 1, ".");
	tmp.resize(10);
	std::cout << std::setfill (' ') << std::setw (10) << tmp;
}

void	PhoneBook::searchInfo()
{
	int			i;

	i = 0;
	std::cout << "|"; std::cout << std::setfill (' ') << std::setw (10) << "index";  std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10) << "first name";  std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10) << "last name";  std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10) << "nickname";  std::cout << "|" << std::endl;
	while (i <= 7)
	{
		if (phoneBook[i].getFirstName().empty() && phoneBook[i].getLastName().empty()
		&& phoneBook[i].getNickName().empty() && phoneBook[i].getPhoneNumber().empty()
		&& phoneBook[i].getDarkSecret().empty())
			return ;
		std::cout << "|"; std::cout << std::setfill (' ') << std::setw (10) << i;
		std::cout << "|";
		if ((phoneBook[i].getFirstName()).size() >= 10)
			cutInfo(phoneBook[i].getFirstName());
		else
			std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getFirstName() << "|";
		if ((phoneBook[i].getLastName()).size() >= 10)
			cutInfo(phoneBook[i].getLastName());
		else
			std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getLastName() << "|";
		if ((phoneBook[i].getNickName()).size() >= 10)
			cutInfo(phoneBook[i].getNickName());
		else
			std::cout << std::setfill (' ') << std::setw (10) << phoneBook[i].getNickName() << "|" << std::endl;
		i++;
	}
}