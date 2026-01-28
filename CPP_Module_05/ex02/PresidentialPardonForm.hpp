#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_HPP
# define PRESIDENTIAL_PARDON_FORM_CLASS_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm {
	private:
		const static long	formSignGrade;
		const static long	formExecGrade;
		std::string			target;

	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);

		bool				execute(const Bureaucrat& executor) const;
};

#endif /* PRESIDENTIAL_PARDON_FORM_CLASS_HPP */
