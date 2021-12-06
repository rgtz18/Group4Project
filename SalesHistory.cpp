#include "SalesHistory.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

//constructor, gets info from file and stores it in a vector
SalesHistory::SalesHistory() {
	ifstream inFS;

	//gets input from file
	inFS.open("SalesHistory.txt");
	//prints error if SalesHistory file couldn't be opened
	if (!inFS.is_open()) {
		cout << "Could not open file SalesHistory.txt." << endl;
		return;
	}

	//makes lines of text from file into Sales objects then puts them into list of all sales
	while (!inFS.eof() && inFS.good()) {
		int saleID;
		string date;
		int clientID;
		int productID;
		double productSales;
		int salesRepID;

		inFS >> saleID >> date >> clientID >> productID >> productSales >> salesRepID;

		Sales currentSale(saleID, date, clientID, productID, productSales, salesRepID);
		allSales.push_back(currentSale);
	}
	inFS.close();
}

//Shows menu of options user can select from
void SalesHistory::SalesHistoryMenu() {
	string userSelect = "";

	//loop for user input until they enter the letter 'q'
	while (userSelect != "q") {
		cout << endl;
		cout << "Sales Menu" << endl;
		cout << "1) " << "Purchase Product" << endl;
		cout << "2) " << "List of All Sales" << endl;
		cout << "3) " << "List of All Sales From Specific Client" << endl;
		cout << "4) " << "Update Specific Sale Information" << endl;
		cout << "q) " << "Quit Sales Menu" << endl << endl;
		cout << "Choose an option: " << endl;

		getline(cin, userSelect);
		cout << endl;

		//options must be numbers 1-4 or q, calls function respective to option stated
		if (userSelect == "1") {
			PurchaseProduct();
		}
		else if (userSelect == "2") {
			PrintAllSalesHistory();
		}
		else if (userSelect == "3") {
			PrintClientSalesHistory();
		}
		else if (userSelect == "4") {
			UpdateSales("all", "");
		}
		else if (userSelect == "q") {
			return;
		}
		else {
			cout << "Please enter one key from the list of options." << endl;
		}
	}
}

//Allows user to enter a number and checks if it is a number
string SalesHistory::enterNumber() {
	string number;
	bool isNumber = false;
	unsigned int i;

	getline(cin, number);
	//loop for asking user for input until they enter a valid number
	//loops is stopped if user entered q to stop updating/purchasing
	while (isNumber == false && number != "q") {
		//if user input is empty, they will be asked to enter again
		if (number == "") {
			isNumber = false;
		}
		else {
			isNumber = true;
			int dotCount = 0;
			//checks each letter in user input to see if it is a number
			for (i = 0; i < number.size(); ++i) {
				if (isdigit(number.at(i)) == false && number.at(i) != '.') {
					isNumber = false;
				}
				//checks number of periods in number
				if (number.at(i) == '.') {
					dotCount += 1;
				}
			}
			//if more than one period in number, number is not valid
			if (dotCount > 1) {
				isNumber = false;
			}
		}
		//if user did not enter a valid number, they will be asked again.=
		if (isNumber == false) {
			cout << "Please enter a number:" << endl;
			getline(cin, number);
		}
	}
	return number;
}

//checks if user input is a valid date
string SalesHistory::checkDate() {
	string date;
	bool isDate = false;
	unsigned int i;

	getline(cin, date);
	//loop for asking user for input until they enter a valid date
	//loops is stopped if user entered q to stop updating/purchasing
	while (isDate== false && date != "q") {
		//if user input is empty, they will be asked to enter again
		if (date == "" || date.size() != 10) {
			isDate = false;
		}
		else {
			isDate = true;
			int dashCount = 0;
			//checks each letter in user input to see if it is a number
			for (i = 0; i < date.size(); ++i) {
				if (isdigit(date.at(i)) == false && date.at(i) != '/') {
					isDate = false;
				}
				//checks number of periods in number
				if (date.at(i) == '/') {
					dashCount += 1;
				}
			}
			//if more than one period in number, number is not valid
			if (dashCount > 2 || date.at(2) != '/' || date.at(5) != '/') {
				isDate = false;
			}
		}
		//if user did not enter a valid date, they will be asked again.=
		if (isDate == false) {
			cout << "Please enter a valid date:" << endl;
			getline(cin, date);
		}
	}
	return date;
}

//Allows user to purchase a product
void SalesHistory::PurchaseProduct() {
	string enterInfo;
	Sales newSale;
	ofstream outFS;

	cout << "(Enter 'q' at any time to quit purchasing a product)" << endl;
	//Gets user entered sale info
	newSale = GetSaleInfo();
	//Stops purchasing product if user entered q at any time
	if (newSale.GetDate() == "q") {
		cout << "Stopped purchasing product." << endl;
		return;
	}
	//Sets new sale's ID to latest sale ID + 1
	newSale.SetSaleID(allSales.at(allSales.size()-1).GetSaleID()+1);
	allSales.push_back(newSale);
	
	//Writes to SalesHistory.txt file
	outFS.open("SalesHistory.txt", ios::app);
	//Error if failed to open file
	if (!outFS.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}
	else {
		//writes new sale to file
		outFS << "\n" << newSale.GetSaleID() << "\n" << newSale.GetDate() << "\n" << newSale.GetClientID() << "\n";
		outFS << newSale.GetProductID() << "\n" << newSale.GetProductSales() << "\n" << newSale.GetSalesRepID();
	}
	outFS.close();
	//Prints information of purchased product
	cout << "Product purchased successfully. Sale information below:" << endl << endl;
	PrintSaleHistoryTitles();
	PrintSaleHistory(newSale);
}

//Prints current sale from file with formatting
void SalesHistory::PrintSaleHistory(Sales currentSale) {
	cout << left << setfill(' ');
	cout << setw(11) << currentSale.GetSaleID() << "| ";
	cout << setw(11) << currentSale.GetDate() << "| ";
	cout << setw(11) << currentSale.GetClientID() << "| ";
	cout << setw(11) << currentSale.GetProductID() << "| ";
	cout << fixed << setprecision(2) << setw(16) << currentSale.GetProductSales() << "| ";
	cout << setprecision(2) << setw(11) << currentSale.GetSalesRepID() << endl;
	cout << right;
}

//Print titles of each sale information category with formatting
void SalesHistory::PrintSaleHistoryTitles() {
	cout << left << setfill(' ');
	cout << setw(11) << "SaleID" << "| ";
	cout << setw(11) << "Date" << "| ";
	cout << setw(11) << "ClientID" << "| ";
	cout << setw(11) << "ProductID" << "| ";
	cout << setw(16) << "Sales" << "| ";
	cout << setw(11) << "RepID" << endl;
	cout << setfill('-') << setw(76) << "" << endl;
	cout << right;
}

//Prints all sales from file
void SalesHistory::PrintAllSalesHistory() {
	unsigned int i;
	PrintSaleHistoryTitles();
	//loops through all sales from vector and calls function to print each sale individually
	for (i = 0; i < allSales.size(); ++i) {
		Sales currentSale = allSales.at(i);
		PrintSaleHistory(currentSale);
	}
}

//Prints all sales from a specific client
void SalesHistory::PrintClientSalesHistory() {
	string clientID;
	bool clientExists = false;
	unsigned int i;

	cout << "(Enter 'q' quit looking at clients' sales history)" << endl;
	cout << "Enter the client's ID: " << endl;
	//gets user input which must be a number or q
	clientID = enterNumber();
	//Loop for asking for user input until client ID is found or user enters q
	while (clientID != "q" && clientExists == false) {
		for (i = 0; i < allSales.size(); ++i) {
			Sales currentSale = allSales.at(i);
			//Checks if client ID exists
			if (to_string(currentSale.GetClientID()) == clientID) {
				clientExists = true;
			}
		}
		//Prints titles for each sale information category
		if (clientExists == true) {
			cout << endl;
			PrintSaleHistoryTitles();
		}
		//Prints each sale belonging to specified client
		for (i = 0; i < allSales.size(); ++i) {
			Sales currentSale = allSales.at(i);
			if (to_string(currentSale.GetClientID()) == clientID) {
				PrintSaleHistory(currentSale);
			}
		}
		//Asks user for input again if client ID does not exist
		if (clientExists == false) {
			cout << "The client does not exist." << endl;
			cout << "Enter the client's ID: " << endl;
			clientID = enterNumber();
		}
	}
}

//Gets user entered info for updating or creating a sale, if user entered q at any time then stop updating/purchasing
Sales SalesHistory::GetSaleInfo() {
	Sales quitSale(0,"q", 0, 0, 0, 0);
	string date;
	string clientID;
	string productID;
	string productSales;
	string salesRepID;

	cout << "Enter Date (mm/dd/yyyy):" << endl;
	date = checkDate();
	if (date == "q") { return quitSale; }

	cout << "Enter Client ID:" << endl;
	clientID = enterNumber();
	if (clientID == "q") { return quitSale; }

	cout << "Enter Product ID:" << endl;
	productID = enterNumber();
	if (productID == "q") { return quitSale; }

	cout << "Enter Product Sales:" << endl;
	productSales = enterNumber();
	if (productSales == "q") { return quitSale; }

	cout << "Enter Sales Representative ID:" << endl;
	salesRepID = enterNumber();
	if (salesRepID == "q") { return quitSale; }

	Sales currentSale(0, date, stoi(clientID), stoi(productID), stod(productSales), stoi(salesRepID));

	return currentSale;
}

//Updates one sale's history
void SalesHistory::UpdateSales(string option, string updateInfo)
{
	if (option == "all") {
		string saleID;
		bool saleExists = false;
		unsigned int i;

		cout << "(Enter 'q' at any time to quit updating a sale)" << endl;
		cout << "Enter the sale's ID: " << endl;
		getline(cin, saleID);
		//Loops for asking user for sale ID until the ID is found or the user enters q
		while (saleID != "q" && saleExists == false) {
			//loops through all sales in vector
			for (i = 0; i < allSales.size(); ++i) {
				Sales currentSale = allSales.at(i);
				int currentSaleID = currentSale.GetSaleID();
				//Checks to see if the sale ID exists
				if (to_string(currentSaleID) == saleID) {
					ofstream outFS;
					unsigned int j;

					saleExists = true;
					currentSale = GetSaleInfo();
					//stops updating the sale if user entered q at any point in updating sale
					if (currentSale.GetDate() == "q") {
						cout << "Stopped updating sale." << endl;
						break;
					}
					currentSale.SetSaleID(currentSaleID);

					//Writes to SalesHistory.txt file
					outFS.open("SalesHistory.txt");
					if (!outFS.is_open()) {
						cout << "Failed to open file." << endl;
						return;
					}
					else {
						//writes each info from each sale per line
						for (j = 0; j < allSales.size(); ++j) {
							if (j == 0) {
								outFS << allSales.at(j).GetSaleID();
							}
							else {
								outFS << "\n" << allSales.at(j).GetSaleID();
							}
							outFS << "\n" << allSales.at(j).GetDate() << "\n" << allSales.at(j).GetClientID() << "\n";
							outFS << allSales.at(j).GetProductID() << "\n" << allSales.at(j).GetProductSales() << "\n" << allSales.at(j).GetSalesRepID();
						}
					}
					outFS.close();
					//Prints old to new update information
					cout << "Updated sale successfully. Update information below from old to new." << endl << endl;
					PrintSaleHistoryTitles();
					PrintSaleHistory(allSales.at(i));
					PrintSaleHistory(currentSale);
					//updates sale in sale history from entered info
					allSales.at(i) = currentSale;
				}
			}
			//Asks for user input again if sale ID is not found
			if (saleExists == false) {
				cout << "The sale does not exist." << endl;
				cout << "Enter the sale's ID: " << endl;
				getline(cin, saleID);
			}
		}
	}
	else {
		//prints if user entered letter q to stop updating
		cout << "Stopped updating sale." << endl;
	}
}