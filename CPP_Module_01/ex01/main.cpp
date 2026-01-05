#include <iostream>

#include "main.hpp"

#include <cstdlib>
int main(void)
{
	std::cout << "================================" << std::endl;
	Zombie		y("zombieY");
	std::cout << "tring to get name (" << y.get_name() << ")" << std::endl;
	y.announce();
	std::cout << "================================" << std::endl;

	Zombie		*horde = zombieHorde(5, "ONE_HORDE");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	delete []horde;
	std::cout << "================================" << std::endl;
	return 0;
}
