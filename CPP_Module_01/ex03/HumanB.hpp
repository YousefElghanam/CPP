#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*weaponPTR;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif /* HUMAN_B_CLASS_HPP */