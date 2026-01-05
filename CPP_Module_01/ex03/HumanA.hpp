#ifndef __HUMANA_H__
# define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	name;
		Weapon		&weaponREF;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void				setWeapon(Weapon& weapon);
		void				attack(void);
};

#endif /* __HUMANA_H__ */