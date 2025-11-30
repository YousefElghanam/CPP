#include <sstream>
#include <cstddef>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cout << "STRING: " << s << std::endl;
	std::getline(std::cin, s);
	std::cout << "STRING: " << s << std::endl;
}