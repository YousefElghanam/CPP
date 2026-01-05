#include <string>
#include <iostream>

int	main(void)
{
	std::string	theString = "HI THIS IS BRAIN";
	std::string	*stringPTR = &theString;
	std::string	&stringREF = theString;
	std::cout << "==================================" << std::endl;
	std::cout << &theString << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << theString << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return 0;
}