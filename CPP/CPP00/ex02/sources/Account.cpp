#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit): _accountIndex(getNbAccounts()), _amount(initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
    if (this->_amount - withdrawal >= 0) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
}

void	Account::_displayTimestamp(void)
{
    std::cout << "[19920104_091532] ";
    /**
    time_t      temp;
    struct tm*  timeinfo;

    temp = time(NULL);
    timeinfo = localtime(&temp);

    std::cout << "[";
    std::cout << 1900 + timeinfo->tm_year;
    if (timeinfo->tm_mon < 9)
        std::cout << "0";
    std::cout << 1 + timeinfo->tm_mon;
    if (timeinfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mday;
    std::cout << "_";
    if (timeinfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_hour;
    if (timeinfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_min;
    if (timeinfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_sec;
    std::cout << "] ";
    */
}


void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

int Account::checkAmount( void ) const
{
    return this->_amount;
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

