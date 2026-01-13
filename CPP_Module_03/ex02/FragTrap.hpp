#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include "ClapTrap.hpp"
# include <string>

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
		~FragTrap(void);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif /* FRAGTRAP_CLASS_H */