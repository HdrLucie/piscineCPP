#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main (void)
{
	AAnimal				*animal[10];
	// AAnimal				*simple_animal = new AAnimal();
	// See message when compile.
	const	AAnimal		*dog = new Dog();
	const	AAnimal		*cat = new Cat();

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Dog;
		else
			animal[i] = new Cat;
	}
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << animal[0]->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();
	animal[0]->makeSound();
	animal[6]->makeSound();

	std::cout << "\n- - - - - - - - - -\nDeep copies...\n- - - - - - - - - -\n" << std::endl;
	std::cout << "Before assignement - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;
	*(animal[0]) = *(animal[1]);
	std::cout << "After assignement - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;
	animal[1]->setIdeas("Random ideas", 0);
	std::cout << "Change idea of src - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;

	delete	dog;
	delete	cat;
	for (int i = 0; i < 10; i++)
		delete animal[i];
	const	WrongAnimal* wrongMeta = new WrongAnimal();
	const	WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete	wrongCat;
	delete	wrongMeta;
	return (0);
}