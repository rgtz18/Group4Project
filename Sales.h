#pragma once
#include <string>
using namespace std;

class Sales
{
	public:
		Sales(int saleID = 0, string enterDate = "None", int enterClientID = 0, int enterProductID = 0, double enterProductSales = 0.00, int enterSalesRep = 0);
		void SetSaleID(int enterSaleID);
		int GetSaleID();
		void SetDate(string enterDate);
		string GetDate();
		void SetClientID(int enterClientID);
		int GetClientID();
		void SetProductID(int enterProductID);
		int GetProductID();
		void SetProductSales(double enterProductSales);
		double GetProductSales();
		void SetSalesRepID(int enterSalesRepID);
		int GetSalesRepID();
		
	private:
		int saleID;
		string date;
		int clientID;
		int productID;
		double productSales;
		int salesRepID;
};