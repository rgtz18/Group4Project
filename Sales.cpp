#include "Sales.h"
#include <string>
using namespace std;

//constructor for sales object
Sales::Sales(int enterSaleID, string enterDate, int enterClientID, int enterProductID, double enterProductSales, int enterSalesRepID)
{
	saleID = enterSaleID;
	date = enterDate;
	clientID = enterClientID;
	productID = enterProductID;
	productSales = enterProductSales;
	salesRepID = enterSalesRepID;
}

//Sets user input as sale ID
void Sales::SetSaleID(int enterID)
{
	saleID = enterID;
}

//Gets sale ID from sale
int Sales::GetSaleID()
{
	return saleID;
}

//Sets user input as sale date
void Sales::SetDate(string enterDate)
{
	date = enterDate;
}

//Gets sale date
string Sales::GetDate()
{
	return date;
}

//Sets user input as client ID
void Sales::SetClientID(int enterClientID)
{
	clientID = enterClientID;
}

//Gets client ID
int Sales::GetClientID()
{
	return clientID;
}

//Sets user input as product ID
void Sales::SetProductID(int enterProductID)
{
	productID = enterProductID;
}

//Gets product ID
int Sales::GetProductID()
{
	return productID;
}

//Sets user input as product sales
void Sales::SetProductSales(double enterProductSales)
{
	productSales = enterProductSales;
}

//Gets product sales
double Sales::GetProductSales()
{
	return productSales;
}

//Sets user input as sales representative ID
void Sales::SetSalesRepID(int enterSalesRepID)
{
	salesRepID = enterSalesRepID;
}

//Gets sales representative's ID
int Sales::GetSalesRepID()
{
	return salesRepID;
}