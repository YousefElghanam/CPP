#ifndef __WEAPON_CLASS_H__
# define __WEAPON_CLASS_H__

# include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string name);
		~Weapon(void);

		/* The first const belongs to the return type.
			The secondt const means that this method will not
			modifiy the object, so we can use it with a objects
			that are const (HumanA's WeaponREF) */
		const std::string&	getType(void) const;
		void				setType(std::string name);
};

#endif /* __WEAPON_CLASS__ */