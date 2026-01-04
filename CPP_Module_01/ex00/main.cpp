#include <iostream>

#include "main.hpp"

int main(void)
{
	Zombie		y("zombieY");
	std::cout << "tring to get name (" << y.get_name() << ")" << std::endl;
	y.announce();
	std::cout << "================================" << std::endl;

	Zombie		*x = newZombie("zombieX");
	x->announce();
	delete x;
	std::cout << "================================" << std::endl;

	randomChump("THE RANDOM");
	return 0;
}
