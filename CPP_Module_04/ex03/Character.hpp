#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter {
	private:
		std::string 				name;
		unsigned int				inventorySize;
		const static unsigned int	inventoryCap;
		AMateria*					inventory[4];

	public:
		Character(void);
		~Character(void);
		explicit Character(const std::string& name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);

		const std::string&	getName(void) const;
		/** will take ownership of `m` */
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif /* CHARACTER_CLASS_HPP */
