#ifndef A_MATERIA_CLASS_HPP
# define A_MATERIA_CLASS_HPP

# include <string>

class ICharacter;

class AMateria {
	protected:
		std::string	type;

	public:
		explicit AMateria(const std::string& type);
		virtual ~AMateria(void);
		AMateria(const AMateria& obj);
		AMateria&	operator=(const AMateria& obj);

		const std::string&	getType(void) const; //Returns the materia type
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif /* A_MATERIA_CLASS_HPP */
