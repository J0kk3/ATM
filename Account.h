// Account.h
#pragma once
#include <iostream>
#include <memory>

class Account
{
private:
		std::string accountName;
		int accountNumber;
		double balance;
public:
	Account(int accountNumber, std::string accountName, double balance);
	void printAccounts() const;
	bool transferMoney(std::shared_ptr<Account> accountFrom, std::shared_ptr<Account> accountTo, double amount);
};

// Path: Account.cpp