/* ======================================================
File Name   : hwk5.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk5, a car dealer inventory system
              using OOP principles
Rev History : Initial
Date        : 11/xx/2020
Version     : 1.0
Comments    : 
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


class Vehicle {
    private:  
        string make_model;
        int year_built;
        double price;

    public:
        // const string DEFAULT_MAKE_MODEL = {"No make no model"};
        // const int DEFAULT_YEAR_BUILT = {1900};
        // const double DEFAULT_PRICE = {100.0};
        
        Vehicle ();
        Vehicle (string m_make_model, int m_year_built, double m_price);  // non-default constructor
        ~Vehicle (); // default destructor

        // accessors
        string get_make_model ( ) const;
        int get_year ( ) const;
        double get_price ( ) const;
        // mutators
        void set_make_model (string m_make_model);
        void set_year (int m_year_built);
        void set_price (double m_price);
};


// Accessors
string Vehicle::get_make_model ( ) const {return make_model;}
int Vehicle::get_year ( ) const {return year_built;}
double Vehicle::get_price ( ) const {return price;}
// Mutators
void Vehicle::set_make_model (string m_make_model) {make_model = m_make_model;}
void Vehicle::set_year (int m_year_built) {year_built = m_year_built;}
void Vehicle::set_price (double m_price) {price = m_price;}

// Constructors and destructor
Vehicle::Vehicle (string m_make_model, int m_year_built, double m_price): 
                    make_model(m_make_model), 
                    year_built(m_year_built), 
                    price(m_price) { }

Vehicle::Vehicle(): make_model("No make no model"),
                    year_built(1900),
                    price(100.0) { }

Vehicle::~Vehicle () {
    cout << "Vehicle object is destroyed ..." << endl;
}

int main() {
    Vehicle car1("Mini", 2018, 18000.00);
    //car1.set_make_model("Mini");
    cout << "car = " << car1.get_make_model() << endl;
    cout << "year = " << car1.get_year() << endl;
    cout << "price = " << car1.get_price() << endl;

    Vehicle car2;
    cout << "car = " << car2.get_make_model() << endl;
    cout << "year = " << car2.get_year() << endl;
    cout << "price = " << car2.get_price() << endl;
}
