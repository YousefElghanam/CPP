#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat Constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const std::string& type){
	std::cout << "Cat Constructor(string) called" << std::endl;
	this->setType("Cat " + type);
}

Cat::Cat(const Cat& obj): Animal(obj) {
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj) {
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "MEOW MEOW!!" << std::endl;
}
