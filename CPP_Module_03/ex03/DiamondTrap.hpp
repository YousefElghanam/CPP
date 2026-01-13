#ifndef DIAMONDTRAP_CLASS_H
# define DIAMONDTRAP_CLASS_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, FragTrap {
	private:
		std::string	name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap& operator=(const DiamondTrap& obj);
		~DiamondTrap(void);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
	};

#endif /* DIAMONDTRAP_CLASS_H */
