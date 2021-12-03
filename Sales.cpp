#include "Sales.h"
#include <string>
using namespace std;

Sales::Sales(int enterSaleID, string enterDate, int enterClientID, int enterProductID, double enterProductSales, int enterSalesRepID)
{
	saleID = enterSaleID;
	date = enterDate;
	clientID = enterClientID;
	productID = enterProductID;
	productSales = enterProductSales;
	salesRepID = enterSalesRepID;
}

void Sales::SetSaleID(int enterID)
{
	saleID = enterID;
}
int Sales::GetSaleID()
{
	return saleID;
}

void Sales::SetDate(string enterDate)
{
	date = enterDate;
}

string Sales::GetDate()
{
	return date;
}

void Sales::SetClientID(int enterClientID)
{
	clientID = enterClientID;
}

int Sales::GetClientID()
{
	return clientID;
}

void Sales::SetProductID(int enterProductID)
{
	productID = enterProductID;
}

int Sales::GetProductID()
{
	return productID;
}

void Sales::SetProductSales(double enterProductSales)
{
	productSales = enterProductSales;
}

double Sales::GetProductSales()
{
	return productSales;
}

void Sales::SetSalesRepID(int enterSalesRepID)
{
	salesRepID = enterSalesRepID;
}

int Sales::GetSalesRepID()
{
	return salesRepID;
}