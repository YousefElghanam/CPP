#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type):
	type(type) {
	std::cout << "WrongAnimal Constructor(string) called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = obj;
}

WrongAnimal&				WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "WrongAnimal Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void				WrongAnimal::makeSound(void) const {
	std::cout << "AAAAA...." << std::endl;
}

void				WrongAnimal::setType(const std::string& newType) {
	this->type = newType;
}

const std::string&	WrongAnimal::getType(void) const {
	return this->type;
}
