// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <conio.h>
#include <vector>
#include <random>
#include "User.h"
#include "Currency.h"

void createUsers(std::vector<User>& users);
void createAccounts(User& user);
void loginWindow(const std::vector<User>& users);
bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users);
void showAccounts(User& user);
void displayMenu(User& user);
void returnToMenu(User& user);

std::string fromCurrencyCode;
std::string toCurrencyCode;

int main()
{
    std::vector<User> users;
    std::vector<User>* usersPtr = &users;

    createUsers(*usersPtr);

    loginWindow(*usersPtr);
}

// createUsers() creates 5 users with 5 accounts each
void createUsers(std::vector<User>& users) {
    std::string username[5]{ "user1", "user2", "user3", "user4", "user5" };
    std::string pin[5]{ "1111", "2222", "3333", "4444", "5555" };
    size_t size = sizeof(username) / sizeof(username[0]);

    for (size_t i = 0; i < size; i++) {
        User user(username[i], pin[i]);
        createAccounts(user);
        users.push_back(user);
    }
}

void createAccounts(User& user) {
    std::string types[5]{ "L\u00F6nekonto", "Sparkonto", "Resekonto", "Personkonto", "F\u00F6retagskonto" };
    std::string currencies[5]{ "SEK", "USD", "EUR", "GBP", "DKK" };

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 5);
    int size = dist(gen);
    // Generate random account details for each account
    for (size_t i = 0; i < size; i++) {
        std::uniform_int_distribution<int> typeDist(0, 4);
        int typeIndex = typeDist(gen);
        std::uniform_int_distribution<int> currencyDist(0, 4);
        int currencyIndex = currencyDist(gen);
        std::uniform_int_distribution<int> balanceDist(0, 10000);
        double balance = balanceDist(gen);
        std::uniform_int_distribution<int> accountNumber(1000, 9999);
        int accountNo = accountNumber(gen);
        user.addAccount(Account(accountNo, types[typeIndex], balance, currencies[currencyIndex]));

        // Generate random number of types from array to each account
       /* std::uniform_int_distribution<int> dist(1, 5);
        int numTypes = dist(gen);
        for (int j = 0; j < numTypes; j++) {

        }*/
    }
}

// authenticateUser() returns true if the username and pin match a user in the users vector
bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users)
{
    for (User user : users) {
        if (user.getUsername() == username && user.getPin() == pin) {
            std::cout << "\nLogin successful!\n";
            displayMenu(user);
            return true;
        }
    }
    return false;
}

// loginWindow() allows the user to login to the ATM with their username and pin, and displays the main menu if successful
void loginWindow(const std::vector<User>& users)
{
    int maxAttempts = 3;
    std::string username;
    std::string pin;

    while (maxAttempts > 0) {
        std::cout << "\nWelcome to the Bank ATM\n";
        std::cout << "Please enter your username: ";
        std::cin >> username;
        std::cout << "Please enter your pin code: ";
        std::cin >> pin;

        if (authenticateUser(username, pin, users)) {
            return;
        }
        else {
            std::cout << "\nInvalid username or pin code. Please try again.\n";
            maxAttempts--;
            std::cout << "\nThere are " << maxAttempts << " left.\n";
        }
    }

    std::cout << "\nToo many failed login attempts. Program will terminate.\n";
}


static void returnToMenu(User& user)
{
    std::cout << "\nTo go back to the main menu, please press [ENTER].\nTo exit press any other key.";
    char input = _getch();
    if (int(input) == 13) { // ([ENTER] i int == 13)
        displayMenu(user);
    } // else logOut() ?
}

void showAccounts(User& user) {
    std::vector<Account> accounts = user.getAccounts();

    for (auto account : accounts) {
        account.printAccounts();
    }
}

void displayMenu(User& user)
{
    bool activateLoop = true;

    while (activateLoop) {
        std::cout << "Please choose one alternative\n\n1. See account and balance\n"
            << "2. Transfer between accounts\n3. Exchange money\n4. Log out\n";

        char option; // fixa infnite loop.
        std::cin >> option;

        switch (option) {
        case '1':
            showAccounts(user);
            activateLoop = false;
            returnToMenu(user);
            break;

        case '2':
            // överför()
            activateLoop = false;
            returnToMenu(user);
            break;

        case '3':
            // växla()
            double convertedAmount;
            double reversedAmount;
            double amount;
            std::cout << "Enter fromCurrencyCode:";
            std::cin >> fromCurrencyCode;
            std::cout << "Enter toCurrencyCode:";
            std::cin >> toCurrencyCode;
            std::cout << "Enter amount you want to exchange from " << fromCurrencyCode << " to " << toCurrencyCode << ":";
            std::cin >> amount;
            std::cout << "\n";
            convertedAmount = Currency::convertAmount(fromCurrencyCode, toCurrencyCode, amount);
            std::cout << "Converted amount: " << convertedAmount << " " << toCurrencyCode << "\n";
            reversedAmount = Currency::reverseConvert(toCurrencyCode, convertedAmount);
            std::cout << "Reversed amount: " << reversedAmount << " " << fromCurrencyCode << "\n";
            activateLoop = false;
            returnToMenu(user);
            break;

        case '4':
            // loggaUt()
            activateLoop = false;
            // gå tillbaka till logga in funktion?
            break;

        default:
            std::cout << "\n\nInvalid input, please try again\n";
            break;
        }
    }
}