#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
	private:
		const static long	minGrade;
		const static long	maxGrade;
		const std::string	name;
		long				grade;

	public:
		class	GradeTooHighException: public std::exception {
			public: const char* what(void) const throw();
		};
		class	GradeTooLowException: public std::exception {
			public: const char* what(void) const throw();
		};

		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const std::string& name, long grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat&	operator=(const Bureaucrat& obj);

		const std::string&	getName(void) const;
		long				getGrade(void) const;
		void				operator++(int);
		// void				operator++(void);
		void				operator--(int);
		// void				operator--(void);
};

std::ostream&	operator<<(std::ostream &os, const Bureaucrat& obj);

#endif /* BUREAUCRAT_CLASS_HPP */
