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

// Function declarations
float random_price(double low, double high);


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
        Vehicle (string m_make_model, int m_year_built, double m_price);
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

////
int main() {
    Vehicle car1("Mini", 2018, 18000.00);
    cout << "car = " << car1.get_make_model() << endl;
    cout << "year = " << car1.get_year() << endl;
    cout << "price = " << car1.get_price() << endl;

    Vehicle car2;
    cout << "car = " << car2.get_make_model() << endl;
    cout << "year = " << car2.get_year() << endl;
    cout << "price = " << car2.get_price() << endl;
}
////

class InventorySystem
{
    private:
        string dealer_name = DEFAULT_DEALER_NAME;
        string dealer_location = DEFAULT_LOCATION;
        int vehicle_count = 0;

        // Menu

        // GetUserChoice

        // ShowVehicleInventory

        // SearchByMakeModel

        // Quit

        // HandleInvalidInput

    public:
        static const int MAX_INVENTORY = 1024;
        const string DEFAULT_DEALER_NAME = {"Any dealer"};
        const string DEFAULT_LOCATION = {"The lost city"};
        const int DEFAULT_VEHICLE_COUNT = {0};

        // Constructor destructor
        InventorySystem(/* args */);
        ~InventorySystem();

        // Accessors and mutators definitions
        string get_dealer_name() const;
        string get_dealer_location() const;
        void set_dealer_name(string m_dealer_name);
        void set_dealer_location(string m_dealer_location);

        // Public member functions
        void BuildInventory();

        // Run
    
    private:
        // had to put this bellow the plublic declaration of MAX_INVENTORY
        Vehicle vehicle_inventory[MAX_INVENTORY];

};

// // Don't understand why this cannot be defined in the declatation
// const int InventorySystem::MAX_INVENTORY = 1024;

InventorySystem::InventorySystem(/* args */) {

}

InventorySystem::~InventorySystem() {
    cout << "Inventory system for dealer " << dealer_name << "@"
         << dealer_location << " is destroyed" << endl; 
}

// Accessors and mutators definitions
string InventorySystem :: get_dealer_name() const {return dealer_name;}
string InventorySystem :: get_dealer_location() const {return dealer_location;}
void  InventorySystem :: set_dealer_name(string m_dealer_name) {
    dealer_name = m_dealer_name;
    }
void InventorySystem :: set_dealer_location(string m_dealer_location) {
    dealer_location = m_dealer_location;
    }

void InventorySystem::BuildInventory() {
    
    int init_inventory = 16;
    int rand_number = 0;

    // car data
    // vector<string> cars = {"Ford Taurus", "Toyota Camry", 
    //     "BMW 335i", "Rolls-Royce Phantom"};
    // vector<double> low = {9000.0, 12000.0, 39500.0, 50000.0};
    // vector<double> high = {27000.0, 30000.0, 53500.0, 180000.0};

    srand(static_cast<unsigned int> (time (0))); //seed for rand

    for (int i=0; i<init_inventory; i++)
    {
        rand_number = rand()%4;
        switch(rand_number)
        {
            case 0:
                vehicle_inventory[i].set_make_model("Ford Taurus");
                vehicle_inventory[i].set_price(random_price(9000.0, 27000.0));
                vehicle_inventory[i].set_year(2010 + (rand()%8));
                break;

            case 1:
                vehicle_inventory[i].set_make_model("Toyota Camry");
                vehicle_inventory[i].set_price(random_price(12000.0, 30000.0));
                vehicle_inventory[i].set_year(2010 + (rand()%8));
                break;

            case 2:
                vehicle_inventory[i].set_make_model("BMW 335i");
                vehicle_inventory[i].set_price(random_price(39050.0, 53500.0));
                vehicle_inventory[i].set_year(2010 + (rand()%8));
                break;
            case 3:
                vehicle_inventory[i].set_make_model("Rolls-Royce Phantom");
                vehicle_inventory[i].set_price(random_price(50000.0, 180000.0));
                vehicle_inventory[i].set_year(2010 + (rand()%8));
                break;
        }
    }

}

float random_price(double low, double high)
{
    return (low + static_cast<float> (rand()) / 
        static_cast<float> (RAND_MAX / (high)));
}