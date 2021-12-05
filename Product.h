#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

class Product {
    public:
        Product();
        Product(name, price, sales);
        void SetProductName(string name);
        void SetProductPrice(double price);
        void SetProductSales(double sales);
        string GetProductName();
        double GetProductPrice();
        double GetProductSales();
        void AddProduct(string name, double price, double sales);
        void RemoveProduct(string name);
        void UpdateProduct(string name, double price, double sales);
        void SaveProduct();
        void PrintProduct(string name);
        void PrintAllProducts();
        void PrintMonthlySales();
    private:
        string productName;
        vector<string> nameList;
        double productPrice;
        vector<double> priceList;
        double productSales;
        vector<double> salesList;
};
#endif
