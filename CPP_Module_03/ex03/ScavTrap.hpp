#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: virtual public ClapTrap {
	public:
		// using ClapTrap::name;
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif /* SCAVTRAP_CLASS_H */
