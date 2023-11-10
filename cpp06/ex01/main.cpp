#include "Data.hpp"

int	main(void)
{
	Data		*data = new Data(10);
	uintptr_t	serializeValue;
	Data		*deserializeValue;

	serializeValue = data->serialize(data);
	deserializeValue = data->deserialize(serializeValue);

	std::cout << "Value before : " << data->getValue() << std::endl;
	std::cout << "Pointer data : " << data << std::endl;
	std::cout << "Serialize value : " << serializeValue << std::endl;
	std::cout << "Deserialize value : " << deserializeValue << std::endl;
	std::cout << "Value after : " << data->getValue() << std::endl;
	delete	data;
	return (0);
}