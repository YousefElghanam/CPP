#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const std::string& type){
	std::cout << "Dog Constructor(string) called" << std::endl;
	this->type = "Dog " + type;
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = obj;
}

Dog&	Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound(void) {
	std::cout << "WOOF WOOF!!" << std::endl;
}
