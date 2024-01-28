// Account.cpp
// Purpose: Source file for Account class
#include "Account.h"


/**
 * @brief Constructs an Account object with the specified account type, balance, and currency.
 * @param accountType The account type.
 * @param balance The account balance.
 * @param currency The currency of the account.
 */
Account::Account(std::string accountType, double balance, const Currency& currency) : 
	accountType(accountType), balance(balance), currency(currency) {}


/**
 * @brief Prints the account details.
 */
void Account::printAccounts()
{
	std::cout << "\t" << accountType << "\t\t" << balance << "\t\t" << currency.getCurrencyCode() << "\n";
}


/**
 * @brief Transfers money from one account to another.
 * @param accountFrom The account to transfer money from.
 * @param amount The amount of money to transfer.
 * @return True if the transfer was successful, false otherwise.
 */
bool Account::transferMoney(Account& accountFrom, double amount)
{

	try
	{
		// Check if the accountFrom has sufficient balance and if the accountFrom and accountTo have the same currency before transferring
		if ((accountFrom.getBalance() >= amount) &&
			(accountFrom.getCurrencyCode() == currency.getCurrencyCode()))
		{
			accountFrom.setBalance(accountFrom.getBalance() - amount);
			balance += amount;
			return true;
		}
		else if (accountFrom.getCurrencyCode() != currency.getCurrencyCode())
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
	catch (const std::exception& e)
	{
		std::cout << e.what() << "Unable to transfer money\n";
	}

	return false;
}

// Getters

/**
 * @brief Gets the balance of the account.
 * @return The balance of the account.
 */
double Account::getBalance() const
{
	return balance;
}

/**
 * @brief Gets the account type of the account.
 * @return The account type of the account.
 */
std::string Account::getAccountName() const
{
	return accountType;
}

/**
 * @brief Gets the currency code of the account.
 * @return The currency code of the account.
 */
std::string Account::getCurrencyCode() const
{
	return currency.getCurrencyCode();
}

// Setters

/**
 * @brief Sets the balance of the account.
 * @param newBalance The new balance of the account.
 * @return The updated balance of the account.
 */
double Account::setBalance(double newBalance)
{
	balance = newBalance;
	return balance;
}