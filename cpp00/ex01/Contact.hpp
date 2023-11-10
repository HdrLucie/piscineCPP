#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class	Contact {

private :
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public :
	Contact(void);
	~Contact(void);

	int		getInfo();
	const	std::string &getFirstName();
	const	std::string &getLastName();
	const	std::string &getNickName();
	const	std::string &getPhoneNumber();
	const	std::string &getDarkSecret();
};

#endif