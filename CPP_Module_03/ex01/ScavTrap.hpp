#ifndef __SCAVTRAP_CLASS_H__
# define __SCAVTRAP_CLASS_H__

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif /* __SCAVTRAP_CLASS_H__ */