#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void) {
	this->name = "";
	std::cout << "++Zombie (" << name << ") created" << std::endl; 
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "++Zombie (" << name << ") created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "--Zombie (" << this->name << ") destroyed" << std::endl;
}

void		Zombie::set_name(std::string name) {
	std::cout << ">>Setting (" << this->name << ")'s name to (" << name << ")" << std::endl;
	this->name = name;
}

std::string	Zombie::get_name(void) {
	return this->name;
}

void		Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
