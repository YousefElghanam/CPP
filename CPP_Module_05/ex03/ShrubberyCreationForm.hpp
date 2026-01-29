#ifndef SHRUBBERY_CREATION_FORM_CLASS_HPP
# define SHRUBBERY_CREATION_FORM_CLASS_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		const static long	formSignGrade;
		const static long	formExecGrade;

	public:
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);

		bool				execute(const Bureaucrat& executor) const;
		virtual AForm*		clone(void) const;
};

#endif /* SHRUBBERY_CREATION_FORM_CLASS_HPP */
