#pragma once
#include <string>
using namespace std;

class Clientlist
{
	public:
	
		void SetClientName(string revClientName);
		void SetClientAddress(string revClientAddress);
		void clientlist();
		string GetClientName();
		string GetClientAddress();
		void newClient();
		void monthlySalesList;
		
	private:
		int clientID;
		string clientName;
		string clientAddress;
		double productSales;
	
};
