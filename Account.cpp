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