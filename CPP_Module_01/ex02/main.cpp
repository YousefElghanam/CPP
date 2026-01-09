#include <string>
#include <iostream>

int	main(void)
{
	std::string	theString = "HI THIS IS BRAIN";
	std::string	*stringPTR = &theString;
	/* REFERENCE IS NOT THE OWNER, IT'S JUST AN ALIAS OF THE VARIABLE,
		CAN'T BE NULL, MUST BE INITIALIZED, CAN'T BE RESEATED TO ANOTHER OBJ */
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