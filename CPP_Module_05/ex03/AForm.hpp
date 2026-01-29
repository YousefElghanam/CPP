#ifndef A_FORM_CLASS_HPP
# define A_FORM_CLASS_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm {
	private:
		const static long	minGrade;
		const static long	maxGrade;
		const std::string	name;
		std::string			target;
		const long			signGrade;
		const long			execGrade;
		bool				sign;

	public:
		class	GradeTooHighException: public std::exception {
			public: const char* what(void) const throw();
		};
		class	GradeTooLowException: public std::exception {
			public: const char* what(void) const throw();
		};
		class	AlreadySignedException: public std::exception {
			public: const char* what(void) const throw();
		};
		class	NotSignedException: public std::exception {
			public: const char* what(void) const throw();
		};

		AForm(void);
		virtual ~AForm(void);
		AForm(const std::string& name, long signGrade, long execGrade);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);

		/* I could put some or all of these functions in protected but naaah */
		const std::string&	getName(void) const;
		long				getSignGrade(void) const;
		long				getExecGrade(void) const;
		bool				getSign(void) const;
		bool				canExecuteForm(const Bureaucrat& executor) const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual AForm*		clone(void) const = 0;
		virtual bool		execute(const Bureaucrat& executor) const = 0;
		void				setTarget(const std::string& newTarget);
		const std::string&	getTarget(void) const;
};

std::ostream&	operator<<(std::ostream &os, const AForm& obj);

#endif /* A_FORM_CLASS_HPP */
