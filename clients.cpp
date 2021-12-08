
#include "Clients.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>


ifstream inFS;  
string fileRowData;    
int fileRow;
int clientName;

class Clients {
   public:
      void SetClientName(string revClientName) {
         clientName = revClientName;
      }
      void SetClientAddress(string revClientAddress) {
         clientAddress = revClientAddress;
   
      }
      string GetClientName() const { return clientName; }
      string GetClientAddress() const { return clientAddress; }
     

   private:
      string clientName = "NoName";
      string clientAddress = "No Address";
      
};


void clientlist() {
  
   cout << "Opening file clientlist.txt." << endl;
   inFS.open("clientlist.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file clientlist.txt." << endl;
      return;
   }

  
   cout << "Reading and printing client list." << endl;

   inFS >> fileRowData;
   while (!inFS.fail()) {

      for(int x = 0; x < 4; x++){
         switch(x){
            case 0:
            cout << "client ID: " << fileRowData << endl;
            break;
            case 1:
            cout << "client Name: " << fileRowData << endl;
            break;
            case 2:
            cout << "client Address: " << fileRowData << endl;
            break;
            case 3:
            cout << "client sales: " << fileRowData << endl << endl;
            break;
         }
      inFS >> fileRowData;

      }
      
      
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file clientlist.txt." << endl;

  
   inFS.close();
}

   
   cout << "Reading and printing specific client." << endl;
   inFS >> fileRowData;
   while (!inFS.fail()) {
      if(fileRowData == receivedClientId){
         matchId = true;
         for(int x = 0; x < 4; x++){
            switch(x){
               case 0:
               cout << "client ID: " << fileRowData << endl;
               break;
               case 1:
               cout << "client Name: " << fileRowData << endl;
               break;
               case 2:
               cout << " client address: " << fileRowData << endl;
               break;
               case 3:
               cout << "client sales: " << fileRowData << endl << endl;
               break;
            }
         inFS >> fileRowData;
         }
    
   }

   cout << "Closing file clientlist.txt." << endl;
   if (matchId == false){
    cout << "ID not found. " << endl;  
   }
   
   inFS.close();
}
void newClient() {

string completeString = "";
cout << "Opening file clientlist.txt." << endl;
   inFS.open("clientlist.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file clientlist.txt." << endl;
      return;
   }
 
   inFS >> fileRowData;
   while (!inFS.fail()) {
         completeString = completeString + fileRowData + "\n";
         inFS >> fileRowData;    
   }
   if (!inFS.eof()) {
      cout << "Input failure before reaching end of file." << endl;
   }

   cout << "Closing file clientlist.txt." << endl;
  
   inFS.close();

string userInput = "";
ofstream outFS;
outFS.open("clientlist.txt");
if (!outFS.is_open()) {
   cout << "Could not open file clientlist.txt." << endl;
   return;
}

cout << "Enter client ID:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";

cout << "Enter client Name:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";

cout << "Enter client Address:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";

cout << "Enter Sales To Date:" << endl;
cin >> userInput;
completeString = completeString + userInput + "\n";

outFS << completeString;


outFS.close();

clientList();

}
void updateClientInfo(string receivedClientId){

string completeString = "";
string userInput = "";
cout << "Opening file clientlist.txt." << endl;
   inFS.open("clientlist.txt");

   if (!inFS.is_open()) {
      cout << "Could not open file clientlist.txt." << endl;
      return;
   }
   // Compile everytihg into one variable
   inFS >> fileRowData;
   while (!inFS.fail()) {
      if (fileRowData == receivedClientId) {
         
         cout << "Enter Client ID:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         
         cout << "Enter Client Name:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         
         cout << "Enter Client Address:" << endl;
         cin >> userInput;
         completeString = completeString + userInput + "\n";
         
         cout << "Enter Client Sales To Date:" << endl;
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

   cout << "Closing file clientlist.txt." << endl;
  
   inFS.close();

   ofstream outFS;
   outFS.open("clientlist.txt");
   if (!outFS.is_open()) {
      cout << "Could not open file clientlist.txt." << endl;
      return;
   }

outFS << completeString;


outFS.close();

clientList();

}

}      
}


    return 0;
}
