#include <iostream>

#include "main.hpp"

// int main()
// {
// {
// Weapon club = Weapon("crude spiked club");
// HumanA bob("Bob", club);
// bob.attack();
// club.setType("some other type of club");
// bob.attack();
// }
// {
// Weapon club = Weapon("crude spiked club");
// HumanB jim("Jim");
// jim.setWeapon(club);
// jim.attack();
// club.setType("some other type of club");
// jim.attack();
// }
// return 0;
// }

int main(void)
{
	std::cout << "================================" << std::endl;
	Weapon		A_weapon("club");
	Weapon		A_alt_weapon("small club");
	Weapon		B_weapon("axe");
	HumanA		A("A", A_weapon);
	HumanB		B("B");

	A.attack();
	B.attack();
	std::cout << "================================" << std::endl;
	B.setWeapon(B_weapon);
	std::cout << "================================" << std::endl;
	A.attack();
	B.attack();
	return 0;
}
