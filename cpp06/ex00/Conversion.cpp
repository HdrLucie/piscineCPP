#include "Conversion.hpp"
#include <cstdlib>
#include <limits>
#include <climits>
#include <iomanip>
#include <cstring> 

Conversion::Conversion(std::string &input) : _inputToConvert(input) {

	if (MSG)
		std::cout << "Conversion constructor called" << std::endl;
	return ;
}

Conversion::Conversion(const Conversion &src) : _inputToConvert(src._inputToConvert) {

	if (MSG)
		std::cout << "Conversion copy constructor called" << std::endl;
	return ;
}

Conversion  &Conversion::operator=(const Conversion &rhs)
{
	if (MSG)
		std::cout << "Operator overloading called" << std::endl;
	(void)rhs;
	return (*this);
}

Conversion::~Conversion(void)
{
	if (MSG)
		std::cout << "Conversion destructor called" << std::endl;
}

void	Conversion::printFloat(double value)
{
	this->_charValue = static_cast<char>(value);
	if ((value >= 32 && value <= 47) || (value >= 58 && value <= 127))
		std::cout << "char : '" << this->_charValue << "'" << std::endl;
	else if (value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : Not displayable" << std::endl;
	this->_intValue = static_cast<int>(value);
	if (this->_intValue <= std::numeric_limits<int>::min() 
	|| this->_intValue >= std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << this->_intValue << std::endl;
	this->_floatValue = static_cast<float>(value);
	if ((this->_floatValue < std::numeric_limits<float>::min() 
	|| this->_floatValue > std::numeric_limits<float>::max()) && this->_floatValue != 0)
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : "  << std::fixed << std::showpoint << std::setprecision(1) << this->_floatValue << "f" << std::endl;
	this->_doubleValue = static_cast<double>(value);
	std::cout << "double : " << std::fixed << std::showpoint << std::setprecision(1) << this->_doubleValue << std::endl;
	return ;
}

void	Conversion::printInt(double value)
{
	this->_charValue = static_cast<char>(value);
	if ((value >= 32 && value <= 47) || (value >= 58 && value <= 127))
		std::cout << "char : '" << this->_charValue << "'" << std::endl;
	else if (value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : Not displayable" << std::endl;
	this->_intValue = static_cast<int>(value);
	if (this->_intValue <= std::numeric_limits<int>::min() 
	|| this->_intValue >= std::numeric_limits<int>::max())
		std::cout << "int : Impossible" << std::endl;
	else
		std::cout << "int : " << this->_intValue << std::endl;
	this->_floatValue = static_cast<float>(value);
	std::cout << "float : "  << std::fixed << std::showpoint << std::setprecision(1) << this->_floatValue << "f" << std::endl;
	this->_doubleValue = static_cast<double>(value);
	std::cout << "double : " << std::fixed << std::showpoint << std::setprecision(1) << this->_doubleValue << std::endl;
	return ;
}

void	Conversion::printChar()
{
	this->_charValue = static_cast<char>(_inputToConvert[0]);
	if ((this->_charValue >= 32 && this->_charValue <= 47)
	|| (this->_charValue >= 58 && this->_charValue <= 127))
		std::cout << "char : '" << this->_charValue << "'" << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	this->_intValue = static_cast<int>(_inputToConvert[0]);
	std::cout << "int : " << this->_intValue << std::endl;
	this->_floatValue = static_cast<float>(_inputToConvert[0]);
	std::cout << "float : " << this->_floatValue << ".0f" << std::endl;
	this->_doubleValue = static_cast<double>(_inputToConvert[0]);
	std::cout << "double : " << this->_doubleValue << ".0" <<std::endl;
	return ;
}

void	Conversion::printDouble(double value)
{
	this->_charValue = static_cast<char>(value);
	if ((value >= 32 && value <= 47) || (value >= 58 && value <= 127))
		std::cout << "char : '" << this->_charValue << "'" << std::endl;
	else if (value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "char : Not displayable" << std::endl;	
	this->_intValue = static_cast<int>(value);
	if (this->_intValue <= std::numeric_limits<int>::min() 
	|| this->_intValue >= std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << this->_intValue << std::endl;
	this->_floatValue = static_cast<float>(value);
	if ((this->_floatValue < std::numeric_limits<float>::min() 
	|| this->_floatValue > std::numeric_limits<float>::max()) && this->_floatValue != 0)
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : "  << std::fixed << std::showpoint << std::setprecision(1) << this->_floatValue << "f" << std::endl;
	this->_doubleValue = static_cast<double>(value);
	if ((this->_doubleValue < std::numeric_limits<double>::min() 
	|| this->_doubleValue > std::numeric_limits<double>::max()) && this->_doubleValue != 0)
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::showpoint << std::setprecision(1) << this->_doubleValue << std::endl;
	return ;
}

void	Conversion::printConvert()
{
	this->_type = whichType();
	double	value;

	value = std::atof(_inputToConvert.c_str());
	if (this->_type == 0)
		return ;
	if (this->_type == 1)
		printChar();
	else if (this->_type == 2)
		printFloat(value);
	else if (this->_type == 3)
		printDouble(value);
	else if (this->_type == 4)
		printInt(value);
}

int	Conversion::whichType()
{
	int	floatFlag;
	int	pointFlag;
	std::string	weirdInputsFloat [3] = {"-inff", "+inff", "nanf"};
	std::string	weirdInputsDouble [3] = {"-inf", "+inf", "nan"};
	floatFlag = 0;
	pointFlag = 0;
	for (int i = 0; i < 3; i++)
	{
		if (!(std::strncmp(this->_inputToConvert.c_str(), weirdInputsFloat[i].c_str(), 3)))
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : " << weirdInputsFloat[i] << std::endl;
			std::cout << "double : " << weirdInputsDouble[i] << std::endl;
			return (0);
		}
	}
	if (((this->_inputToConvert[0] >= 32 && this->_inputToConvert[0] <= 47)
	|| (this->_inputToConvert[0] >= 58 && this->_inputToConvert[0] <= 127))
	&& this->_inputToConvert.size() == 1)
		return (1);
	for (size_t i = 0; i < _inputToConvert.size(); i++)
		if (_inputToConvert[i] == 'f')
			return (2);
	for (size_t i = 0; i < _inputToConvert.size(); i++)
	{
		if (_inputToConvert[i] == '.')
			return (3);
	}
	return (4);
}