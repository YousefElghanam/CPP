#ifndef I_CHARACTER_CLASS_HPP
# define I_CHARACTER_CLASS_HPP

# include <string>

class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter(void) {};
		virtual const std::string&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

#endif /* I_CHARACTER_CLASS_HPP */
