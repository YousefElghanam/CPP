#include <cstdlib>
#include <string>
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

const unsigned int	Character::inventoryCap = 4;

Character::Character(void): 
	inventorySize(0) {
	for (unsigned int i = 0; i < Character::inventoryCap; i++) {
		this->inventory[i] = NULL;
	}
}

Character::~Character(void) {
	for (unsigned int i = 0; i < Character::inventoryCap; i++) {
		delete this->inventory[i];
	}
}

Character::Character(const std::string& name):
	name(name), inventorySize(0) {
	for (unsigned int i = 0; i < Character::inventoryCap; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character& obj):
	ICharacter() {
	*this = obj;
}

Character&			Character::operator=(const Character& obj) {
	if (this != &obj) {
		for (unsigned int i = 0; i < Character::inventoryCap; i++) {
			if (obj.inventory[i]) {
				this->inventory[i] = obj.inventory[i]->clone();
			}
			else {
				this->inventory[i] = NULL;
			}
		}
		this->name = obj.name;
		this->inventorySize = obj.inventorySize;
	}
	return *this;
}

const std::string&	Character::getName(void) const {
	return this->name;	
}

void				Character::equip(AMateria* m) {
	if (this->inventorySize == Character::inventoryCap || !m) {
		delete m;
		return ;
	}
	for (unsigned int i = 0; i < Character::inventoryCap; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m->clone();
			this->inventorySize++;
			break ;
		}
	}
	delete m;
}

void				Character::unequip(int idx) {
	if (idx < 0 || (unsigned int)idx >= Character::inventoryCap) {
		return ;
	}
	delete this->inventory[idx];
	this->inventory[idx] = NULL;
	this->inventorySize--;
}

void				Character::use(int idx, ICharacter& target) {
	if (idx < 0 || this->inventory[idx] == NULL) {
		return ;
	}
	this->inventory[idx]->use(target);
}
