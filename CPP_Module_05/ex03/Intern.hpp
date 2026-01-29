#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>

class AForm;

class Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);

		AForm*	makeForm(const std::string& formName, const std::string& target) const;
};

#endif /* INTERN_CLASS_HPP */
