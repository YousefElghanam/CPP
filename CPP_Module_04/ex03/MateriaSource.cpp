#include <iostream>
#include <string>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

const unsigned int MateriaSource::materiaListCap = 4;

MateriaSource::MateriaSource(void):
	materiaListSize(0) {}

MateriaSource::~MateriaSource(void) {
	for (unsigned int i = 0; i < this->materiaListSize; i++) {
		delete this->materiaList[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj):
	materiaListSize(0) {
	*this = obj;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& obj) {
	if (this != &obj) {
		this->materiaListSize = obj.materiaListSize;
		for (unsigned int i = 0; i < MateriaSource::materiaListCap; i++) {
			if (this->materiaListSize > 0) {
				this->materiaListSize--;
			}
			this->materiaList[i] = obj.materiaList[i];
		}
	}
	return *this;
}

void			MateriaSource::learnMateria(AMateria* m) {
	if (this->materiaListSize == MateriaSource::materiaListCap) {
		return ;
	}
	this->materiaList[this->materiaListSize] = m;
	this->materiaListSize++;
}

AMateria*		MateriaSource::createMateria(const std::string& type) {
	// if (type != "ice" && type != "cure") {
	// 	return 0;
	// }
	for (unsigned int i = 0; i < this->materiaListSize; i++) {
		if (type == this->materiaList[i]->getType()) {
			return this->materiaList[i]->clone();
		}
	}
	std::cout << "unkown type from createMaterial()" << std::endl;
	return 0;
}

const AMateria*	MateriaSource::getMateria(unsigned int n) const {
	return this->materiaList[n];
}
