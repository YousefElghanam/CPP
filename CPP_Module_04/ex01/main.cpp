#include <iostream>
#include "main.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal*	animals[4];
	for (int i = 0; i < 2; i++) {
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; i++) {
		animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++) {
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		animals[i]->think();
	}
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	return 0;
}

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// return 0;
// }
