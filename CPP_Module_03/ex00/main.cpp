#include "main.hpp"

int main(void) {
	ClapTrap	namnam("Namnam");
	ClapTrap	twitch("Twitch");
	ClapTrap	noname;
	ClapTrap	a;
	ClapTrap	b(a);
	std::cout << "doing c = a >> =================" << std::endl;
	ClapTrap	c = a;
	std::cout << "doing c = a >> =================" << std::endl;

	namnam.attack("THE_TARGET");
	// namnam.attack("THE_OTHER_TARGET");
	twitch.attack("Namnam");
	namnam.takeDamage(0);
	c.beRepaired(2000);
	return 0;
}
