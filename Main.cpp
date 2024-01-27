// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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

void createAccounts(User& user) 
{
    std::string types[5]{ "Salary Account", "Savings Account", "Travel Account", "Check Account", "Retire Account" };
    std::string currencies[5]{ "SEK", "USD", "EUR", "GBP", "DKK" };

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 5);
    int size = dist(gen);

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

// createUsers() creates 5 users with 5 accounts each
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
        std::cout << e.what() << " Oops, something went wrong. Please try again.\n";
    }
}