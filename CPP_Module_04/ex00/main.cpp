#include "main.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {
	Animal	generic;
	Dog		myDog;

	generic.makeSound();
	myDog.makeSound();
	return 0;
}
