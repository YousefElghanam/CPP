#ifndef WEAPON_CLAS_HPP
# define WEAPON_CLAS_HPP

# include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string name);
		~Weapon(void);

		/* The first const belongs to the return type.
			The secondt const means that this method will not
			modifiy the object, so we can use it with objects
			that are const (HumanA's WeaponREF) */
		const std::string&	getType(void) const;
		void				setType(std::string name);
};

#endif /* WEAPON_CLAS_HPP */