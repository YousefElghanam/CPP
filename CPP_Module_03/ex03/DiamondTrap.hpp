#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	name;
		using		FragTrap::hp;
		using		ScavTrap::energy;
		using		FragTrap::ad;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);
		~DiamondTrap(void);

		void	whoAmI(void);
		using	ScavTrap::attack;
};

#endif /* DIAMONDTRAP_CLASS_H */
