// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "User.cpp"

int main()
{
	int userID, tryPin = 3;
	std::string user, pin;
	User start(0);


beginning:
	start.userinfo(1);	  //Uppmanar anv�ndare att skriva in user ID

	std::cin >> user;						   

	if (start.setUserID(user) == false)	  //Kollar s� att de �r digits och antal
		goto beginning;

	userID = stoi(user);   //Konverterar till int f�r att kunna skickas till switch
	User one(userID);	  //Anv�ndarobjekt skapat

	

	/****** Anv�nde name eftersom att user initeras i main(), men det finns garanterat b�ttre s�tt att kolla input mot user*****/

	if ("" == one.get_name())	 //Kollar ifall anv�ndare finns.
	{
		start.userinfo(3);
		goto beginning;	  //g�r till start 

	}

	start.userinfo(4);	  //Uppnaming om att skriva in pin

	do
	{

		std::cin >> pin;
		if (one.setPin(pin) == false)
		{
			tryPin--;
			std::cout << "\t\t" << tryPin << " attempts remaining\n\t\t";

		}
		if (tryPin == 0)
		{
			start.userinfo(6);
			break;

		}



	} while (tryPin >= 0);
}