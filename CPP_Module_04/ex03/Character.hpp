#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include <string>
# include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: ICharacter {
	public:
		Character(void);
		virtual ~Character(void);
		Character(const Character& obj);
		Character& operator=(const Character& obj);

		virtual const std::string&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, Character& target) = 0;
};

#endif /* CHARACTER_CLASS_HPP */
