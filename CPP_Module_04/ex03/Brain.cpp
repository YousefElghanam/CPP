#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Constructor called" << std::endl;
	for (unsigned int i = 0; i < ideasCount; i++) {
		this->ideas[i] = "Default Idea";
	}
}

Brain::Brain(const std::string& animalType) {
	std::cout << "Brain Constructor called" << std::endl;
	if (animalType == "Dog") {
		initDogThoughts();
	}
	else if (animalType == "Cat") {
		initCatThoughts();
	}
	else {
		for (unsigned int i = 0; i < Brain::ideasCount; i++) {
			this->ideas[i] = "Unknown animal's idea";
		}
	}
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = obj;
}

Brain&				Brain::operator=(const Brain& obj) {
	std::cout << "Brain Copy Assignment called" << std::endl;
	if (this != &obj) {
		for (unsigned int i = 0; i < ideasCount; i++) {
			this->ideas[i] = obj.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called" << std::endl;
}

void	Brain::setIdeas(std::string newIdeas[Brain::ideasCount]) {
	for (unsigned int i = 0; i < Brain::ideasCount; i++) {
		this->ideas[i] = newIdeas[i];
	}
}

const std::string&	Brain::getRandomIdea(void) const {
	return this->ideas[std::rand() % Brain::ideasCount];
}

void	Brain::initDogThoughts(void) {
	fillDogThoughts(this);
}

void	Brain::initCatThoughts(void) {
	fillCatThoughts(this);
}
