#include "easyfind.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>
#include <iostream>

#include <deque>
#include <vector>
#include <list>
#include <set>

int	main(void) {
	std::srand(std::time(0));
	{
		std::vector<int>	vec;
		for (unsigned int i = 0; i < 5; i++) {
			vec.push_back(std::rand() % 5);
		}
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "-----------------------" << std::endl;
		try {
			std::vector<int>::iterator x = easyfind(vec, 1);
			std::cout << *x << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==================================" << std::endl;
	{
		std::deque<int>	vec;
		for (unsigned int i = 0; i < 5; i++) {
			vec.push_back(std::rand() % 5);
		}
		for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "-----------------------" << std::endl;
		try {
			std::deque<int>::iterator x = easyfind(vec, 1);
			std::cout << *x << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==================================" << std::endl;
	{
		std::list<int>	vec;
		for (unsigned int i = 0; i < 5; i++) {
			vec.push_back(std::rand() % 5);
		}
		for (std::list<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "-----------------------" << std::endl;
		try {
			std::list<int>::iterator x = easyfind(vec, 1);
			std::cout << *x << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==================================" << std::endl;
	{
		std::set<int>	vec;
		for (unsigned int i = 0; i < 5; i++) {
			vec.insert(std::rand() % 5);
		}
		for (std::set<int>::iterator it = vec.begin(); it != vec.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "-----------------------" << std::endl;
		try {
			std::set<int>::iterator x = easyfind(vec, 1);
			std::cout << *x << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
