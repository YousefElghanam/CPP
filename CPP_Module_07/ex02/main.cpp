#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
		std::cout << "Array[" << i << "]: " << numbers[i] << " ----- " << "mirror[" << i << "]: " << mirror[i] << std::endl;
    }
	std::cout << "=======================================" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "tmp: ";
		for (unsigned int i = 0; i < MAX_VAL; i++) {
			std::cout << test[i] << ", ";
		}
		std::cout << std::endl;
    }
	std::cout << "=======================================" << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
