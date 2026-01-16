#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.hpp"
# include <string>

class Dog: public Animal {
	public:
		Dog(void);
		/* explicit (works only for single argument constructors) makes it
			invalid to use this constructor like this: Dog inst = "hello";
			I have to use it explicitly like this: Dog inst("hello"); which
			is good for copy constructors */
		explicit Dog(const std::string& type);
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& obj);
		~Dog(void);

		void	makeSound(void);
};

#endif /* DOG_CLASS_HPP */
