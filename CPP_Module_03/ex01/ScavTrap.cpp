#include "ScavTrap.hpp"
#include <iostream>
#include <stdint.h>

/* OCF */

ScavTrap::ScavTrap(void):
	ClapTrap() {
		std::cout << "ScavTrap Constructor called" << std::endl;
		this->hp = 100;
		this->energy = 50;
		this->ad = 20;
}

ScavTrap::ScavTrap(const std::string& name):
	ClapTrap(name) {
		std::cout << "ScavTrap Constructor(string) called" << std::endl;
		this->hp = 100;
		this->energy = 50;
		this->ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj):
	ClapTrap(obj) {
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << "ScavTrap Copy Assignment operator called => " << this->name << std::endl;
	if (this != &obj) {
		ClapTrap::operator=(obj);
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/* MEMBER FUNCTIONS */

void	ScavTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "I'm dead, idiot. I can't attack" << std::endl;
		return ;
	}
	if (this->energy == 0) {
		std::cout << "No energy to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target \
				<< ", causing " << this->ad << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->name << " is guarding the gate" << std::endl;
}
