#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form {
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
		class	AlreadySigned: public std::exception {
			public: const char* what(void) const throw();
		};

		Form(void);
		~Form(void);
		Form(const std::string& name, long signGrade, long execGrade);
		Form(const Form& obj);
		Form&	operator=(const Form& obj);

		const std::string&	getName(void) const;
		long				getSignGrade(void) const;
		long				getExecGrade(void) const;
		bool				getSign(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream &os, const Form& obj);

#endif /* FORM_CLASS_HPP */
