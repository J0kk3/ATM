#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Currency.h"

Menu::Menu(std::vector<User>& users) : users(users) {};



/**
 * Authenticates a user by comparing the provided username and pin with the users in the system.
 * If the authentication is successful, it clears the screen, displays a login successful message,
 * and navigates to the main menu for the authenticated user.
 * 
 * @param username The username to authenticate.
 * @param pin The pin code to authenticate.
 * @param users The vector of users in the system.
 * @return True if the authentication is successful, False otherwise.
 */
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


/**
 * Displays the accounts and their details for a given user.
 * 
 * @param user The user whose accounts to display.
 */
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


/**
 * Logs in a user by prompting for their username and pin code.
 * If the authentication is successful, it clears the screen, displays a login successful message,
 * and navigates to the main menu for the authenticated user.
 * If the authentication fails, it displays an error message and allows the user to try again.
 * If the maximum number of login attempts is reached, it terminates the program.
 */
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


/**
 * Returns the user to the main menu if they press [ENTER], otherwise logs them out.
 * 
 * @param user The authenticated user.
 */
void Menu::returnToMain(User& user)
{
    std::cout << "\n\nTo go back to the main menu, please press [ENTER].\nTo exit press any other key.";
    char input = _getch();
    if (int(input) == 13) 
    { // ([ENTER] i int == 13)
        mainMenu(user);
    } // else logOut() ? 
}



/**
 * Updates the balance of the accounts after a successful exchange.
 *
 * @param user The user whose accounts to update.
 * @param fromAccount The index of the account to exchange from.
 * @param toAccount The index of the account to exchange to.
 * @param amount The amount to exchange.
 * @param convertedAmount The converted amount after the exchange.
 */
void Menu::updateAccountBalance(User& user, int fromAccount, int toAccount, double amount, double convertedAmount)
{
    std::vector<Account> accounts = user.getAccounts();
    accounts[fromAccount].setBalance(accounts[fromAccount].getBalance() - amount);
    accounts[toAccount].setBalance(accounts[toAccount].getBalance() + convertedAmount);
}


/**
 * Exchanges currency between two given currency codes.
 *
 * @param user The user performing the currency exchange.
 */
void Menu::exchangeCurrency(User& user)
{
    double amount;
    double convertedAmount;
    std::string fromCurrencyCode;
    std::string toCurrencyCode;

    std::cout << "\n======== Exchange currency =========\n\n";

    std::cout << "Your accounts: \n";
    showAccounts(user);

    std::cout << "\n\n";

    std::cout << "Please enter the account you want to exchange from: ";
    int fromAccount;
    std::cin >> fromAccount;
    fromCurrencyCode = user.getAccounts()[static_cast<std::vector<Account, std::allocator<Account>>::size_type>(fromAccount) - 1].getCurrencyCode();
    std::cout << "How much do you want to exchange? ";
    std::cin >> amount;
    std::cout << "Available currencies: " << Currency::getCurrencyCodes() << "\n\n";
    std::cout << "To which currency do you want to exchange? ";
    std::cin >> toCurrencyCode;

    std::vector<Account> accounts = user.getAccounts();

    for (size_t i = 0; i < accounts.size(); i++)
    {
        Account& account = accounts[i];
        if (account.getBalance() >= amount && account.getCurrencyCode() == toCurrencyCode)
        {
            std::cout << "You have account(s) with the currency code " << toCurrencyCode << ".\n";
            std::cout << "Account Number: " << i + 1 << "\n";
            std::cout << "Account name: " << account.getAccountName() << "\n";
            std::cout << "Balance: " << account.getBalance() << " " << account.getCurrencyCode() << "\n";

            std::cout << "Enter the account number you want to exchange to: ";
            int toAccount;
            std::cin >> toAccount;

            std::cout << "You want to exchange " << amount << " " << fromCurrencyCode << " to " << toCurrencyCode << "?\n";
            std::cout << "Enter [Y] to confirm or [N] to cancel: ";

            char input = _getch();

            if (int(input) == 89 || int(input) == 121)
            {
                convertedAmount = round(Currency::convertAmount(fromCurrencyCode, toCurrencyCode, amount) * 100) / 100;
                std::cout << "\nConverted amount: " << convertedAmount << " " << toCurrencyCode << "\n";
                std::cout << "Do you want to exchange? [Y] or [N]: ";
                char input = _getch();

                if (int(input) == 89 || int(input) == 121)
                {
                    updateAccountBalance(user, fromAccount - 1, toAccount - 1, amount, convertedAmount);
                    std::cout << "You have exchanged " << amount << " " << fromCurrencyCode << " to " << convertedAmount << " " << toCurrencyCode << "\n";
                    std::cout << "You have " << accounts[static_cast<std::vector<Account, std::allocator<Account>>::size_type>(fromAccount) - 1].getBalance() << " " << fromCurrencyCode << " left in your account.\n";
                    std::cout << "The account you exchanged to now has " << accounts[static_cast<std::vector<Account, std::allocator<Account>>::size_type>(toAccount) - 1].getBalance() << " " << toCurrencyCode << "\n\n";

                    std::cout << "Do you want to exchange more? [Y] or [N]: ";
                    char input = _getch();

                    if (int(input) == 89 || int(input) == 121)
                    {
                        exchangeCurrency(user);
                    }
                    else
                    {
                        std::cout << "Do you want to go back to the main menu? [Y] or [N]: ";
                        char input = _getch();

                        if (int(input) == 89 || int(input) == 121)
                        {
                            mainMenu(user);
                        }
                        else
                        {
                            std::cout << "Program will terminate.\n";
                        }
                    }

                    returnToMain(user);
                }
                else
                {
                    std::cout << "You have cancelled the exchange.\n";
                    returnToMain(user);
                }
            }
            else
            {
                std::cout << "You have cancelled the exchange.\n";
                returnToMain(user);
            }
        }
        else if (account.getBalance() < amount)
        {
            std::cout << "You don't have enough balance to exchange.\n";
            returnToMain(user);
        }
    }

    std::cout << "You don't have an account with the currency code " << toCurrencyCode << ".\n";
    std::cout << "Please create a new account with the currency code " << toCurrencyCode << ".\n";
    std::string accountName;
    std::cout << "Enter a name for the new account: ";
    std::cin.ignore();
    std::getline(std::cin, accountName);
    convertedAmount = round(Currency::convertAmount(fromCurrencyCode, toCurrencyCode, amount) * 100) / 100;
    user.addAccount(Account(accountName, convertedAmount, Currency(toCurrencyCode)));
}



/**
 * Displays the main menu for the authenticated user.
 * 
 * @param user The authenticated user.
 */
void Menu::mainMenu(User& user) 
{
    bool isRunning = true;
   
    // Display welcome message
    std::cout << "\nWelcome " << user.getUsername() << "!\n\n";
    
    while (isRunning) 
    {
        // Display menu options
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
                exchangeCurrency(user);
                isRunning = false;
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


/**
 * Retrieves the vector of users in the system.
 * 
 * @return The vector of users.
 */
std::vector<User> Menu::getUsers()
{
    return users;
}


/**
 * Clears the screen based on the operating system.
 * 
 * On Windows, it uses the "cls" command to clear the screen.
 * On Linux and macOS, it uses the "clear" command to clear the screen.
 * If the operating system is not recognized, it prints 100 newline characters to simulate clearing the screen.
 */
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