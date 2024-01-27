// Account.cpp
// Purpose: Source file for Account class
#include "Account.h"

/*
* Account class
* Purpose:
*    To create an account with a number, name, and balance
*    To print the account details
*    To transfer money between accounts
*   @param accountNumber - the account number
*   @param accountType - the account name
*   @param balance - the account balance
*
*/

Account::Account(std::string accountType, double balance, std::string currency) : accountType(accountType), balance(balance), currency(currency)
{}

void Account::printAccounts() const
{
	std::cout << "\t" << accountType << "\t\t" << balance << "\t\t" << currency << "\n";
}

// using smart pointers to transfer money between accounts for easy memory management
bool Account::transferMoney(Account* accountFrom, double amount)
{
	// Check if the accountFrom has sufficient balance to transfer
	if ((accountFrom && accountFrom->getBalance() >= amount) && (accountFrom->getCurrency() == currency))
	{
		accountFrom->setBalance(accountFrom->getBalance() - amount);
		balance += amount;
		return true;
	}
    else if (accountFrom && accountFrom->getCurrency() != currency)
	{
		std::cout << "Cannot transfer between accounts with different currencies\n";
		return false;
	}
	else
	{
		std::cout << "Insufficient balance to transfer\n";
		return false;
	}
}

// Getters

double Account::getBalance() const
{
	return balance;
}

std::string Account::getCurrency() const
{
	return currency;
}

// Setters

double Account::setBalance(double newBalance)
{
	balance = newBalance;
	return balance;
}