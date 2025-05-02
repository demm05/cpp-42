#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(void) {
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    (void)initial_deposit;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";closed" << std::endl;
    _nbAccounts--;
}

int Account::checkAmount(void) const {
    return (this->_amount);
}

void Account::makeDeposit(int deposit) {
    int p_amount;

    p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";deposit:" << deposit << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std ::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    int p_amount;

    if (withdrawal < 0 || withdrawal > this->_amount) {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex
                  << ";p_amount:" << this->_amount << ";withdrawal:refused"
                  << std::endl;
        return (0);
    }
    p_amount = this->_amount;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std ::endl;
    return (1);
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std ::endl;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
    time_t    timestamp;
    struct tm dt;

    time(&timestamp);
    dt = *localtime(&timestamp);
    // clang-format off
    std::cout << "[" << 1900 + dt.tm_year 
    	<< std::setfill('0') << std::setw(2) << dt.tm_mon 
    	<< std::setfill('0') << std::setw(2) << dt.tm_mday << "_" 
    	<< std::setfill('0') << std::setw(2) << dt.tm_mday
        << std::setfill('0') << std::setw(2) << dt.tm_hour
        << std::setfill('0') << std::setw(2) << dt.tm_min << "] ";
    // clang-format on
    // std::cout << "[19920104_091532] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
