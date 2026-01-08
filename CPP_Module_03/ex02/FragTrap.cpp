#include "FragTrap.hpp"
#include <iostream>
#include <stdint.h>

/* OCF */

FragTrap::FragTrap(void):
	ClapTrap() {
		std::cout << "FragTrap Constructor called" << std::endl;
		this->hp = 100;
		this->energy = 100;
		this->ad = 30;
}

FragTrap::FragTrap(const std::string& name):
	ClapTrap(name) {
		std::cout << "FragTrap Constructor(string) called" << std::endl;
		this->hp = 100;
		this->energy = 100;
		this->ad = 30;
}

FragTrap::FragTrap(const FragTrap& obj):
	ClapTrap(obj) {
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	std::cout << "FragTrap Copy Assignment operator called => " << this->name << std::endl;
	if (this != &obj) {
		ClapTrap::operator=(obj);
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called" << std::endl;
}

/* MEMBER FUNCTIONS */

void	FragTrap::attack(const std::string& target) {
	if (this->hp == 0) {
		std::cout << "I'm dead, idiot. I can't attack" << std::endl;
		return ;
	}
	if (this->energy == 0) {
		std::cout << "No energy to attack" << std::endl;
		return ;
	}
	this->energy -= 1;
	std::cout << "FragTrap " << this->name << " attacks " << target \
				<< ", causing " << this->ad << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " requesting high-fives" << std::endl;
}
