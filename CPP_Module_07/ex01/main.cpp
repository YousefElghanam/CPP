#include <string>
#include <iostream>
#include "iter.hpp"

void	printDoubleConst(const int& num) {
	std::cout << num << " is now: " << num * 2 << std::endl;
}

void	printDouble(int& num) {
	std::cout << num << " is now: " << num * 2 << std::endl;
}

void	printTwiceConst(const std::string& word) {
	std::cout << word << "-" << word << std::endl;
}

void	printTwice(std::string& word) {
	std::cout << word << "-" << word << std::endl;
}

int	main(void) {
	const int			constArr[3] = {1, 2, 3};
	int					arr[3] = {1, 2, 3};
	const std::string	constWords[3] = {"word1", "word2", "word3"};
	std::string			words[3] = {"word1", "word2", "word3"};

	iter(arr, 3, printDouble);
	std::cout << "=======================" << std::endl;

	iter(arr, 3, printDoubleConst);
	std::cout << "=======================" << std::endl;

	iter(constArr, 3, printDoubleConst);
	std::cout << "=======================" << std::endl;

	// iter(constArr, 3, printDouble); // THIS DOESN'T COMPILE BECAUSE WE USE FUNCTION THAT WORKS ON non-const BUT ARRAY IS CONST

	iter(words, 3, printTwice);
	std::cout << "=======================" << std::endl;

	iter(words, 3, printTwiceConst);
	std::cout << "=======================" << std::endl;

	iter(constWords, 3, printTwiceConst);
	return 0;
}

// class Awesome
// {
// public:
// Awesome( void ) : _n( 42 ) { return; }
// int get( void ) const { return this->_n; }
// private:
// int _n;
// };
// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
// template< typename T >
// void printConst( T const & x ) { std::cout << x << std::endl; return; }
// template< typename T >
// void print( T & x ) { std::cout << x << std::endl; return; }
// int main() {
// int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// Awesome tab2[5];
// iter( tab, 5, printConst );
// iter( tab, 5, print );
// iter( tab2, 5, print );
// iter( tab2, 5, printConst );
// return 0;
// }
