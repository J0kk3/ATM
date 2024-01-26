// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <conio.h>
#include <vector>
#include <random>
#include "User.h"



void createUsers(std::vector<User>& users);
void createAccounts(User& user);
void loginWindow(const std::vector<User>& users);
bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users);
void displayMeny();





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
    int accountNumber[5]{ 1234, 2345, 3456, 4567, 5678 };
    double balance[5]{ 1000, 2000, 3000, 4000, 5000 };
    std::string types[5]{ "L\u00F6nekonto", "Sparkonto", "Resekonto", "Personkonto", "F\u00F6retagskonto" };
    std::string currencies[5]{ "SEK", "USD", "EUR", "GBP", "DKK" };
    size_t size = sizeof(accountNumber) / sizeof(accountNumber[0]);

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generate random account details for each account
    for (size_t i = 0; i < size; i++) {


        // Generate random number of types from array to each account
        std::uniform_int_distribution<int> dist(1, 5);
        int numTypes = dist(gen);
        for (int j = 0; j < numTypes; j++) {
            std::uniform_int_distribution<int> typeDist(0, 4);
            int typeIndex = typeDist(gen);
            std::uniform_int_distribution<int> currencyDist(0, 4);
            int currencyIndex = currencyDist(gen);
            std::uniform_int_distribution<int> balanceDist(0, 10000);
            double balance = balanceDist(gen);
            user.addAccount(Account(accountNumber[i], types[typeIndex], balance, currencies[currencyIndex]));
        }


    }
}

// authenticateUser() returns true if the username and pin match a user in the users vector
bool authenticateUser(const std::string& username, const std::string& pin, const std::vector<User>& users)
{
    for (User user : users) {
        if (user.getUsername() == username && user.getPin() == pin) {
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
            std::cout << "\nLogin successful!\n";
            displayMeny();
            return;
        }
        else {
            std::cout << "\nInvalid username or pin code. Please try again.\n";
            maxAttempts--;
        }
    }

    std::cout << "\nToo many failed login attempts. Program will terminate.\n";
}


static void returnToMeny()
{
    std::cout << "\nTo go back to the main meny, please press [ENTER].\nTo exit press any other key.";
    char input = _getch();
    if (int(input) == 13) { // ([ENTER] i int == 13)
        displayMeny();
    } // else logOut() ? 
}

void displayMeny()
{
    bool activateLoop = true;

    while (activateLoop) {
        std::cout << "Please choose one alternative\n\n1. See account and balance\n"
            << "2. Transfer between accounts\n3. Exchange money\n4. Log out\n";

        char option; // fixa infnite loop.  
        std::cin >> option;

        switch (option) {
        case '1':
            // seKonto()
            activateLoop = false;
            returnToMeny();
            break;

        case '2':
            // överför()
            activateLoop = false;
            returnToMeny();
            break;

        case '3':
            // växla()
            activateLoop = false;
            returnToMeny();
            break;

        case '4':
            // loggaUt()
            activateLoop = false;
            // gå tillbaka till logga in funktion? 
            break;

        default:
            std::cout << "\n\nInvalid input, please try again\n";
        }
    }
}