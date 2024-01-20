// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 

void displayMeny()
{
   bool activateLoop = true;

   while(activateLoop){
      std::cout << "Please choose one alternative\n\n1. See account and balance\n"
                << "2. Transfer between accounts\n3. Exchange money\n4. Log out\n";

      int option; 
      std::cin >> option; 

      switch (option){
         case 1:
            // seKonto()
            activateLoop = false; 
            break;
   
         case 2:
            // överför()
            activateLoop = false; 
            break; 

         case 3: 
            // växla()
            activateLoop = false; 
            break;

         case 4: 
            // loggaUt()
            activateLoop = false; 
            break;

         default:
            std::cout << "\n\nInvalid input, please try again\n";
      }
   }
}

int main()
{
   // string currentUser = getUsername(); 
   std::cout << "\nWelcome to the bank"; // << currentUser\n\n;
   displayMeny();
}