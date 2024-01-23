#pragma once
#include <string>

class User
{
private:
	std::string username;
	std::string pin;
	int userid;

public:

	//Constructors
	User();
	User(int userId);//std::string username, std::string pin);

	//Getters
	std::string getUsername() const;
	std::string getPin() const;

	//Setter with validation
	bool setPin(std::string newPin);
	bool setUserID(std::string newUser);

	//Methods
	void userinfo(int info);
};