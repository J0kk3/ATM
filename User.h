#pragma once
#include <string>
#include <vector>

#include "Account.h"

class User
{
private:
	std::string username;
	std::string pin;
	std::vector<Account> accounts;

public:
	//Constructors
	User();
	User(std::string username, std::string pin);

	//Getters
	std::string getUsername();
	std::string getPin();
	std::vector<Account> getAccounts() const;

	//Setter with validation
	bool setPin(std::string newPin);
	void addAccount(Account newAccount);
};