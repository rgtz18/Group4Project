#include <iostream>
using namespace std;

#include "Product.h"

//default constructor for the Product Class
Product::Product() {
    productName = "none";
    productPrice = 0;
    productSales = 0;
}

void Product::SetProductName(string name) {
    productName = name;
}

void Product::SetProductPrice(double price) {
    productPrice = price;
}

void Product::SetProductSales(double sales) {
    productSales = sales;
}

string Product::GetProductName() {
    return productName;
}

double Product::GetProductPrice() {
    return productPrice;
}

double Product::GetProductSales() {
    return productSales;
}

//Adds a product to the product list
void Product::AddProduct(string name, double price, double sales) {
    nameList.push_back(productName);
    priceList.push_back(productPrice);
    salesList.push_back(productSales);
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
void Product::UpdateProduct(string name, double price, double sales) {
    unsigned int i;
    for (i = 0; i < nameList.size(); ++i) {
        if (name == nameList.at(i)) {
            priceList.at(i) = productPrice;
            salesList.at(i) = productSales;
            break;
        }
    }
}

//Saves the product list to a file
void Product::SaveProduct() {
    //**FIX ME**
}

//Prints the information for a specific product in the product list
void Product::PrintProduct(string name) {
    unsigned int i;
    for (i = 0; i < nameList.at(i); ++i) {
        if (name == nameList.at(i)) {
            cout << "Product: " << nameList.at(i) << endl;
            cout << "Price: " << priceList.at(i) << endl;
            cout << "Sales: " << salesList.at(i) << endl;
        }
    }
}

//Prints the information of all products in the product list
void Product::PrintAllProducts() {
    unsigned int i;
    for (i = 0; i < nameList.at(i); ++i) {
        cout << "Product " << i << " : " << nameList.at(i) << endl;
        cout << "Price: " << priceList.at(i) << endl;
        cout << "Sales: " << salesList.at(i) << endl << endl;
    }
}

//Prints the monthly sales report
void Product::PrintMonthlySales() {
    //**FIX ME**
}
