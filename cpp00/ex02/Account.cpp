/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucie <hlucie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:15:02 by hlucie            #+#    #+#             */
/*   Updated: 2022/02/01 15:42:45 by hlucie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::_displayTimestamp()
{
	time_t	current_time;
	tm 		*tm_local;

	time(&current_time);
	tm_local = localtime(&current_time);
	std::cout << "[";
	std::cout << std::setfill ('0') << std::setw(4) << 1900 + tm_local->tm_year;
	std::cout << std::setfill ('0') << std::setw(2) << 1 + tm_local->tm_mon;
	std::cout << std::setfill ('0') << std::setw(2) << tm_local->tm_mday;
	std::cout << "_";
	std::cout << std::setfill ('0') << std::setw(2) << tm_local->tm_hour;
	std::cout << std::setfill ('0') << std::setw(2) << tm_local->tm_min;
	std::cout << std::setfill ('0') << std::setw(2) << tm_local->tm_sec;
	std::cout << "] ";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"; std::cout << this->_accountIndex;
	std::cout << ";p_amount:"; std::cout << this->_amount;
	std::cout << ";deposit:"; std::cout << deposit;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	Account::_nbDeposits += 1;
	std::cout << ";amount:"; std::cout << this->_amount;
	std::cout << ";nb_deposits:"; std::cout << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:"; std::cout << this->_accountIndex;
	std::cout << ";p_amount:"; std::cout << this->_amount;
	if (withdrawal < this->_amount)
	{
		std::cout << ";withdrawal:"; std::cout << withdrawal;
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
		std::cout << ";amount:"; std::cout << this->_amount;
		std::cout << ";nb_withdrawals:"; std::cout << this->_nbWithdrawals << std::endl;
		return (1);
	}
	else
		std::cout << ";withdrawal:refused" << std::endl;
	return (0);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:"; std::cout << this->_accountIndex;
	std::cout << ";amount:"; std::cout << this->_amount;
	std::cout << ";deposits:"; std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:"; std::cout << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += checkAmount();
	Account::_totalNbDeposits += getNbDeposits();
	Account::_totalNbWithdrawals += getNbWithdrawals();
	Account::_displayTimestamp();
	std::cout << "index:"; std::cout << this->_accountIndex; std::cout << ";";
	std::cout << "amount:"; std::cout << this->_amount;
	std::cout << ";created" << std::endl;
	return ;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:"; std::cout << this->_accountIndex; std::cout << ";";
	std::cout << "amount:"; std::cout << this->_amount;
	std::cout << ";closed" << std::endl;	
	return ;
}