#include "main.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal	animals[100];
	for (int i = 0; i < 50; i++) {
		animals[i] = Dog();
	}
	for (int i = 50; i < 100; i++) {
		animals[i] = Cat();
	}
	for (int i = 0; i < 100; i++) {
		animals[i].getType();
		animals[i].makeSound();
		
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
