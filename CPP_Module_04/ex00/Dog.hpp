#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const std::string& name);
		Dog(const Dog& obj);
		Dog&	operator=(const Dog& obj);
		~Dog(void);

		void	makeSound(void);
};

#endif /* DOG_CLASS_HPP */
