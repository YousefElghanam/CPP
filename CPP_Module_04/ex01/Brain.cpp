#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Constructor called" << std::endl;
	for (unsigned int i = 0; i < ideasCount; i++) {
		this->ideas[i] = "Default Idea";
	}
}

Brain::Brain(const std::string& idea) {
	std::cout << "Brain Constructor called" << std::endl;
	for (unsigned int i = 0; i < ideasCount; i++) {
		this->ideas[i] = idea;
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
