#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n---- Other tests ----\n Arithmetic operators\n" << std::endl;
	Fixed	c = 10.5f;
	Fixed	d = 2;

	std::cout << c << " + " << d << " = " << c + d << std::endl;
	std::cout << c << " - " << d << " = " << c - d << std::endl;
	std::cout << d << " - " << c << " = " << d - c << std::endl;
	std::cout << c << " * " << d << " = " << c * d << std::endl;
	std::cout << c << " / " << d << " = " << c / d << std::endl;

	std::cout << "\nmax between " << c << " et " << d << " : " << Fixed::max( c, d ) << std::endl;
	std::cout << "min between " << c << " et " << d << " : " << Fixed::min( c, d ) << std::endl;
	
	std::cout << "\n Comparaison operators\n" << std::endl;
	std::cout << c << " est-il plus petit que " << d << " ?" << std::endl;
	if (c < d)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il plus grand que " << d << " ?" << std::endl;
	if (c > d)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il superieur ou egal a " << d << " ?" << std::endl;
	if (c >= d)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il inferieur ou egal a " << d << " ?" << std::endl;
	if (c <= d)
		std::cout << "NON" << std::endl;
	else 
		std::cout << "OUI" << std::endl;
	std::cout << c << " est-il egal a " << d * 5.25f << " ?" << std::endl;
	if (c == d * 5.25f)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il egal a " << d << " ?" << std::endl;
	if (c == d)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il different de " << d << " ?" << std::endl;
	if (c != d)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	std::cout << c << " est-il different de " << d * 5.25f << " ?" << std::endl;
	if (c != d * 5.25f)
		std::cout << "OUI" << std::endl;
	else 
		std::cout << "NON" << std::endl;
	return (0);
}