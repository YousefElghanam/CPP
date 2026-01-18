#ifndef WRONG_CAT_CLASS_HPP
# define WRONG_CAT_CLASS_HPP

# include "WrongAnimal.hpp"
# include <string>

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		~WrongCat(void);
		/* explicit (works only for single argument constructors) makes it
			invalid to use this constructor like this: WrongCat inst = "hello";
			I have to use it explicitly like this: WrongCat inst("hello"); which
			is good for copy constructors */
		explicit WrongCat(const std::string& type);
		WrongCat(const WrongCat& obj);
		WrongCat&	operator=(const WrongCat& obj);

		void		makeSound(void) const;
};

#endif /* WRONG_CAT_CLASS_HPP */
