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

MateriaSource::MateriaSource(const MateriaSource& obj) {
	*this = obj;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& obj) {
	std::cout << "assigning ==== MateriaSource" << std::endl;
	if (this != &obj) {
		for (unsigned int i = 0; i < MateriaSource::materiaListCap && i < obj.materiaListSize; i++) {
			// if (this->materiaListSize > 0) {
			// 	this->materiaListSize--;
			// }
			std::cout << "assigning " << obj.materiaList[i]->getType() << " in idx " << i << std::endl;
			this->materiaList[i] = obj.materiaList[i];
		}
		this->materiaListSize = obj.materiaListSize;
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
		std::cout << "IDX: " << i << "\n";
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
