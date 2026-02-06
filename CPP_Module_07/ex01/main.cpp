#include <string>
#include <iostream>
#include "iter.hpp"

void	printDouble(int num) {
	std::cout << num << " is now: " << num * 2 << std::endl;
}

void	printTwiceRef(const std::string& word) {
	std::cout << word << "-" << word << std::endl;
}

void	printTwice(std::string& word) {
	std::cout << word << "-" << word << std::endl;
}

int	main(void) {
	int			arr[3] = {1, 2, 3};
	std::string	words[3] = {"word1", "word2", "word3"};

	iter(arr, 3, printDouble);
	std::cout << "=======================" << std::endl;
	
	iter(words, 3, printTwiceRef);
	std::cout << "=======================" << std::endl;

	iter(words, 3, printTwice);
	return 0;
}
