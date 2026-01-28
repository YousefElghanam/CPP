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
		void				beSigned(const Bureaucrat& bureaucrat);
		bool				canExecuteForm(const Bureaucrat& executor) const;
		virtual bool		execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream &os, const AForm& obj);

#endif /* A_FORM_CLASS_HPP */
