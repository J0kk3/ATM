#include "User.h"
#include <iostream>

/*
* @brief User class
* @param username - the username of the user
* @param pin - the pin of the user, must be 4 digits
* 
* This class is used to create a user object. It contains a username and a pin.
*/

//Default Constructor
User::User() : username(""), pin("0000"), userid(000000) {}

//Parameterized constructor
User::User(int userId) : userid(userId)//std::string userName, std::string pin) : userid(userId), username(userName), pin(pin)
{

		switch (userId)
		{
		case 911022:
			username = "Liv Danielsdottir";
			pin = "1111";
			break;
		case 850212:
			username = "Joakim Sjöström";
			pin = "2222";
			break;
		case 841130:

			username = "Meduart Juniku";
			pin = "3333";
			break;
		case 020427:
			username = "Leo Katakalidis";
			pin = "4444";
			break;
		case 760320:
			username = "Jimmy Wallener";
			pin = "5555";
			break;
		default:
			break;

		}
	setPin(pin);
}


//Getters
std::string User::getUsername() const
{
	return username;
}
std::string User::getPin() const
{
	return pin;
}
void User::userinfo(int info)	//Output
{


	switch (info)
	{

	case 1:
		std::cout << "\n\t\tPlease enter user ID:\n\t\t";
		break;
	case 2:
		system("cls");	//Rensar skärmen
		std::cout << "\a\n\t\tUser ID must be a 6-digit number.";
		break;
	case 3:
		system("cls");
		std::cout << "\a\n\t\tUser not found.";
		break;
	case 4:
		system("cls");
		std::cout << "\n\t\tPlease enter PIN:\n\t\t";
		break;
	case 5:
		system("cls");
		std::cout << "\a\n\t\tInvalid pin. Pin must be a 4-digit number.\n";
		break;
	case 6:
		system("cls");
		std::cout << "\n\t\tToo many incorrect attempts";
		break;
	case 7:
		system("cls");
		std::cout << "\n\t\tWelcome " << username;
		break;
	default:
		break;

	}


}

bool User::setUserID(std::string newUser) //Checks for non-digits and number of digits
{


	if (newUser.length() == 6)
	{
		bool validUser = true;
		for (char digit : newUser)
		{
			if (!std::isdigit(digit))
			{
				validUser = false;
				// Exit the loop early if a non-digit character
				break;
			}
		}
		if (validUser)
		{

			return true;
		}


	}

	userinfo(2);	// Validation failed
	return false;



}
bool User::setPin(std::string newPin)		 //Setter with validation
{
	if (newPin.length() == 4)
	{
		bool isValid = true;

		for (char digit : newPin)
		{
			if (!std::isdigit(digit))
			{
				isValid = false;
				// Exit the loop early if a non-digit character
				break;
			}
		}
		if (isValid)
		{
			if (newPin == pin)//if(newPin==get_pin())
			{
				pin = newPin;
				// Pin set successfully
				userinfo(7);
				return true;
			}
			else
			{
				userinfo(5);
				return false;
			}



		}
	}
	userinfo(5);	  // Validation failed
	return false;
}

