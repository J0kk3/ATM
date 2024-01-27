// Account.h
#pragma once
#include <iostream>
#include "Currency.h"

class Account
{
private:
	double balance;
	std::string accountType;
	Currency currency;

public:
	Account(std::string accountType, double balance, const Currency& currency);

	void printAccounts() const;
	bool transferMoney(Account* accountFrom, double amount);
	std::string getCurrencyCode() const;
	double getBalance() const;
	double setBalance(double newBalance);
};