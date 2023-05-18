#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account :: Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account :: ~Account( void )
{
	//[19920104_091532] index:0;amount:47;closed
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void Account :: displayAccountsInfos( void )
{
	//accounts:8;total:21524;deposits:8;withdrawals:0
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

void Account :: makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account :: makeWithdrawal( int withdrawal )
{
	bool refused;

	refused = true;
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		refused = false;
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	if (refused)
	{
		std::cout << "p_amount:" << this->_amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "p_amount:" << this->_amount + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account :: displayStatus( void ) const
{
	//index:7;amount:16576;deposits:0;withdrawals:0
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void Account :: _displayTimestamp( void )
{
	std::time_t	time_in_sec;
	std::tm 	*timemark;

	time_in_sec = std::time(NULL);
	timemark = std::localtime(&time_in_sec);
	std::cout << "[" << timemark->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << timemark->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timemark->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timemark->tm_sec << "] ";
}
