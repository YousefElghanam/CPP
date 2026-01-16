#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog Constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const std::string& type){
	std::cout << "Dog Constructor(string) called" << std::endl;
	this->setType("Dog " + type);
}

Dog::Dog(const Dog& obj): Animal(obj) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "WOOF WOOF!!" << std::endl;
}
