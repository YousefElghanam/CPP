#ifndef __HUMANA_H__
# define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {
	/* We use a reference when the attribute (Weapon) must always exist,
		it's known at construction time (with initializer list), and it
		can not change during the HumanA's lifetime.
		In HumanB, we use a poitner, because a HumanB can have no Weapon */
	private:
		std::string		name;
		const Weapon	&weaponREF;
		/* It doesn't make sense to add setWeapon(Weapon &Weapon), because
			weaponREF is initializer to one object at the start, and can't
			be changed, if we do weaponREF = weapon, we are actually 
			changing the original Weapon that weaponREF aliases.*/
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		// void				setWeapon(Weapon& weapon); // read Weapon::getType()
		void				attack(void);
};

#endif /* __HUMANA_H__ */