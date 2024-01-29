#include "User.h"
#include <iostream>

/*
* @brief User class
* @param username - the username of the user
* @param pin - the pin of the user, must be 4 digits
*
* This class is used to create a user object. It contains a username and a pin.
*/


//Parameterized constructor
User::User(std::string userName, std::string pin) : username(userName), pin(pin), accounts(accounts)
{}

//Getters
std::string User::getUsername() const
{
	return username;
}

std::string User::getPin() const
{
	return pin;
}
std::vector<Account>& User::getAccounts()
{
	return accounts;
}

void User::addAccount(Account newAccount)
{
	accounts.push_back(newAccount);

}