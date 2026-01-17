#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const std::string& type):
type(type) {
	std::cout << "Animal Constructor(string) called" << std::endl;
}

Animal::Animal(const Animal& obj) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = obj;
}

Animal&				Animal::operator=(const Animal& obj) {
	std::cout << "Animal Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

void				Animal::setType(const std::string& newType) {
	this->type = newType;
}

const std::string&	Animal::getType(void) const {
	return this->type;
}

void				Animal::makeSound(void) const {
	std::cout << "AAAAA...." << std::endl;
}

void	Animal::think(void) const {
	std::cout << "* Hakuna Matata *" << std::endl;
}
