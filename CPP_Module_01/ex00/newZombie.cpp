#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie*	ptr = new Zombie(name);
	ptr->set_name(name);
	return (ptr);
}
