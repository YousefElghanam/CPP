#include "main.hpp"

int main(void) {
	DiamondTrap	diaTrap("DIAMONDDDDDD");
	// ScavTrap	scaTrap("SCAVVVVV");

	diaTrap.beRepaired(20);
	diaTrap.guardGate();
	diaTrap.highFivesGuys();
	diaTrap.takeDamage(1);
	diaTrap.whoAmI();
	diaTrap.attack(">>TARGET<<");
	// std::cout << diaTrap.ClapTrap::name << std::endl;
	// std::cout << scaTrap.ClapTrap::name << std::endl;
	return 0;
}
