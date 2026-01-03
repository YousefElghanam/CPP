#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();
	std::cout << "index:" << Account::_nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;

	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/* STATIC METHODS */

int		Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
			<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp() {
	time_t	t = time(NULL);
	tm		*tm = localtime(&t);
	char		buf[32];

	strftime(buf, 16, "%Y%m%d_%H%M%S", tm);
	std::cout << "[" << std::string(buf) << "] ";
}

/* NORMAL METHODS */

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
			<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (1);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	return (0);
}
