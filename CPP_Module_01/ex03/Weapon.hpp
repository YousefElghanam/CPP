#ifndef __WEAPON_CLASS_H__
# define __WEAPON_CLASS_H__

# include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string name);
		~Weapon(void);

		const std::string&	getType(void);
		void				setType(std::string name);
};

#endif /* __WEAPON_CLASS__ */