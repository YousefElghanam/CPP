#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice& obj);
		Ice&	operator=(const Ice& obj);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif /* ICE_CLASS_HPP */
