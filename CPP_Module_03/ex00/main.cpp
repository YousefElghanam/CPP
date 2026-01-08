#include "main.hpp"
#include <stdint.h>

int main(void) {
	ClapTrap	namnam("Namnam");
	ClapTrap	twitch("Twitch");
	ClapTrap	noname;
	ClapTrap	a("A");
	ClapTrap	b = a;
	ClapTrap	c;
	ClapTrap	d(a);
	c = a;
	std::cout << "=================================" << std::endl;
	namnam.attack("THE_TARGET");
	namnam.attack("THE_OTHER_TARGET");
	twitch.attack("Namnam");
	namnam.takeDamage(1);
	namnam.takeDamage(9);
	c.beRepaired(1);
	c.beRepaired(UINT32_MAX - 1);
	c.beRepaired(UINT32_MAX);
	return 0;
}
