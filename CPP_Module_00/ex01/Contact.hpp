#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <cstdio>

class Contact {
	public: // SHOULD BE PRIVATE AND MAKE SETTERS AND GETTER FUNCTIONS
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone;
		std::string	secret;
};

#endif /* CONTACT_CLASS_H */