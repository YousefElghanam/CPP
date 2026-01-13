#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <string>

class ClapTrap {
	private:
		std::string		name;
		unsigned int	hp;
		unsigned int	energy;
		unsigned int	ad;

	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		~ClapTrap(void);

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif /* CLAPTRAP_CLASS_H */