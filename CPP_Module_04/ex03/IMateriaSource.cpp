#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void) {}

IMateriaSource::~IMateriaSource(void) {}

IMateriaSource::IMateriaSource(const IMateriaSource& obj) {
	*this = obj;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& obj) {
	(void)obj;
	return *this;
}
