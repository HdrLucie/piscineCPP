#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
	const	Animal* meta = new Animal();
	const	Animal* dog = new Dog();
	const	Animal* cat = new Cat();

	std::cout << "Type : " << dog->getType() << " " << std::endl;
	std::cout << "Type : " << cat->getType() << " " << std::endl;
	std::cout << "Type : " << meta->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	delete	dog;
	delete	cat;
	delete	meta;

	const	WrongAnimal* wrongMeta = new WrongAnimal();
	const	WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete	wrongCat;
	delete	wrongMeta;
	return (0);
}