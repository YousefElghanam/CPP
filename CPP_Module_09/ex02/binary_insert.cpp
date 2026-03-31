#include <vector>
#include <iostream>
#include <cstddef>

void	binary_insert(std::vector<int>& vec, int start, int end, int num) {
	if (start >= end) {
		if (num > vec.at(start)) { // TODO 1 comparison
			vec.insert(vec.begin() + start + 1, num);
		}
		else {
			vec.insert(vec.begin() + start, num);
		}
		return ;
	}
	int mid = start + ((end - start) / 2);
	// std::cout << "mid is: " << mid << std::endl;

	if (num == vec.at(mid)) { // TODO 2 comparisons
		vec.insert(vec.begin() + mid, num);
	}
	else if (num < vec.at(mid)) { // TODO 3 comparisons
		binary_insert(vec, start, mid - 1, num);
	}
	else {
		binary_insert(vec, mid + 1, end, num);
	}
}

int main() {
	std::vector<int> vec;

	vec.push_back(0);
	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(15);
	vec.push_back(20);
	vec.push_back(25);
	vec.push_back(30);

	std::cout << "before: ";
	for (size_t i = 0; i < 7; i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;

	binary_insert(vec, 0, 6, 21);

	std::cout << "after: ";
	for (size_t i = 0; i < 8; i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
}