#include "main.hpp"

int	main(int argc, char **argv) {
	if (argc != 2 && argc != 1) {
		std::cerr << "Unexpected error" << std::endl;
		return 1;
	}
	std::cout << "=============================" << std::endl;
	Harl	obj;
	obj.complain("ERROR");
	std::cout << "=============================" << std::endl;
	obj.complain("xx");
	std::cout << "=============================" << std::endl;
	obj.complain("WARNING");
	std::cout << "=============================" << std::endl;
	obj.complain("DEBUG");
	std::cout << "=============================" << std::endl;
	obj.complain("INFO");
	std::cout << "=============================" << std::endl;
	if (argc == 1)
		return 0;
	obj.complain(argv[1]);
	return 0;
}
