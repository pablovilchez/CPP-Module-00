#include "Account.hpp"
#include <iostream>

void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}

int	Account::getNbAccounts( void ) {return (_nbAccounts);}

int	Account::getTotalAmount( void ) {return (_totalAmount);}

int	Account::getNbDeposits( void ) {return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void ) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	_accountIndex = Account::_nbAccounts++;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << ++_nbDeposits;
	std::cout << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount(void) const {return (_amount);}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}
