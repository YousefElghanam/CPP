#include "RPN.hpp"

#include <climits>
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <stack>

RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(const RPN& obj) {
	(void)obj;
}

RPN&	RPN::operator=(const RPN& obj) {
	(void)obj;
	return *this;
}

static void	validateInput(char* input) {
	if (!input || !input[0]) {
		std::cerr << "Empty argument ";
		throw std::exception();
	}
	for (size_t i = 0; input[i] != '\0'; i++) {
		if (std::isdigit(input[i]) == 0 && std::isspace(input[i]) == 0
			&& (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/')) {
				std::cerr << "Unknown symbol (" << input[i] << ")";
				throw std::exception();
		}
	}
}

static void add(std::stack<long>& s, long num1, long num2) {
	if (num1 > LONG_MAX - num2) {
		std::cerr << "Overflowed in addition";
		throw std::exception();
	}
	s.push(num1 + num2);
}

static void subtract(std::stack<long>& s, long num1, long num2) {
	s.push(num1 - num2);
}

static void multiply(std::stack<long>& s, long num1, long num2) {
	const long	res = num1 * num2;
	if (res / num1 != num2) {
		std::cerr << "Overflowed in multiplaction";
		throw std::exception();
	}
	s.push(res);
}

static void divide(std::stack<long>& s, long num1, long num2) {
	if (num2 == 0) {
		std::cerr << "Division by 0";
		throw std::exception();
	}
	s.push(num1 / num2);
}

static void	doMaths(std::stack<long>& s, char op) {
	if (s.size() < 2) {
		std::cout << "Not enough numbers in stack to operate on";
		throw std::exception();
	}
	const long	num2 = s.top();
	s.pop();
	const long	num1 = s.top();
	s.pop();
	switch (op) {
		case '+':
			add(s, num1, num2);
			break ;
		case '-':
			subtract(s, num1, num2);
			break ;
		case '*':
			multiply(s, num1, num2);
			break ;
		case '/':
			divide(s, num1, num2);
			break ;
		default:
			std::cerr << "Unknown error happened";
			throw std::exception();
	}
}

static void	readInput(char* input) {
	std::stack<long>	s;

	for (size_t i = 0; input[i] != '\0'; i++) {
		if (std::isspace(input[i]) != 0) {
			continue ;
		}
		if (std::isdigit(input[i]) != 0) {
			s.push(input[i] - '0');
			continue ;
		}
		doMaths(s, input[i]);
	}
	if (s.size() != 1) {
		std::cerr << "Invalid input";
		throw std::exception();
	}
	std::cout << s.top() << std::endl;
}

int		RPN::calculate(char* input) {
	try {
		validateInput(input);
		readInput(input);
	}
	catch (std::exception& e) {
		std::cerr << std::endl;
		return 1;
	}
	return 0;
}
