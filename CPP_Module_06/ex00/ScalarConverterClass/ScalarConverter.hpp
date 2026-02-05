#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter {
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter&	operator=(const ScalarConverter& obj);
		virtual ~ScalarConverter(void) = 0;

		static void	convert(const std::string& input);
};

#endif /* SCALAR_CONVERTER_HPP */
