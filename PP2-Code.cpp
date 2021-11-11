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
string salesName;     // File data


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
      cout << "Could not open file myfile.txt." << endl;
      return;
   }

   // Print read numbers to output
   cout << "Reading and printing numbers." << endl;

   inFS >> salesName;
   while (!inFS.fail()) {
      cout << "sales rep: " << salesName << endl;
      inFS >> salesName;
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file SalesReps.txt." << endl;

   // Done with file, so close it
   inFS.close();
}
void monthlySalesList() {
cout << "List of Current Monthly Sales" << endl; 
}
void newSalesRep() {
cout << "Add a new Sales Representative" << endl;
}
void updateRepInfo(){
cout << "Update Current Sales Representative Information" << endl;
}
void saveRepInfo(){
cout << "Save Updated Sales Representative Information" << endl;
}
void salesRepMenu() {
char userSelect = '0';

while(userSelect != '1' && userSelect != '2' && userSelect != '3' && userSelect != '4' && userSelect != '5'){  

cout << "1) " << "List of Current Sales Representatives" << endl;
cout << "2) " << "List of Current Monthly Sales" << endl;
cout << "3) " << "Add a new Sales Representative" << endl;
cout << "4) " << "Update Current Sales Representative Information" << endl;
cout << "5) " << "Save Updated Sales Representative Information" << endl;
cout << endl;
cout << "Choose an option: " << endl;

cin >> userSelect;

     if (userSelect == '1'){
         salesRepList();
    }
     else if (userSelect == '2'){
         monthlySalesList();  
    } 
     else if (userSelect == '3'){
         newSalesRep();   
    }      
     else if (userSelect == '4'){
         updateRepInfo();  
    }      
     else if (userSelect == '5'){
         saveRepInfo();  
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