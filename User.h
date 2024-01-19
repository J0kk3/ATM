#pragma once
#include <string>

class User
{
private:
	std::string username;
	std::string pin;

public:
	//Constructors
	User();
	User(std::string username, std::string pin);

	//Getters
	std::string getUsername() const;
	std::string getPin() const;

	//Setter with validation
	bool setPin(std::string newPin);
};