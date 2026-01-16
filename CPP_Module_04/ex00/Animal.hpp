#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const std::string& name);
		Animal(const Animal& obj);
		Animal&	operator=(const Animal& obj);
		~Animal(void);

		void	makeSound(void);
};

#endif /* ANIMAL_CLASS_HPP */
