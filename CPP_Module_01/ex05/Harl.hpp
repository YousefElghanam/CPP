#ifndef __HARL_CLASS__
# define __HARL_CLASS__

# include <iostream>

class Harl {
	private:
		std::string	levels[4];
		void		(Harl::* fnArr[5])();
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		void		unknown(void);
	public:
		Harl(void);
		~Harl(void);
		void		complain(std::string level);
};

#endif /* __HARL_CLASS__ */