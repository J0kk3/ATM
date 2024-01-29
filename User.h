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
	User(std::string username, std::string pin);

	//Getters
	std::string getUsername() const;
	std::string getPin() const;
	std::vector<Account>& getAccounts();

	//Setter with validation
	void addAccount(Account newAccount);
};