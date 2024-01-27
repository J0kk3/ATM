#pragma once
#include "User.h"


class Menu
{
private:
	std::vector<User> users;
	bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users);
	void showAccounts(User& user);
public:
	Menu(std::vector<User>& users);
	void login();
	void mainMenu(User& user);
	void returnToMain(User& user);
	void clearScreen();
	std::vector<User> getUsers();
};



