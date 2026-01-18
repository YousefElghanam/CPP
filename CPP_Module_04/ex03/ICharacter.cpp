#include "ICharacter.hpp"

ICharacter::ICharacter(void) {}

ICharacter::~ICharacter(void) {}

ICharacter::ICharacter(const ICharacter& obj) {
	*this = obj;
}

ICharacter&	ICharacter::operator=(const ICharacter& obj) {
	(void)obj;
	return *this;
}
