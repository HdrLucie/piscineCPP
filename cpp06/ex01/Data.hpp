#ifndef DATA_HPP
# define DATA_HPP

#ifndef	MSG
# define MSG 1
#endif

#include <string>
#include <iostream>
#include <stdint.h>

class Data {

private:
	int	_value;
public:
	Data(int value);
	Data(const Data &src);
	Data	&operator=(const Data &rhs);
	virtual ~Data(void);

	int			getValue() const;
	uintptr_t	serialize(Data *ptr);
	Data		*deserialize(uintptr_t raw);
};

#endif