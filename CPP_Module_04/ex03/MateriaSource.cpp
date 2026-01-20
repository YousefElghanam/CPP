#include <iostream>
#include <string>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
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
	IMateriaSource() {
	*this = obj;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& obj) {
	if (this != &obj) {
		// std::cout << "listSize is: " << this->materiaListSize << std::endl;
		// for (unsigned int i = 0; i < this->materiaListSize; i++) {
		// 	delete this->materiaList[i];
		// }
		for (unsigned int i = 0; i < obj.materiaListSize; i++) {
			this->materiaList[i] = obj.materiaList[i]->clone();
		}
		this->materiaListSize = obj.materiaListSize;
	}
	return *this;
}

void			MateriaSource::learnMateria(AMateria* m) {
	if (this->materiaListSize == MateriaSource::materiaListCap) {
		delete m;
		return ;
	}
	this->materiaList[this->materiaListSize] = m->clone();
	this->materiaListSize++;
	delete m;
}

AMateria*		MateriaSource::createMateria(const std::string& type) {
	for (unsigned int i = 0; i < this->materiaListSize; i++) {
		if (type == this->materiaList[i]->getType()) {
			return this->materiaList[i]->clone();
		}
	}
	return 0;
}
