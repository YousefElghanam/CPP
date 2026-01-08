#include "ClapTrap.hpp"
#include <iostream>
#include <stdint.h>

ClapTrap::ClapTrap(void):
	hp(10), energy(10), ad(0) {
		std::cout << "ClapTrap Constructor called" << std::endl;
	}

ClapTrap::ClapTrap(const std::string& name):
	name(name), hp(10), energy(10), ad(0) {
		std::cout << "ClapTrap Constructor called => " << this->name << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = obj;
}

const ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	std::cout << "ClapTrap Copy Assignment operator called => " << this->name << std::endl;
	this->name = obj.name;
	this->hp = obj.hp;
	this->energy = obj.energy;
	this->ad = obj.ad;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void			ClapTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "I'm dead, idiot. I can't attack" << std::endl;
		return ;
	}
	if (this->energy == 0) {
		std::cout << "No energy to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target \
				<< ", causing " << this->ad << " points of damage!" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp == 0) {
		std::cout << "Stop! he's already dead! D:" << std::endl;
		return ;
	}
	if (amount > this->hp)
		this->hp = 0;
	else
		this->hp -= amount;
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage";
	if (this->hp == 0)
		std::cout << " and died!" << std::endl;
	else
		std::cout << "!" << std::endl;
}
void			ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp == 0) {
		std::cout << "I'm dead, idiot. I can't do anything" << std::endl;
		return ;
	}
	if (this->energy == 0) {
		std::cout << "Not enough energy to repair" << std::endl;
		return ;
	}
	this->energy -= 1;
	if (UINT32_MAX - amount < this->hp) {
		this->hp = UINT32_MAX;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " \
					<< amount << " hitpoints and reached the max hp cap!" << std::endl;
	}
	else {
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " \
					<< amount << " hitpoints!" << std::endl;
	}
}
