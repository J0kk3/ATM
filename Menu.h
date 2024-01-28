#pragma once
#include "User.h"


class Menu
{
private:
	std::vector<User> users;
	bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users);
	void showAccounts(User& user);
	void updateAccountBalance(User& user, int fromAccount, int toAccount, double amount, double convertedAmount);
public:
	Menu(std::vector<User>& users);
	void login();
	void mainMenu(User& user);
	void returnToMain(User& user);
	void clearScreen();
	std::vector<User> getUsers();
	void exchangeCurrency(User& user);
	void transferMoney(User& user, int from, int to);
	
};



