#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <string>
# include <exception>

// class Bureaucrat: public std::exception {
// 	private:
// 		const static long	minGrade;
// 		const static long	maxGrade;
// 		// const std::string	name;
// 		long				grade;

// };

class Bureaucrat {
	private:
		const static long	minGrade;
		const static long	maxGrade;
		const std::string	name;
		long				grade;

	public:
		class	GradeTooHighException: std::exception { public: static const char*	what(void) const throw();};
		class	GradeTooLowException: std::exception { public: const char*	what(void) const throw();};
		// Bureaucrat(void);
		// ~Bureaucrat(void);
		Bureaucrat(const std::string& name, long grade);
		// Bureaucrat(const Bureaucrat& obj);
		// Bureaucrat&	operator=(const Bureaucrat& obj);

		const std::string&	getName(void) const;
		long				getGrade(void) const;
		void				operator++(void);
		void				operator--(void);
};

#endif /* BUREAUCRAT_CLASS_HPP */
