#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>

class AForm;

class Intern {
	private:
		const static unsigned int	formCount;
		std::string					forms[3];
		AForm*						formArr[4];

	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);

		unsigned int	getFormIdx(const std::string& formName) const;
		AForm*			makeForm(const std::string& formName, const std::string& target) const;
};

#endif /* INTERN_CLASS_HPP */
