#include <iostream>
#include <iomanip>
using namespace std;

#include "Product.h"

//default constructor for the Product Class
Product::Product() {
    productName = "none";
    productPrice = 0;
    productSales = 0;
}

//Adds a product to the product list
void Product::AddProduct(string name, double price, int sales) {
    nameList.push_back(name);
    priceList.push_back(price);
    salesList.push_back(sales);
}

//Removes a product from the product list
void Product::RemoveProduct(string name) {
    unsigned int i;
    for (i = 0; i < nameList.size(); ++i) {
        if (name == nameList.at(i)) {
            nameList.erase(nameList.begin()+i);
            priceList.erase(priceList.begin()+i);
            salesList.erase(salesList.begin()+i);
            break;
        }
    }
}

//Updates a product in the product list
void Product::UpdateProduct(string name, double price, int sales) {
    unsigned int i;
    for (i = 0; i < nameList.size(); ++i) {
        if (name == nameList.at(i)) {
            priceList.at(i) = price;
            salesList.at(i) = sales;
            break;
        }
    }
}

//Prints the information for a specific product in the product list
void Product::PrintProduct(string name) {
    unsigned int i;
    for (i = 0; i < nameList.size(); ++i) {
        if (name == nameList.at(i)) {
            cout << fixed << setprecision(2);
            cout << "Product: " << nameList.at(i) << endl;
            cout << "Price: $" << priceList.at(i) << endl;
            cout << "Sold " << salesList.at(i) << " for $" << salesList.at(i) * priceList.at(i) << endl;
        }
    }
}

//Prints the information of all products in the product list
void Product::PrintAllProducts() {
    unsigned int i;
    for (i = 0; i < nameList.size(); ++i) {
        cout << "Product " << i+1 << ": " << nameList.at(i) << endl;
        cout << "Price: $" << priceList.at(i) << endl;
        cout << "Sold " << salesList.at(i) << " for $" << salesList.at(i) * priceList.at(i) << endl << endl;
    }
}
