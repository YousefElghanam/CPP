#ifndef ROBOTOMY_REQUEST_FORM_CLASS_HPP
# define ROBOTOMY_REQUEST_FORM_CLASS_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm {
	private:
		const static long	formSignGrade;
		const static long	formExecGrade;
		static unsigned int	state;

	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		explicit RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);

		static int			rand(void);
		bool				execute(const Bureaucrat& executor) const;
		virtual AForm*		clone(void) const;
};

#endif /* ROBOTOMY_REQUEST_FORM_CLASS_HPP */
