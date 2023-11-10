#include "whatever.hpp"

int	main(void)
{

	{
		int a = 2;
		int b = 3;
		std::cout << "Before swap - a : " << a << " b : " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before swap - a : " << c << " b : " << d << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		int	x;
		int	y;

		x = 10;
		y = 5;
		std::cout << "\n- - - - - - - - -\n     WITH INT\n- - - - - - - - -" << std::endl;
		std::cout << "x : " << x << " & y : " << y << std::endl; 
		std::cout << "Min : " << ::min(x, y) << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
		::swap(x, y);
		std::cout << "Swap - x : " << x << " - y : " << y << "\n" << std::endl;
	}
	{
		float	x;
		float	y;

		x = -7.095f;
		y = 12.65f;
		std::cout << "- - - - - - - - -\n   WITH FLOAT\n- - - - - - - - -" << std::endl;
		std::cout << "x : " << x << " & y : " << y << std::endl; 
		std::cout << "Min : " << ::min(x, y) << std::endl;
		std::cout << "Max : " << ::max(x, y) << std::endl;
		::swap(x, y);
		std::cout << "Swap - x : " << x << " - y : " << y << "\n" << std::endl;
	}
	{
		std::string	s1;
		std::string	s2;

		s1 = "Bonjour les p'tits potes";
		s2 = "Salut les boys";
		std::cout << "- - - - - - - - -\n    WITH STRING\n- - - - - - - - -" << std::endl;
		std::cout << "s1 : " << s1 << " & s2 : " << s2 << std::endl; 
		std::cout << "Min : " << ::min(s1, s2) << std::endl;
		std::cout << "Max : " << ::max(s1, s2) << std::endl;
		::swap(s1, s2);
		std::cout << "Swap - s1 : " << s1 << " - s2 : " << s2 << std::endl;
	}
	return (0);
}