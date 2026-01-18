#ifndef WRONG_ANIMAL_CLASS_HPP
# define WRONG_ANIMAL_CLASS_HPP

# include <string>

class WrongAnimal {
	private:
		std::string	type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		explicit WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal&				operator=(const WrongAnimal& obj);

		void				makeSound(void) const;
		void				setType(const std::string& newType);
		const std::string&	getType(void) const;
};

#endif /* WRONG_ANIMAL_CLASS_HPP */
