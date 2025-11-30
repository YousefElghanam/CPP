#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		std::string	arg;
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			arg = argv[i];
			for (std::string::iterator it = arg.begin(); it != arg.end(); it++)
				*it = std::toupper((unsigned char)*it);
			std::cout << std::string(arg);
		}
		std::cout << std::endl;
	}
	return (0);
}
