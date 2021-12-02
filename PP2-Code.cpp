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
//       - Delgado, Stepahnie
//       - Escobedo, Jonathan
//       - Kim, Arthur
//       - Nguyen, Michael
//
//   Change Log:
//           Version         User        Date            Changes
// -------------------------------------------------------------------------------------------------------------------
//           1.0             Rgtz18      11/04/2021      Created header for code, added develoment team names, added directives
//           1.1             Rgtz18      11/10/2021      Created Sales reperesentatives menu, category & class 
// ===================================================================================================================


#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
ifstream inFS;   // Input file stream
string fileRowData;     // File data
int fileRow;
int salesmanId;


// My Sales Rep Class 
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

while(userSelect != '1' && userSelect != '2' && userSelect != '3' && userSelect != '4' && userSelect != '5'){  

cout << "1) " << "List of Current Sales Representatives" << endl;
cout << "2) " << "List of Current Monthly Sales" << endl;
cout << "3) " << "Add a new Sales Representative" << endl;
cout << "4) " << "Update Current Sales Representative Information" << endl;
cout << "5) " << "Calculate Yearly Bonus" << endl;
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
      else {
         cout << "Pressed Wrong Key. Press any key to try again " << endl;
      }
}      
}




int main () {

salesRepMenu();

   return 0;
}