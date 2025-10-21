#include <iostream>
#include <string>
using namespace std;


class Product {
public:

    string name;

    double price;

    string description;

    bool available;

 

    Product(string n, double p, string d, bool a) {

        name = n;
        price = p;
        description = d;
        available = a;

    }

 
    void display() {
        cout << name << " - $" << price << endl;

    }

};
