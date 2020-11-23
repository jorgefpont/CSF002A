/* ======================================================
File Name   : hwk5.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk5, a car dealer inventory system
              using OOP principles
Rev History : Initial hwk release
Date        : 11/21/2020
Version     : 1.0
Comments    : 
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class Fruit {
    private:  
        string fruit_name;
        double weight;
        double unit_price;
        
    public:    
        static const string DEFAULT_FRUIT_NAME; // {"Fruitie"};
        static const double DEFAULT_WEIGHT; // {0.0};
        static const double DEFAULT_UNIT_PRICE; // {0.0};

    public:
        Fruit ();
        Fruit (string m_fruit_name, double m_weight, double m_unit_price);
        ~Fruit (); // default destructor
        // accessors
        string get_fruit_name( ) const;
        double get_weight( ) const;
        double get_unit_price( ) const;
        // mutators
        void set_fruit_name(string m_fruit_name);
        void set_weight(double m_weight);
        void set_unit_price(double m_unit_price);
        // Helpers
        void Display( ) const;
};

// Variables
const string Fruit::DEFAULT_FRUIT_NAME {"Fruitie"};
const double Fruit::DEFAULT_WEIGHT {0.0};
const double Fruit::DEFAULT_UNIT_PRICE {0.0};

// Constructors and destructor
Fruit::Fruit(string m_fruit_name, double m_weight, double m_unit_price): 
                    fruit_name(m_fruit_name), 
                    weight(m_weight), 
                    unit_price(m_unit_price) { }

Fruit::Fruit(): fruit_name(DEFAULT_FRUIT_NAME),
                    weight(DEFAULT_WEIGHT),
                    unit_price(DEFAULT_UNIT_PRICE) { }

Fruit::~Fruit() { } // Need to add message !!!

// Accessors
string Fruit::get_fruit_name( ) const {return fruit_name;}
double Fruit::get_weight( ) const {return weight;}
double Fruit::get_unit_price( ) const {return unit_price;}

// Mutators
void Fruit::set_fruit_name(string m_fruit_name) {fruit_name = m_fruit_name;}
void Fruit::set_weight(double m_weight) {weight = m_weight;}
void Fruit::set_unit_price(double m_unit_price) {unit_price = m_unit_price;}

// Helper functions
void Fruit::Display( ) const {
    cout << "Fruit:      " << fruit_name << endl;
    cout << fixed << setprecision (2);
    cout << "Weight:     " << weight << endl;
    cout << "Unit Price: " << "$" << unit_price << endl;

    //return fruit_name + " / " + to_string(weight) + " / "
    //+ "$" + to_string(unit_price) + " per lb\n";
}

int main() {
    Fruit afruit;
    cout << afruit.get_fruit_name() << endl;
    cout << afruit.get_unit_price() << endl;
    cout << afruit.get_weight() << endl;

    Fruit afruit1("Apple", 20.0, 10.0);
    cout << afruit1.get_fruit_name() << endl;
    cout << afruit1.get_unit_price() << endl;
    cout << afruit1.get_weight() << endl;
    //
    afruit1.Display();
}