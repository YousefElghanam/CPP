#ifndef __ZOMBIE_CLASS_H__
# define __ZOMBIE_CLASS_H__

# include <string>

class Zombie {
	private:
		std::string	name;

	public:

		Zombie(std::string name);
		~Zombie(void);

		void		set_name(std::string name);
		std::string get_name(void);
		void		announce(void);
};

#endif /* __ZOMBIE_CLASS__ */