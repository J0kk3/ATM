// Account.h
#pragma once
#include <iostream>


class Account
{
private:
	int accountNumber;
	double balance;
	std::string accountType;
	std::string currency;

public:
	Account(int accountNumber, std::string accountType, double balance, std::string currency);
	void printAccounts() const;
	bool transferMoney(Account* accountFrom, double amount);
	std::string getCurrency() const;
};