// ===================================================================================================================
//  Project Name: Dunder Mifflin Database
//  Developer: Group 4
//  Date: November 4th, 2021
//  Description: Company Database
//  Version 1.0
//
//   Configuration Variables:
//   
//
//   Development Team:
//       - Gutierrez, Raul
//         + Sales Rep menu
//         + Sales Rep categories
//         + Sales Rep class
//       - Caldwell, Aaron
//         + Product class
//         + Product menu
//       - Delgado, Stephanie
//         + Client class
//         + Client menu
//       - Escobedo, Jonathan
//         + PowerPoint Presentation
//       - Nguyen, Michael
//         + SalesHistory class
//         + Sales class
//         + Sales menu
//         + Main menu
//
//   Change Log:
//           Version         User        Date            Changes
// -------------------------------------------------------------------------------------------------------------------
//           1.0             Rgtz18      11/04/2021      Created header for code, added develoment team names, added directives
//           1.1             Rgtz18      11/10/2021      Created Sales reperesentatives menu, category & class 
// ===================================================================================================================

#include "Clients.h"
#include "Product.h"
#include "SalesHistory.h"
#include "Sales.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
SalesHistory history; //gets sales info
ifstream inFS;   // Input file stream
string fileRowData;     // File data
int fileRow;
int salesmanId;


// My Sales Rep Class//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class salesRep {
   public:
      void SetRepName(string revRepName) {
         repName = revRepName;
      }
      void SetRepAddress(string revRepAddress) {
         repAddress = revRepAddress;
      }
      void SetSalesToDate(double revSalesToDate) {
         salesToDate = revSalesToDate;
      }
      string GetRepName() const { return repName; }
      string GetRepAddress() const { return repAddress; }
      double GetSalesToDate() const { return salesToDate; }

   private:
      string repName = "NoName";
      string repAddress = "No Address";
      double salesToDate = 0.00;
};


void salesRepList() {
   // Open file
   cout << "Opening file SalesReps.txt." << endl;
   inFS.open("SalesReps.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }

   // Print read numbers to output
   cout << "Reading and printing sales rep list." << endl;

   inFS >> fileRowData;
   while (!inFS.fail()) {

      for(int x = 0; x < 4; x++){
         switch(x){
            case 0:
            cout << "sales rep ID: " << fileRowData << endl;
            break;
            case 1:
            cout << "sales rep: " << fileRowData << endl;
            break;
            case 2:
            cout << "sales rep address: " << fileRowData << endl;
            break;
            case 3:
            cout << "sales rep salary: " << fileRowData << endl << endl;
            break;
         }
      inFS >> fileRowData;

      }
      
      
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;

   // Done with file, so close it
   inFS.close();
}

void monthlySalesList(string receivedSalesmanId) {
   bool matchId = false;
   // Open file
   cout << "Opening file SalesReps.txt." << endl;
   inFS.open("SalesReps.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }
   // Print specific salesman
   cout << "Reading and printing specific salesman." << endl;
   inFS >> fileRowData;
   while (!inFS.fail()) {
      if(fileRowData == receivedSalesmanId){
         matchId = true;
         for(int x = 0; x < 4; x++){
            switch(x){
               case 0:
               cout << "sales rep ID: " << fileRowData << endl;
               break;
               case 1:
               cout << "sales rep: " << fileRowData << endl;
               break;
               case 2:
               cout << "sales rep address: " << fileRowData << endl;
               break;
               case 3:
               cout << "sales rep salary: " << fileRowData << endl << endl;
               break;
            }
         inFS >> fileRowData;
         }
      } else {
         inFS >> fileRowData;   
      }  
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;
   if (matchId == false){
    cout << "ID not found. " << endl;  
   }
   // Done with file, so close it
   inFS.close();
}
void newSalesRep() {
//READING
string completeString = "";
cout << "Opening file SalesReps.txt." << endl;
   inFS.open("SalesReps.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }
   // Compile everytihg into one variable
   inFS >> fileRowData;
   while (!inFS.fail()) {
         completeString = completeString + fileRowData + "\n";
         inFS >> fileRowData;    
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;
   // Done with file, so close it
   inFS.close();

//WRITING
string userInput = "";
ofstream outFS;
outFS.open("SalesReps.txt");
if (!outFS.is_open()) {
   cout << "Could not open file SalesReps.txt." << endl;
   return;
}
//Enter Salesman ID
cout << "Enter Salesman ID:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";
//Enter Salesman Name
cout << "Enter Salesman Name:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";
//Enter Salesman Address
cout << "Enter Salesman Address:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";
//Enter Salesman Sales to Date
cout << "Enter Salesman Sales To Date:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";

outFS << completeString;

//Close File
outFS.close();

salesRepList();

}
void updateRepInfo(string receivedSalesmanId){
//READING
string completeString = "";
string userInput = "";
cout << "Opening file SalesReps.txt." << endl;
   inFS.open("SalesReps.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }
   // Compile everytihg into one variable
   inFS >> fileRowData;
   while (!inFS.fail()) {
      if (fileRowData == receivedSalesmanId) {
         //Enter Salesman ID
         cout << "Enter Salesman ID:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         //Enter Salesman Name
         cout << "Enter Salesman Name:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         //Enter Salesman Address
         cout << "Enter Salesman Address:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         //Enter Salesman Sales to Date
         cout << "Enter Salesman Sales To Date:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         inFS >> fileRowData;
         inFS >> fileRowData;
         inFS >> fileRowData;
      } else {
         completeString = completeString + fileRowData + "\n";
      }
         inFS >> fileRowData;    
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;
   // Done with file, so close it
   inFS.close();

   ofstream outFS;
   outFS.open("SalesReps.txt");
   if (!outFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }

outFS << completeString;

//Close File
outFS.close();

salesRepList();

}
void calcSalesBonus(string receivedSalesmanId){
cout << "Opening file SalesReps.txt." << endl;
   inFS.open("SalesReps.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file SalesReps.txt." << endl;
      return;
   }
   // Compile everytihg into one variable
   inFS >> fileRowData;
   while (!inFS.fail()) {
      if (receivedSalesmanId == fileRowData){
         inFS >> fileRowData;
         inFS >> fileRowData;
         inFS >> fileRowData;
         cout << "Total Sales is: " << stof(fileRowData) << endl;
         cout << "Bonus percetage is 2% " << endl;
         cout << "Total Bonus is: " << stof(fileRowData) * .02 << endl;
      }
      inFS >> fileRowData;
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;
   // Done with file, so close it
   inFS.close();





}
void salesRepMenu() {
char userSelect = '0';
string selectedId = "0";

while(userSelect != 'q'){  

cout << "1) " << "List of Current Sales Representatives" << endl;
cout << "2) " << "List of Current Monthly Sales" << endl;
cout << "3) " << "Add a new Sales Representative" << endl;
cout << "4) " << "Update Current Sales Representative Information" << endl;
cout << "5) " << "Calculate Yearly Bonus" << endl;
cout << "q) " << "Quit Sales Representatives Menu" << endl;
cout << endl;
cout << "Choose an option: " << endl;

cin >> userSelect;

     if (userSelect == '1'){
         salesRepList();
    }
     else if (userSelect == '2'){
        cout << "Enter an ID: " << endl;
        cin >> selectedId;
         monthlySalesList(selectedId);  
    } 
     else if (userSelect == '3'){
         newSalesRep();   
    }      
     else if (userSelect == '4'){
        cout << "Enter an ID to Update: " << endl;
        cin >> selectedId;
         updateRepInfo(selectedId);  
    }      
     else if (userSelect == '5'){
         cout << "Enter an ID: " << endl;
         cin >> selectedId;
         calcSalesBonus(selectedId);  
    }
     else if (userSelect == 'q') {
         return;  
    }
      else {
         cout << "Pressed Wrong Key. Press any key to try again " << endl;
      }
}      
}
//////Sales Rep Ends ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//client menu //

void clientMenu() {
char userSelect = '0';
string selectedId = "0";

while(userSelect != 'q'){  

cout << "1) " << "List of Current Clients" << endl;
cout << "2) " << "List of Specific Client Information" << endl;
cout << "3) " << "Add a new client" << endl;
cout << "4) " << "Update Current Client Information" << endl;
cout << "q) " << "Quit Client Menu" << endl;
cout << endl;
cout << "Choose an option: " << endl;

cin >> userSelect;

     if (userSelect == '1'){
         clientList();
    }
     else if (userSelect == '2'){
        cout << "Enter an ID: " << endl;
        cin >> selectedId;
         clientList(selectedId);  
    } 
     else if (userSelect == '3'){
         newClient();   
    }      
     else if (userSelect == '4'){
        cout << "Enter an ID to Update: " << endl;
        cin >> selectedId;
         updateClientInfo(selectedId);  
    
    }
     else if (userSelect == 'q') {
         return;  
    }
      else {
         cout << "Pressed Wrong Key. Press any key to try again " << endl;
      }
}      
}

//product menu //

void ProductMenu() {
   char userSelect = '0';
   string productName;
   double productPrice;
   double productSales;
   Product product;
   
   while(userSelect != 'q') {
      
      cout << "Product Menu" << endl;
      cout << "1) Add Product" << endl;
      cout << "2) Remove Product" << endl;
      cout << "3) Update Product" << endl;
      cout << "4) Print Product" << endl;
      cout << "5) Print All Products" << endl;
      cout << "q) " << "Quit Product Menu" << endl;
      cout << endl;
      cout << "Choose an option: " << endl;
      
      cin >> userSelect;
      cout << endl;
      
      if (userSelect == '1') {
         cout << "Enter a product name: " << endl;
         cin >> productName;
         cout << "Enter the price of the product: " << endl;
         cin >> productPrice;
         cout << "Enter how many were sold: " << endl;
         cin >> productSales;
         product.AddProduct(productName, productPrice, productSales);
         cout << endl;
      }
      else if (userSelect == '2') {
         cout << "Enter the name of the product you want to remove: " << endl;
         cin >> productName;
         product.RemoveProduct(productName);
         cout << endl;
      }
      else if (userSelect == '3') {
         cout << "Enter the name of the product you want to update: " << endl;
         cin >> productName;
         cout << "Enter the new price of the product: " << endl;
         cin >> productPrice;
         cout << "Enter how many were sold: " << endl;
         cin >> productSales;
         product.UpdateProduct(productName, productPrice, productSales);
         cout << endl;
      }
      else if (userSelect == '4') {
         cout << "Enter the name of the product you want to print: " << endl;
         cin >> productName;
         product.PrintProduct(productName);
         cout << endl;
      }
      else if (userSelect == '5') {
         product.PrintAllProducts();
         cout << endl;
      }
      else if (userSelect == 'q') {
         return;  
      }
      else {
         cout << "Pressed Wrong Key. Press any key to try again " << endl;
      }
   }
}

int main() {

    string userSelect = "";
    //shows list of options user can select from
    //loop for user input until they enter the letter 'q' which exits the program
    while (userSelect != "q") {
        cout << "Dunder Mifflin Database" << endl;
        cout << "1) " << "Product Menu" << endl;
        cout << "2) " << "Sales Menu" << endl;
        cout << "3) " << "Client Menu" << endl;
        cout << "4) " << "Sales Representatives Menu" << endl;
        cout << "q) " << "Quit Program" << endl << endl;
        cout << "Choose an option: " << endl;

        getline(cin, userSelect);

        //options must be numbers 1-4 or q, calls function respective to option stated
        if (userSelect == "1") {
            ProductMenu();
        }
        else if (userSelect == "2") {
            history.SalesHistoryMenu();
        }
        else if (userSelect == "3") {
            clientMenu();
        }
        else if (userSelect == "4") {
            salesRepMenu();
        }
        else if (userSelect == "q") {
            return 0;
        }
        else {
            cout << "Please enter one key from the list of options." << endl << endl;
        }
    }

    return 0;
}
