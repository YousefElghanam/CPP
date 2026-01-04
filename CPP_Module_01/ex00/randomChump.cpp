#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	x(name);
	x.set_name(name);
	x.announce();
}
