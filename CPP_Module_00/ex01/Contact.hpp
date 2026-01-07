#ifndef __CONTACT_CLASS_H__
# define __CONTACT_CLASS_H__

# include <string>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <cstdio>

class Contact {
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone;
		std::string	secret;
};

#endif