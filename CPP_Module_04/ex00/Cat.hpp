#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "Animal.hpp"
# include <string>

class Cat: public Animal {
	public:
		Cat(void);
		~Cat(void);
		/* explicit (works only for single argument constructors) makes it
			invalid to use this constructor like this: Cat inst = "hello";
			I have to use it explicitly like this: Cat inst("hello"); which
			is good for copy constructors */
		explicit Cat(const std::string& type);
		Cat(const Cat& obj);
		Cat&	operator=(const Cat& obj);

		void	makeSound(void) const;
};

#endif /* CAT_CLASS_HPP */
