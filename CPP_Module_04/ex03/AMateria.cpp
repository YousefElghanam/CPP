#include <string>
#include "AMateria.hpp"

AMateria::AMateria(const std::string& type):
	type(type) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(const AMateria& obj) {
	*this = obj;
}

AMateria&	AMateria::operator=(const AMateria& obj) {
	if (this != &obj) {
		this->type = obj.type;
	}
	return *this;
}

const std::string&	AMateria::getType(void) const {
	return this->type;
}
