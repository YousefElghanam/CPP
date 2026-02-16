#ifndef BITCOIN_EXCHANGE_CLASS_HPP
# define BITCOIN_EXCHANGE_CLASS_HPP

# include <fstream>

class BitcoinExchange {
	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator=(const BitcoinExchange& obj);

	public:
		virtual ~BitcoinExchange(void) = 0;
		static int	exchange(std::ifstream& data, std::ifstream& input);
};

#endif /* BITCOIN_EXCHANGE_CLASS_HPP */
