#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));
	const Animal* myDog = new Dog("newDog");
	std::cout << "================================================" << std::endl;
	myDog->think();
	myDog->think();
	myDog->think();
	myDog->think();
	std::cout << "================================================" << std::endl;
	delete myDog;
	std::cout << "================================================" << std::endl;
	const Animal* myCat = new Cat("newCat");
	std::cout << "================================================" << std::endl;
	myCat->think();
	myCat->think();
	myCat->think();
	myCat->think();
	std::cout << "================================================" << std::endl;
	delete myCat;
}

// int main()
// {
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;//should not create a leak
// delete i;
// return 0;
// }
