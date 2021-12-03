#pragma once
#include "Sales.h"
#include <vector>
using namespace std;

class SalesHistory
{
	public:
		SalesHistory();
		void SalesHistoryMenu();
		void PurchaseProduct();
		void PrintSaleHistory(Sales currentSale);
		void PrintSaleHistoryTitles();
		void PrintAllSalesHistory();
		void PrintClientSalesHistory();
		void UpdateSales(string option, string updateInfo);
		Sales GetSaleInfo();
	private:
		vector<Sales> allSales;
};