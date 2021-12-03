#include "SalesHistory.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

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
	string selectedID = "";

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

		//options must be numbers 1-4 or q
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
		}
		else {
			cout << "Please enter one key from the list of options." << endl;
		}
	}
}

//Allows user to enter a number and checks if it is a number
string enterNumber() {
	string number;
	bool isNumber = false;
	unsigned int i;

	getline(cin, number);
	while (isNumber == false) {
		if (number == "") {
			isNumber = false;
		}
		else {
			isNumber = true;
			for (i = 0; i < number.size(); ++i) {
				if (isdigit(number.at(i)) == false && number.at(i) != '.') {
					isNumber = false;
				}
			}
		}
		if (isNumber == false) {
			cout << "Please enter a number:" << endl;
			getline(cin, number);
		}
	}
	return number;
}

//Allows user to purchase a product
void SalesHistory::PurchaseProduct() {
	string enterInfo;
	Sales newSale;
	ofstream outFS;

	//Gets user entered sale info
	newSale = GetSaleInfo();
	//Sets new sale's ID to latest sale ID + 1
	newSale.SetSaleID(allSales.at(allSales.size()-1).GetSaleID()+1);
	allSales.push_back(newSale);
	
	//Writes to SalesHistory.txt file
	outFS.open("SalesHistory.txt", ios::app);
	if (!outFS.is_open()) {
		cout << "Failed to open file." << endl;
		return;
	}
	else {
		outFS << "\n" << newSale.GetSaleID() << "\n" << newSale.GetDate() << "\n" << newSale.GetClientID() << "\n";
		outFS << newSale.GetProductID() << "\n" << newSale.GetProductSales() << "\n" << newSale.GetSalesRepID();
	}
	outFS.close();
	cout << "Product purchased." << endl;
}

//Prints current sale from file
void SalesHistory::PrintSaleHistory(Sales currentSale) {
	cout << left << setfill(' ');
	cout << setw(11) << currentSale.GetSaleID() << "| ";
	cout << setw(11) << currentSale.GetDate() << "| ";
	cout << setw(11) << currentSale.GetClientID() << "| ";
	cout << setw(11) << currentSale.GetProductID() << "| ";
	cout << setprecision(4) << setw(11) << currentSale.GetProductSales() << "| ";
	cout << setprecision(2) << setw(11) << currentSale.GetSalesRepID() << endl;
	cout << right;
}

//Print titles of each sale information category
void SalesHistory::PrintSaleHistoryTitles() {
	cout << left << setfill(' ');
	cout << setw(11) << "SaleID" << "| ";
	cout << setw(11) << "Date" << "| ";
	cout << setw(11) << "ClientID" << "| ";
	cout << setw(11) << "ProductID" << "| ";
	cout << setw(11) << "Sales" << "| ";
	cout << setw(11) << "RepID" << endl;
	cout << setfill('-') << setw(76) << "" << endl;
	cout << right;
}

//Prints all sales from file
void SalesHistory::PrintAllSalesHistory() {
	unsigned int i;
	PrintSaleHistoryTitles();
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

	cout << "Enter the client's ID: " << endl;
	getline(cin, clientID);
	cout << endl;
	if (clientID != "q") {
		for (i = 0; i < allSales.size(); ++i) {
			Sales currentSale = allSales.at(i);
			//Checks if client ID exists
			if (to_string(currentSale.GetClientID()) == clientID) {
				clientExists = true;
			}
		}
		//Prints titles for each sale information category
		if (clientExists == true) {
			PrintSaleHistoryTitles();
		}
		//Prints each sale belonging to specified client
		for (i = 0; i < allSales.size(); ++i) {
			Sales currentSale = allSales.at(i);
			if (to_string(currentSale.GetClientID()) == clientID) {
				PrintSaleHistory(currentSale);
			}
		}
		if (clientExists == false) {
			cout << "The client does not exist." << endl;
		}
	}
}

//Gets user entered info for updating or creating a sale
Sales SalesHistory::GetSaleInfo() {
	Sales currentSale;
	string enterInfo;

	cout << "Enter Date (mm/dd/yyyy):" << endl;
	getline(cin, enterInfo);
	while (enterInfo == "") {
		cout << "Please enter a date:" << endl;
		getline(cin, enterInfo);
	}
	currentSale.SetDate(enterInfo);

	cout << "Enter Client ID:" << endl;
	enterInfo = enterNumber();
	currentSale.SetClientID(stoi(enterInfo));

	cout << "Enter Product ID:" << endl;
	enterInfo = enterNumber();
	currentSale.SetProductID(stoi(enterInfo));

	cout << "Enter Product Sales:" << endl;
	enterInfo = enterNumber();
	currentSale.SetProductSales(stod(enterInfo));

	cout << "Enter Sales Representative ID:" << endl;
	enterInfo = enterNumber();
	currentSale.SetSalesRepID(stoi(enterInfo));

	return currentSale;
}

//Updates one sale's history
void SalesHistory::UpdateSales(string option, string updateInfo)
{
	if (option == "all") {
		string saleID;
		bool saleExists = false;
		unsigned int i;

		cout << "Enter the sale's ID: " << endl;
		getline(cin, saleID);
		if (saleID != "q") {
			for (i = 0; i < allSales.size(); ++i) {
				Sales currentSale = allSales.at(i);
				int currentSaleID = currentSale.GetSaleID();
				//Checks to see if the sale ID exists
				if (to_string(currentSaleID) == saleID) {
					ofstream outFS;
					unsigned int j;

					saleExists = true;
					currentSale = GetSaleInfo();
					currentSale.SetSaleID(currentSaleID);
					//updates sale in sale history after getting entered info
					allSales.at(i) = currentSale;

					//Writes to SalesHistory.txt file
					outFS.open("SalesHistory.txt");
					if (!outFS.is_open()) {
						cout << "Failed to open file." << endl;
						return;
					}
					else {
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
					cout << "Updated Sale." << endl;
				}
			}
			if (saleExists == false) {
				cout << "The sale does not exist." << endl;
			}
		}
	}
}