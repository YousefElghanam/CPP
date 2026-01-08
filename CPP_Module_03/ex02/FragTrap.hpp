#ifndef __FRAGTRAP_CLASS_H__
# define __FRAGTRAP_CLASS_H__

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

#endif /* __FRAGTRAP_CLASS_H__ */