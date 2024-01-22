// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h> 
#include "User.h"

void displayMeny();

void returnToMeny()
{
   std::cout << "\nTo go back to the main meny, please press [ENTER].\nTo exit press any other key.";
   char input;
   input = _getch();
   if(int(input) == 13){ // ([ENTER] i int == 13)
      displayMeny();
   } // else logOut() ? 
}

void displayMeny()
{
   bool activateLoop = true;

   while(activateLoop){
      std::cout << "Please choose one alternative\n\n1. See account and balance\n"
                << "2. Transfer between accounts\n3. Exchange money\n4. Log out\n";

      char option; // fixa infnite loop.  
      std::cin >> option; 

      switch (option){
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

int main()
{
   // behöver skapa objekt av user för att hämta username
   // fixa vanligt välkomnande till banken också. 
   std::cout << "\nWelcome to the bank"; // << currentUser\n\n;
   displayMeny();
}
