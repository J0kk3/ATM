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
*   @param accountName - the account name
*   @param balance - the account balance
*    
*/

Account::Account(const int accountNumber, const std::string accountName, double balance) : accountNumber(accountNumber), accountName(accountName), balance(balance)
{}

void Account::printAccounts() const
{
	std::cout << "Account Number: " << accountNumber << std::endl;
	std::cout << "Account Name: " << accountName << std::endl;
	std::cout << "Account Balance: " << balance << std::endl;
}

// using smart pointers to transfer money between accounts for easy memory management
bool Account::transferMoney(std::shared_ptr<Account> accountFrom, std::shared_ptr<Account> accountTo, double amount)
{
	// Check if the accountFrom has sufficient balance to transfer
	if (accountFrom && accountFrom->balance >= amount)
	{
		accountFrom->balance -= amount;
		accountTo->balance += amount;
		return true;
	}
	else
	{
		std::cout << "Insufficient balance to transfer" << std::endl;
		return false;
	}
}