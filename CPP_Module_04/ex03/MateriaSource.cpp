#include <string>
#include "MateriaSource.hpp"
#include "AMateria.hpp"

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
				delete this->materiaList[i];
				this->materiaListSize--;
			}
			this->materiaList[i] = obj.materiaList[i]->clone();
		}
	}
	return *this;
}

void			MateriaSource::learnMateria(AMateria* m) {
	if (this->materiaListSize == MateriaSource::materiaListCap) {
		return ;
	}
	this->materiaList[this->materiaListSize] = m->clone();
	this->materiaListSize++;
}

AMateria*		MateriaSource::createMateria(const std::string& type) {
	for (unsigned int i = 0; i < this->materiaListSize; i++) {
		if (type == this->materiaList[i]->getType()) {
			return this->materiaList[i]->clone();
		}
	}
	return 0;
}
