#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <string>

class Animal {
	private:
		std::string	type;

	public:
		Animal(void);
		virtual ~Animal(void);
		explicit Animal(const std::string& type);
		Animal(const Animal& obj);
		Animal&				operator=(const Animal& obj);

		void				setType(const std::string& newType);
		const std::string&	getType(void) const;

		virtual void		makeSound(void) const = 0;
		virtual void		think(void) const = 0;
};

#endif /* ANIMAL_CLASS_HPP */
