#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

using namespace std;

class Product {
    public:
        Product();
        Product(string name, double price, int sales);
        void AddProduct(string name, double price, int sales);
        void RemoveProduct(string name);
        void UpdateProduct(string name, double price, int sales);
        void PrintProduct(string name);
        void PrintAllProducts();
    private:
        string productName;
        vector<string> nameList;
        double productPrice;
        vector<double> priceList;
        int productSales;
        vector<int> salesList;
};
#endif
