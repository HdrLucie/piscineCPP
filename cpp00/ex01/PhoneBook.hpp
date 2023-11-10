/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:20:21 by hlucie            #+#    #+#             */
/*   Updated: 2022/01/14 15:23:50 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <clocale>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "Contact.hpp"

class PhoneBook {

private:
	Contact	phoneBook[8];
public: 

	PhoneBook(void);
	~PhoneBook(void);
	int			nbContact;
	void		addContact();
	void		searchInfo();
	int			trackInfo();
};

#endif