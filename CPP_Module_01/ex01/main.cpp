#include <iostream>

#include "main.hpp"

int main(void)
{
	std::cout << "================================" << std::endl;
	Zombie		y("zombieY");
	std::cout << "tring to get name (" << y.get_name() << ")" << std::endl;
	y.announce();
	std::cout << "================================" << std::endl;

	Zombie		*horde = zombieHorde(5, "ONE_HORDE");
	for (int i = 0; i < 5; i++) {
		std::cout << "iteration (" << i << "): ";
		horde[i].announce();
	}
	/* just to see in what order are they destroyed when using delete[] */
	horde[0].set_name("0");
	horde[1].set_name("1");
	horde[2].set_name("2");
	horde[3].set_name("3");
	horde[4].set_name("4");
	delete []horde;
	std::cout << "================================" << std::endl;
	return 0;
}
