#include "MutantStack.hpp"
#include <algorithm>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <iostream>

// template <typename T>
static void	print_it(int num) {
	std::cout << num << " ";
}

int	main() {
	std::srand(std::time(0));
	// std::stack<int, std::vector<int> > stack;
	const std::stack<int> st;
	MutantStack<int>	mstack;
	for (size_t i = 0; i < 5; i++) {
		mstack.push(std::rand() % 100);
	}
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::for_each(mstack.begin(), mstack.end(), print_it);
	std::cout << std::endl;
}

// #include <vector>
// #include <list>
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
