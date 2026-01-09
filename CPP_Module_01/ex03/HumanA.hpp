#ifndef HUMAN_A_CLASS_HPP
# define HUMAN_A_CLASS_HPP

#include "Weapon.hpp"

class HumanA {
	/* We use a reference when the attribute (Weapon) must always exist,
		it's known at construction time (with initializer list), and it
		can not change during the HumanA's lifetime.
		In HumanB, we use a poitner, because a HumanB can have no Weapon */
	private:
		std::string		name;
		/* I don't want to make the reference public, because I don't intend
			to use it from main(). If I want to change the weapon, I should do
			it from the original owner that I passed its refernce in constuctor */
		const Weapon	&weaponREF;
		/* It doesn't make sense to add setWeapon(Weapon &Weapon), because
			weaponREF is initialized to one object at the start, and can't
			be changed, if we do weaponREF = weapon, we are actually 
			changing the original Weapon that weaponREF aliases, which means
			this class can be used to change data owned by another class,
			and I should NOT do that (in most cases I guess). */
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		// void				setWeapon(Weapon& weapon); // read Weapon::getType()
		void	attack(void);
};

#endif /* HUMAN_A_CLASS_HPP */