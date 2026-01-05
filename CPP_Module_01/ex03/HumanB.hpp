#ifndef __HUMANB_H__
# define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*weaponPTR;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void				setWeapon(Weapon& weapon);
		void				attack(void);
};

#endif /* __HUMANB_H__ */