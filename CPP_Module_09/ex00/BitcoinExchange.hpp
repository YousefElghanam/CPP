#ifndef BITCOIN_EXCHANGE_CLASS_HPP
# define BITCOIN_EXCHANGE_CLASS_HPP

# include <fstream>
# include <map>

typedef struct s_date {
	int	year;
	int	month;
	int	day;
}	t_date;

struct f_less_date {
	bool	operator()(t_date& d1, t_date& d2) const;
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
};

#endif /* BITCOIN_EXCHANGE_CLASS_HPP */
