#ifndef I_CHARACTER_CLASS_HPP
# define I_CHARACTER_CLASS_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter {
	public:
		ICharacter(void);
		virtual ~ICharacter(void);
		ICharacter(const ICharacter& obj);
		ICharacter& operator=(const ICharacter& obj);

		virtual const std::string&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

#endif /* I_CHARACTER_CLASS_HPP */
