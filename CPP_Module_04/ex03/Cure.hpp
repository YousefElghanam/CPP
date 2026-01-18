#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure& obj);
		Cure&	operator=(const Cure& obj);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif /* CURE_CLASS_HPP */
