/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <snair@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:10:35 by snair             #+#    #+#             */
/*   Updated: 2022/12/07 10:10:36 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{ 
    return _nbAccounts; 
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{ 
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{ 
    return _totalNbWithdrawals; 
}

//displays time stamp starting from year,month,day,hour,minute,seconds
//setfill to fill in '0' if width 2 is empty
void Account::_displayTimestamp(void) 
{
    time_t t = time(NULL);
    tm *tm = localtime(&t);
    std::cout << "[" << (tm->tm_year + 1900) << std::setw(2) << std::setfill('0')
    << tm->tm_mon << std::setw(2) << std::setfill('0') << tm->tm_mday
    << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour
    << std::setw(2) << std::setfill('0') << tm->tm_min << std::setw(2)
    << std::setfill('0') << tm->tm_sec << "]";
}

//displays the timestap and the various account information
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}


//constructor for Account Class
Account::Account(int initial_deposit) 
{
    // Set private data members 
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
    << ";created" << std::endl;
}

//destructor for Account Class
Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
    << ";closed" << std::endl;
}

//takes the amount deposited, adds it to total amount and increases the number of deposits made for an account
void Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
    << ";p_amount:" << this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

//checks to see if withdrawl amount is bigger than amount in account, if yes withdrawl is not allowed
//takes the amount withdrawn deduct it from current amount, deduct it to total amount and increases the number of withdrawls made for an account
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
    << ";withdrawal:";
    if (withdrawal > this->_amount) 
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount 
    << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

//checks current amount
int Account::checkAmount(void) const
{ 
    return this->_amount;
}

void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}