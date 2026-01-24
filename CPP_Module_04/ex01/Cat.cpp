#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void): 
	brain(new Brain) {
	std::cout << "Cat Constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const std::string& type):
	brain(new Brain("Cat " + type + "'s Thoughts")) {
	std::cout << "Cat Constructor(string) called" << std::endl;
	this->setType("Cat " + type);
}

Cat::Cat(const Cat& obj):
	Animal(obj), brain(new Brain(*obj.brain)) {
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& obj) {
	std::cout << "Cat Copy Assignment called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound(void) const {
	std::cout << "MEOW MEOW!!" << std::endl;
}

void	Cat::think(void) const {
	std::cout << this->brain->getRandomIdea() << std::endl;
}
