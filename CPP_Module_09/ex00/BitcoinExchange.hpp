#ifndef BITCOIN_EXCHANGE_CLASS_HPP
# define BITCOIN_EXCHANGE_CLASS_HPP

# include <fstream>
# include <map>
# include <exception>

typedef struct s_date {
	long	year;
	long	month;
	long	day;
}	t_date;

struct f_less_date {
	bool	operator()(const t_date& d1, const t_date& d2) const;
};

class BitcoinExchange {
	private:
		std::map<t_date, double>	data;

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator=(const BitcoinExchange& obj);

	public:
		virtual ~BitcoinExchange(void) = 0;
		static int	exchange(std::ifstream& data, std::ifstream& input);

		class InvalidDataFileException: public std::exception {
			const char*	what(void) const throw();
		};
		class InvalidInputFileException: public std::exception {
			const char*	what(void) const throw();
		};
		class InvalidInputFormatException: public std::exception {
			const char*	what(void) const throw();
		};
		
};

#endif /* BITCOIN_EXCHANGE_CLASS_HPP */
