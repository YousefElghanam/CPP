#include <iostream>
#include <string>
#include "Character.hpp"
#include "AMateria.hpp"

const unsigned int	Character::inventoryCap = 4;

Character::Character(void): 
	inventorySize(0) {}

Character::~Character(void) {
	for (unsigned int i = 0; this->inventorySize; i++) {
		delete this->inventory[i];
	}
}

Character::Character(const std::string& name):
	name(name), inventorySize(0) {}

Character::Character(const Character& obj) {
	*this = obj;
}

Character&			Character::operator=(const Character& obj) {
	if (this != &obj) {
		for (unsigned int i = 0; i < Character::inventoryCap; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
				this->inventory[i] = 0;
				// this->inventorySize--;
			}
			this->name = obj.name;
			this->inventory[i] = obj.inventory[i]->clone();
		}
		this->inventorySize = obj.inventorySize;
	}
	return *this;
}

const std::string&	Character::getName(void) const {
	return this->name;	
}

void				Character::equip(AMateria* m) {
	// std::cout << this->inventorySize << "===" << Character::inventoryCap << std::endl;
	if (this->inventorySize == Character::inventoryCap) {
		return ;
	}
	// std::cout << "equiping Materia " << m->getType() << std::endl;
	this->inventory[this->inventorySize] = m->clone();
	this->inventorySize++;
}

void				Character::unequip(int idx) {
	if (idx < 0 || (unsigned int)idx >= this->inventorySize) {
		return ;
	}
	delete this->inventory[idx];
	this->inventorySize--;
}

void				Character::use(int idx, ICharacter& target) {
	if (idx < 0 || (unsigned int)idx >= this->inventorySize) {
		return ;
	}
	this->inventory[idx]->use(target);
}
