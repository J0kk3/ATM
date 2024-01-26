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

Account::Account(int accountNumber, std::string accountType, double balance, std::string currency) : accountNumber(accountNumber), accountType(accountType), balance(balance), currency(currency)
{}

void Account::printAccounts() const
{
	std::cout << "Account Number: " << accountNumber << "\n";
	std::cout << "Account Type: " << accountType << "\n";
	std::cout << "Account Balance: " << balance << "\n";
	std::cout << "Account Currency: " << currency << "\n";
	std::cout << std::endl;
}

// using smart pointers to transfer money between accounts for easy memory management
bool Account::transferMoney(Account* accountFrom, double amount)
{
	// Check if the accountFrom has sufficient balance to transfer
	if (accountFrom && accountFrom->balance >= amount)
	{
		accountFrom->balance -= amount;
		balance += amount;
		return true;
	}
	else
	{
		std::cout << "Insufficient balance to transfer\n";
		return false;
	}
}



std::string Account::getCurrency() const
{
	return currency;
}