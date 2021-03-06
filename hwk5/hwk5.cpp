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
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function declarations
float random_price(double low, double high); // I chose to keep this outside of the class
void  Delay (int  milliseconds,  std::string delay_msg,  char  delay_symbol);

class Vehicle {
    private:  
        string make_model;
        int year_built;
        double price;

    public:
        Vehicle ();
        Vehicle (string m_make_model, int m_year_built, double m_price);
        ~Vehicle (); // default destructor

        // accessors
        string get_make_model( ) const;
        int get_year( ) const;
        double get_price( ) const;
        // int get_vehicle_count() const;
        // mutators
        void set_make_model(string m_make_model);
        void set_year(int m_year_built);
        void set_price(double m_price);
};

// Accessors
string Vehicle::get_make_model( ) const {return make_model;}
int Vehicle::get_year( ) const {return year_built;}
double Vehicle::get_price( ) const {return price;}

// Mutators
void Vehicle::set_make_model(string m_make_model) {make_model = m_make_model;}
void Vehicle::set_year(int m_year_built) {year_built = m_year_built;}
void Vehicle::set_price(double m_price) {price = m_price;}

// Constructors and destructor
Vehicle::Vehicle(string m_make_model, int m_year_built, double m_price): 
                    make_model(m_make_model), 
                    year_built(m_year_built), 
                    price(m_price) { }

Vehicle::Vehicle(): make_model("No make no model"),
                    year_built(1900),
                    price(100.0) { }

Vehicle::~Vehicle() { }
    //cout << "Vehicle object is destroyed ..." << endl;
    // had to remove this otherwise I got 1024 lines out

class InventorySystem {
    private:
        string dealer_name = DEFAULT_DEALER_NAME;
        string dealer_location = DEFAULT_LOCATION;

        // Member functions
        void Menu();
        int GetUserChoice();
        void ShowVehicleInventory();
        void Quit();
        void HandleInvalidInput(int selection);
        void SearchByMakeModel();

    public:
        static const int MAX_INVENTORY = 1024;
        static const int INIT_INVENTORY = 16;
        static int VEHICLE_COUNT; // to keep track of vehicles in inventory, defined outside
        const string DEFAULT_DEALER_NAME = "Any dealer";
        const string DEFAULT_LOCATION = "The lost city";
        const int DEFAULT_VEHICLE_COUNT = 0;

        // Constructor destructor
        InventorySystem();
        InventorySystem(string m_dealer_name, string m_dealer_location);
        ~InventorySystem();

        // Accessors and mutators
        string get_dealer_name() const;
        string get_dealer_location() const;
        void set_dealer_name(string m_dealer_name);
        void set_dealer_location(string m_dealer_location);
        void AddVehicle();

        // Public member functions
        void BuildInventory();
        void Run();
        int get_vehicle_count();
    
    private:
        // had to put this below the public declaration of MAX_INVENTORY for it to work
        // not sure why ordeer maters
        Vehicle vehicle_inventory[MAX_INVENTORY];
};

// Variable for tracking count of non default vehicles instantiated
// through AddVehicle feature
int InventorySystem::VEHICLE_COUNT = INIT_INVENTORY;

InventorySystem::InventorySystem(): 
    dealer_name("Default Dealer"), 
    dealer_location("Default Location") { }

InventorySystem::InventorySystem(string m_dealer_name, string m_dealer_location):
    dealer_name(m_dealer_name), dealer_location(m_dealer_location) { }

InventorySystem::~InventorySystem() {
    cout << "Inventory system for dealer " << dealer_name << "@"
         << dealer_location << " is destroyed" << endl; 
}

// Accessors and mutators definitions
string InventorySystem::get_dealer_name() const {return dealer_name;}
string InventorySystem::get_dealer_location() const {return dealer_location;}
void  InventorySystem::set_dealer_name(string m_dealer_name) {
    dealer_name = m_dealer_name;
    }
void InventorySystem::set_dealer_location(string m_dealer_location) {
    dealer_location = m_dealer_location;
    }
int InventorySystem::get_vehicle_count() {return InventorySystem::VEHICLE_COUNT;}

// Helper functions
void InventorySystem::Menu() {
    cout << "****************************\n";
    cout << "     SMART CAR INQUIRY\n";
    cout << "****************************\n";
    cout << " 1. View Vehicle Inventory\n";
    cout << " 2. Search by Make and Model\n";
    cout << " 3. Add Vehicle\n";
    cout << " 4. Quit\n\n";
}

int InventorySystem::GetUserChoice() {
    int selection;
    cout << "Please choose an option from the menu (1-4): ";
    cin >> selection;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << endl;
        return 0;
    }
    else{
        return selection;
    }
}

void InventorySystem::HandleInvalidInput(int selection) {
    cout << selection << " is an invalid input, please try again\n\n\n";
}

void InventorySystem::Quit() {
    cout << "Thanks, exiting the program ...\n\n";
    exit;
}

void InventorySystem::BuildInventory() {
    int rand_number = 0;
    srand(static_cast<unsigned int> (time (0))); //seed for rand

    for (int i=0; i<InventorySystem::INIT_INVENTORY; i++)
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

void InventorySystem::AddVehicle() {
    string make_model;
    int year;
    double price;

    if (VEHICLE_COUNT < InventorySystem::MAX_INVENTORY){
        cout << "Enter vehicle make model: ";
        if (cin.peek() == '\n') {cin.ignore();}
        getline(cin, make_model);
        cout << "Enter vehicle year: ";
        cin >> year;
        cout << "Enter vehicle price: ";
        cin >> price;
        cout << endl;

        vehicle_inventory[VEHICLE_COUNT].set_make_model(make_model);
        vehicle_inventory[VEHICLE_COUNT].set_price(price);
        vehicle_inventory[VEHICLE_COUNT].set_year(year);
        VEHICLE_COUNT ++;
    }
    else
    {
        cout << "Inventory full, cannot add new vehicles.\n\n";
    }
    
}

void InventorySystem::ShowVehicleInventory() {
    cout << endl;
    cout << "      ****************************\n";
    cout << "           VEHICLE INVENTORY\n";
    cout << "      ****************************\n";

    for (int i=0; i<InventorySystem::VEHICLE_COUNT; i++){ 
        cout << setw(20) << right << 
        vehicle_inventory[i].get_make_model()
        << "   " <<
        vehicle_inventory[i].get_year() 
        << "   " << '$' <<
        setw(10) << fixed << setprecision(2) << right << 
        vehicle_inventory[i].get_price() 
        << endl;
    }
    cout << "\nThere are " << InventorySystem::get_vehicle_count() 
         << " vehicles in inventory." << "\n\n"; 
}

void InventorySystem::SearchByMakeModel() {
    string make_model;
    int count = 0;
        
    cout << "Enter name and model: ";
    cin.ignore();
    getline(cin, make_model);
    cout << make_model << " Inventory >>>" << endl;

    for (int i=0; i<InventorySystem::VEHICLE_COUNT; i++) {  
        if (make_model == vehicle_inventory[i].get_make_model()) { // could built this into a ftn, used twice
            cout << setw(20) << right << 
            vehicle_inventory[i].get_make_model()
            << "   " <<
            vehicle_inventory[i].get_year() 
            << "   " << '$' <<
            setw(10) << fixed << setprecision(2) << right << 
            vehicle_inventory[i].get_price() 
            << endl;
            count ++;
        }
    }
    if (count == 0) {
        cout << "Your car is not in inventory\n";
    }
    cout << endl;
}

float random_price(double low, double high)
{
    return (low + static_cast<float> (rand()) / 
        static_cast<float> (RAND_MAX / (high)));
}

void InventorySystem::Run() {
    cout << "*** Welcome to " << endl
         << get_dealer_name() << endl
         << get_dealer_location() << endl
         << "Dealership ***\n\n";
    Delay (3000, "Loading inventory, please wait ", '.'); //dummy delay
    cout << endl << endl;

    int selection = 1;
    do
    {
        Menu();
        selection = GetUserChoice();
        switch (selection){
            case 1:
                ShowVehicleInventory();
                break;
            case 2:
                SearchByMakeModel();
                break;
            case 3:
                AddVehicle();
                break;
            case 4:
                Quit();
                break;
            default: // Handles the '0' return
                HandleInvalidInput(selection);
                break;
        }
    }
    while (selection != 4);
}

////
int main() {
    InventorySystem dealer1("Carlsen Subaru", "Redwood City");
    dealer1.BuildInventory();
    dealer1.Run();
}
////

/// Functions I borrowed
void  Delay (int  milliseconds,  std::string delay_msg,  char  delay_symbol) {
    const int millisecond_cycles = 600;
    std::cout  << delay_msg << std::flush ;

    for (int ms =0 ; ms < milliseconds;  ++ms) {
        for (int cycle=0;  cycle <= millisecond_cycles * 1000; ++cycle) {
            if (ms%1000==0 && cycle== millisecond_cycles) { // print a symbol every second
                std::cout << delay_symbol << std::flush;
            }
        }                        
    }
}