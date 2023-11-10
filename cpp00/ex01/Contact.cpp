/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:49:06 by hlucie            #+#    #+#             */
/*   Updated: 2022/01/14 16:23:39 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"  

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_phoneNumber = "";
	this->_nickname = "";
	this->_darkestSecret = "";
	return ;
}

Contact::~Contact()
{
	return ;
}

int	Contact::getInfo()
{
	std::cout << "ENTER YOUR FIRST NAME :" << std::endl;
	std::getline(std::cin, this->_firstName);
	if (std::cin.eof())
		return (0);
	std::cout << "ENTER YOUR LAST NAME :" << std::endl;
	std::getline(std::cin, this->_lastName);
	if (std::cin.eof())
		return (0);
	std::cout << "ENTER YOUR NICKNAME :" << std::endl;
	std::getline(std::cin, this->_nickname);
	if (std::cin.eof())
		return (0);
	std::cout << "ENTER YOUR PHONE NUMBER :" << std::endl;
	std::getline(std::cin, this->_phoneNumber);
	if (std::cin.eof())
		return (0);
	std::cout << "ENTER YOUR DARKEST SECRET :" << std::endl;
	std::getline(std::cin, this->_darkestSecret);
	if (std::cin.eof())
		return (0);
	return (1);
}

const std::string	&Contact::getFirstName()
{
	return (this->_firstName);
}

const std::string	&Contact::getLastName()
{
	return (this->_lastName);
}

const std::string	&Contact::getNickName()
{
	return (this->_nickname);
}

const std::string	&Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

const std::string	&Contact::getDarkSecret()
{
	return (this->_darkestSecret);
}