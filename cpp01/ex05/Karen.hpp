#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>
#include <iostream>

class   Karen {
	
private :

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	
public	:

	Karen(void);
	~Karen(void);
	void			complain(std::string level);
	void			(Karen::*f_level[5])();
};

#endif