#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main (void)
{
	Animal 	*animal[5];

	for (int i = 0; i < 5; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << "\n- - - - - - - - - -\nGet some types...\n- - - - - - - - - -\n" << std::endl;
	std::cout << "Index - 0 : " << animal[0]->getType() << std::endl;
	std::cout << "Index - 13 : " << animal[1]->getType() << std::endl;	
	std::cout << "Index - 48 : " << animal[2]->getType() << std::endl;
	std::cout << "Index - 99 : " << animal[3]->getType() << std::endl;
	std::cout << "\n- - - - - - - - - -\nGet some actions...\n- - - - - - - - - -\n" << std::endl;

	for (int i = 0; i < 5; i++)
		std::cout << animal[i]->getType() << " " << i << " " << animal[i]->getIdeas(i) << std::endl;

	std::cout << "\n- - - - - - - - - -\nDeep copies...\n- - - - - - - - - -\n" << std::endl;
	std::cout << "Before assignement - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;
	*(animal[0]) = *(animal[1]);
	std::cout << "After assignement - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;
	animal[1]->setIdeas("Random ideas", 0);
	std::cout << "Change idea of src - " << animal[0]->getType() << " [0] : " << animal[0]->getIdeas(0) << " "
	<< animal[1]->getType() << " | [1] : " << animal[1]->getIdeas(0) << std::endl;
	
/*
**	Test for deep copy, if it's shallow copy, if I delete the src, copy is delete too.
** 	std::cout << "Test delete : erase src animal[1] " << std::endl;
** 	delete animal[1];
** 	std::cout << "Copy still exixts - type :  " << animal[0]->getType() << " idea : "
** 	<< animal[0]->getIdeas(0) << std::endl;
*/

	std::cout << "\n" << std::endl;
	Dog test;
	Dog test1 = test;
	Dog test3;

	std::cout << "Test : " << test.getIdeas(0) << "\n" 
	<< "Test1 : " << test1.getIdeas(0) << std::endl;

	test.setIdeas("I'm dog", 0);
	test1.setIdeas("Other idea", 0);

	std::cout << "Test : " << test.getIdeas(0)  << "\n" 
	<< "Test1 : " << test1.getIdeas(0) << std::endl;
	
	std::cout << "\nTest1 : " << test1.getIdeas(0) << "\n" 
	<< "Test3 : " << test3.getIdeas(0) << std::endl;
	test3 = test1;
	test1.setIdeas("Test1 idea, other", 0);	
	std::cout << "Test1 : " << test1.getIdeas(0) << "\n" 
	<< "Test3 : " << test3.getIdeas(0) << "\n" << std::endl;
	for (int i = 0; i < 5; i++)
			delete animal[i];
	return (0);
}