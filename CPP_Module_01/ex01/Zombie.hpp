#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void		set_name(std::string name);
		std::string get_name(void);
		void		announce(void);
};

#endif /* ZOMBIE_CLASS_HPP */