#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Currency.h"

Menu::Menu(std::vector<User>& users) : users(users) {};

std::string fromCurrencyCode;
std::string toCurrencyCode;

bool Menu::authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users) 
{
    for (User user : users) 
    {
        
        if (user.getUsername() == username && user.getPin() == pin) 
        {
            clearScreen();
            std::cout << "\nLogin successful!\n";
            mainMenu(user);
            return true;
        }
    }
    return false;
}

void Menu::showAccounts(User& user) 
{
    std::vector<Account> accounts = user.getAccounts();

    std::cout << "\n\t==================== Your accounts =====================\n\n";
    std::cout << "\tAccount type\t\tBalance\t\tCurrency\n\n";
    std::cout << "  ---------------------------------------------------------\n";
    for (auto& account : accounts) 
    {
        size_t index = &account - &accounts[0];
        std::cout << index + 1 << ". ";
        account.printAccounts();
        std::cout << "\n  ---------------------------------------------------------\n";
    }
}

void Menu::login() 
{
    std::string username;
    std::string pin;
    std::vector<User> users = getUsers();
    bool isAuthenticated = false;
    int maxAttempts = 3;

    std::cout << "\n======== Welcome to the Bank ATM =========\n\n";

    while (maxAttempts > 0) 
    {
        std::cout << "Please enter your username: ";
        std::cin >> username;
        std::cout << "Please enter your pin code: ";
        std::cin >> pin;

        isAuthenticated = authenticateUser(username, pin, users);

        if (!isAuthenticated) 
        {
            std::cout << "\nInvalid username or pin code. Please try again.\n";
            maxAttempts--;
            std::cout << "There are " << maxAttempts << " left.\n";
        }
    }
    std::cout << "Too many failed login attempts. Program will terminate.\n";
}

void Menu::returnToMain(User& user)
{
    std::cout << "\n\nTo go back to the main menu, please press [ENTER].\nTo exit press any other key.";
    char input = _getch();
    if (int(input) == 13) 
    { // ([ENTER] i int == 13)
        mainMenu(user);
    } // else logOut() ? 
}

void Menu::mainMenu(User& user) 
{
    bool isRunning = true;

    std::cout << "\nWelcome " << user.getUsername() << "!\n\n";
    while (isRunning) 
    {
        std::cout << "1. See account and balance\n";
        std::cout << "2. Transfer between accounts\n";
        std::cout << "3. Exchange money\n";
        std::cout << "4. Log out\n";

        int choice;
        std::cin >> choice;

        switch (choice) 
        {
            case 1:
                clearScreen();
                showAccounts(user);
                isRunning = false;
                returnToMain(user);
                break;
            case 2:
        
                break;
            case 3:
                clearScreen();
                double amount;
                double convertedAmount;
                double reverseAmount;

                std::cout << "Enter fromCurrencyCode:";
                std::cin >> fromCurrencyCode;
                std::cout << "Enter toCurrencyCode:";
                std::cin >> toCurrencyCode;
                std::cout << "Enter amount you want to exchange from " << fromCurrencyCode << " to " << toCurrencyCode << ":";
                std::cin >> amount;
                std::cout << "\n";

                convertedAmount = Currency::convertAmount(fromCurrencyCode, toCurrencyCode, amount);
                reverseAmount = Currency::convertAmount(toCurrencyCode, fromCurrencyCode, convertedAmount);
                std::cout << "Converted amount: " << convertedAmount << " " << toCurrencyCode << "\n";
                std::cout << "Reverse converted amount: " << reverseAmount << " " << fromCurrencyCode << "\n";

                returnToMain(user);
                break;
            case 4:
                std::cout << "Logging out...\n";
                isRunning = false;
                clearScreen();
                login();
                break;
            default:
                std::cout << "Wrong choice. Please try again!\n";
                mainMenu(user);
                break;
        }
    }
}

std::vector<User> Menu::getUsers()
{
	return users;
}

void Menu::clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#else
    std::cout << std::string(100, '\n');
#endif
}