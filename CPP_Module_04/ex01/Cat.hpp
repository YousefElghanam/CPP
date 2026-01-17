#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain*	brain;

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
		void	think(void) const;
};

#endif /* CAT_CLASS_HPP */
