#include "SerializerClass/SerializerClass.hpp"
#include <iostream>
#include <stdint.h>
#include <cstdio>

typedef struct s_data {
	long	num;
	char	c;
} Data;

// class	Data {
// 	private:
// 		std::string	name;
// 	public:
// 		Data(void): name("default_DataClass_name") {};
// };

int	main() {
	Data		data;

	std::cout << "data address at start: " << &data << std::endl;
	std::cout << "====================================================" << std::endl;


	uintptr_t	ptr = Serializer::serialize(&data);
	// std::cout << "serialize result is: " << (void *)ptr << std::endl;
	// std::cout << "data& after serialize is: " << (void *)&data << std::endl;
	// std::cout << "----------------------------------------------------" << std::endl;
	Data*		new_data = Serializer::deserialize(ptr);
	std::cout << "deserialize: new_data  value is: " << new_data << std::endl;

}
