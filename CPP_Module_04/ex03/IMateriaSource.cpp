#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource;

IMateriaSource::IMateriaSource(void) {}

IMateriaSource::~IMateriaSource(void) {}

IMateriaSource::IMateriaSource(const IMateriaSource& obj) {
	*this = obj;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& obj) {
	std::cout << "copying IMateriaSource" << std::endl;
	(void)obj;
	return *this;
}

// IMateriaSource&	IMateriaSource::operator=(const MateriaSource& obj) {
// 	return *this;
// }
