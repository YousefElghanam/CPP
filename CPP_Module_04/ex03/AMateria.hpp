#ifndef A_MATERIA_CLASS_HPP
# define A_MATERIA_CLASS_HPP

# include <string>
# include "ICharacter.hpp"

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
		virtual void		use(ICharacter& target);
};

#endif /* A_MATERIA_CLASS_HPP */