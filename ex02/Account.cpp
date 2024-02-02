/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:51:39 by pvilchez          #+#    #+#             */
/*   Updated: 2024/02/02 09:51:42 by pvilchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900;
	if (now->tm_mon + 1 < 10)
		std::cout << 0;
	std::cout << now->tm_mon + 1;
	if (now->tm_mday < 10)
		std::cout << 0;
	std::cout << now->tm_mday << "_";
	if (now->tm_hour < 10)
		std::cout << 0;
	std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << 0;
	std::cout << now->tm_min;
	if (now->tm_sec < 10)
		std::cout << 0;
	std::cout << now->tm_sec << "] ";
}

int	Account::getNbAccounts(void) {return (_nbAccounts);}

int	Account::getTotalAmount(void) {return (_totalAmount);}

int	Account::getNbDeposits(void) {return (_totalNbDeposits);}

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

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;
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
