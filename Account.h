// Account.h
#pragma once
#include <iostream>


class Account
{
private:
	double balance;
	std::string accountType;
	std::string currency;

public:
	Account(std::string accountType, double balance, std::string currency);
	void printAccounts() const;
	bool transferMoney(Account* accountFrom, double amount);
	std::string getCurrency() const;
	double getBalance() const;
	double setBalance(double newBalance);
};