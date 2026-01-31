#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>

enum e_type {
	EMPTY,
	UNKOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter&	operator=(const ScalarConverter& obj);
		virtual ~ScalarConverter(void) = 0;

		static void	convert(const std::string& input);
};

std::ostream&	operator<<(std::ostream &os, const ScalarConverter& obj);

#endif /* SCALAR_CONVERTER_HPP */
