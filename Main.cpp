
/*
* File: Main.cpp
* Authors: Joakim Sjöström, Liv Danielsdottir, Leo Katakalidis, Jimmy Wallener
* Date: 2024-01-29
* Description: Main file for the ATM program.
* ATM is a program that simulates an ATM machine.
* The program allows the user to log in, view their accounts, transfer money between accounts, exchange currency, and log out.
* User.h and User.cpp contains the User class which represents a user.
* Account.h and Account.cpp contains the Account class which represents an account.
* Currency.h and Currency.cpp contains the Currency class which represents a currency.
* Menu.h and Menu.cpp contains the Menu class which is used to display the menu and handle user input.
*/

#include <iostream>
#include <conio.h>
#include <vector>
#include <random>
#include "User.h"
#include "Menu.h"

void runProgram();

int main()
{   
    runProgram();
    return 0;
}

/**
 * Generates random account details for a user.
 * 
 * @param user The user for whom the accounts will be created.
 */
void createAccounts(User& user) 
{
    std::string types[5]{ "Salary Account", "Savings Account", "Travel Account", "Check Account", "Retire Account" };
    Currency currencies[5] = { Currency("SEK"), Currency("DKK"), Currency("EUR"), Currency("GBP"), Currency("USD") };

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 5);
    int size = dist(gen);

    try
    {
        // Generate random account details for each account
        for (size_t i = 0; i < size; i++)
        {
            std::uniform_int_distribution<int> currencyDist(0, 4);
            int currencyIndex = currencyDist(gen);
            std::uniform_int_distribution<int> balanceDist(0, 10000);
            double balance = balanceDist(gen);
            user.addAccount(Account(types[i], balance, currencies[currencyIndex]));
        }
    }
    catch (const std::exception& e)
    {
		std::cout << e.what() << " Oops, something went wrong when creating accounts.\n";

    }

  
}


/**
 * Runs the ATM program.
 * 
 * This function initializes the users, creates random account details for each user,
 * and starts the login process by displaying the menu.
 */
static void runProgram()
{
    std::vector<User> users;
    std::string username[5]{ "Joakim", "Leo", "Liv", "Jimmy", "John" };
    std::string pin[5]{ "1111", "2222", "3333", "4444", "5555" };

    // Get the size of the username array using the sizeof operator and dividing it by the size of the first element
    size_t size = sizeof(username) / sizeof(username[0]);

    try
    {
        for (size_t i = 0; i < size; i++)
        {
            User user(username[i], pin[i]);
            createAccounts(user);
            users.push_back(user);
        }

        Menu menu(users);
        menu.login();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << " Oops, something went wrong when creating users.\n";
    }
}