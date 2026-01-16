#include "main.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
const Animal* meta = new Animal();
// const WrongAnimal* meta = new WrongAnimal();
const Animal* j = new Dog();
const Animal* i = new Cat();
// const WrongAnimal* i = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << "==========================================" << std::endl;
i->makeSound(); //will output the cat sound! (NOT IF IT'S Wrong..)
j->makeSound();
meta->makeSound();
std::cout << "==========================================" << std::endl;
delete meta;
delete j;
delete i;
return 0;
}
// int main(void) {
// 	Animal	generic;
// 	Dog		myDog;
// 	Cat		myCat;

// 	std::cout << "==========================================" << std::endl;
// 	generic.makeSound();
// 	myDog.makeSound();
// 	myCat.makeSound();
// 	std::cout << "==========================================" << std::endl;
// 	return 0;
// }
