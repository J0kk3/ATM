#include "User.h"
#include <iostream>

/*
* @brief User class
* @param username - the username of the user
* @param pin - the pin of the user, must be 4 digits
*
* This class is used to create a user object. It contains a username and a pin.
*/

//Default Constructor
User::User() : username(""), pin("0000") {}

//Parameterized constructor
User::User(std::string userName, std::string pin) : username(userName), pin(pin)
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
std::vector<Account> User::getAccounts() const
{
	return accounts;
}

// Unused setter
/*
//Setter with validation
bool User::setPin(std::string newPin)
{
	// Check if the pin is a numeric string
	if (newPin.length() == 4)
	{
		bool isValid = true;

		for (char digit : newPin)
		{
			if (!std::isdigit(digit))
			{
				isValid = false;
				// Exit the loop early if a non-digit character
				break;
			}
		}

		if (isValid)
		{
			pin = newPin;
			// Pin set successfully
			return true;
		}
	}

	// Validation failed
	std::cout << "Invalid pin. Pin must be a 4-digit number." << std::endl;
	return false;
}
*/
void User::addAccount(Account newAccount)
{
	accounts.push_back(newAccount);

}