#include <cstdlib>
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void):
	brain(new Brain) {
	std::cout << "Dog Constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const std::string& type):
	brain(new Brain("Dog " + type + "' Thoughts")) {
	std::cout << "Dog Constructor(string) called" << std::endl;
	this->setType("Dog " + type);
}

Dog::Dog(const Dog& obj):
	Animal(obj), brain(obj.brain) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
		this->brain = obj.brain;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const {
	std::cout << "WOOF WOOF!!" << std::endl;
}

void	Dog::think(void) const {
	std::cout << 
}
