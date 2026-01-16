#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat Constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const std::string& type){
	std::cout << "WrongCat Constructor(string) called" << std::endl;
	this->setType("WrongCat " + type);
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal(obj) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& obj) {
	std::cout << "WrongCat Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "MEOW MEOW!!" << std::endl;
}
