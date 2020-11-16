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
void  Delay (int  milliseconds,  std::string delay_msg,  char  delay_symbol);

// Class declarations
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
//    cout << "Vehicle object is destroyed ..." << endl;
}

class InventorySystem
{
    private:
        string dealer_name = DEFAULT_DEALER_NAME;
        string dealer_location = DEFAULT_LOCATION;
        int vehicle_count = 0;

        // Member functions
        void Menu();
        int GetUserChoice();
        void ShowVehicleInventory();
        void Quit();
        void HandleInvalidInput(); // need to fix return
        void SearchByMakeModel();

    public:
        static const int MAX_INVENTORY = 1024;
        const string DEFAULT_DEALER_NAME = {"Any dealer"};
        const string DEFAULT_LOCATION = {"The lost city"};
        const int DEFAULT_VEHICLE_COUNT = {0};

        // Constructor destructor
        InventorySystem(); // need not defayult sconstructor !!!
        ~InventorySystem();

        // Accessors and mutators definitions
        string get_dealer_name() const;
        string get_dealer_location() const;
        void set_dealer_name(string m_dealer_name);
        void set_dealer_location(string m_dealer_location);

        // Public member functions
        void BuildInventory();
        void Run();
    
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
string InventorySystem::get_dealer_name() const {return dealer_name;}
string InventorySystem::get_dealer_location() const {return dealer_location;}
void  InventorySystem::set_dealer_name(string m_dealer_name) {
    dealer_name = m_dealer_name;
    }
void InventorySystem::set_dealer_location(string m_dealer_location) {
    dealer_location = m_dealer_location;
    }

// Helper functions
void InventorySystem::Menu() {
    cout << "****************************\n";
    cout << "     SMART CAR INQUIRY\n";
    cout << "****************************\n";
    cout << " 1. View Vehicle Inventory\n";
    cout << " 2. Search by Make and Model\n";
    cout << " 3. Quit\n\n";
}

int InventorySystem::GetUserChoice() {
    int selection;
    cout << "Please choose an option from the menu (1-3): ";
    cin >> selection;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << endl;
        return 0;
    }
    // need to fix this with feedback from hwk3 !!!!!!!
    else if (selection < 1 || selection > 4){
        return 0;
    }
    else{
        return selection;
    }
}

void InventorySystem::HandleInvalidInput() {
    cout << "Invalid input, please try again\n\n\n";
}

void InventorySystem::Quit() {
    cout << "Thanks, exiting the program ...\n\n";
    exit;
}



void InventorySystem::BuildInventory() {
    
    int init_inventory = 16;
    int rand_number = 0;
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

void InventorySystem::ShowVehicleInventory() {

    cout << endl;
    cout << "      ****************************\n";
    cout << "           VEHICLE INVENTORY\n";
    cout << "      ****************************\n";

    for (int i=0; i<16; i++){    //need to fis the 16
        cout << setw(20) << right << 
        vehicle_inventory[i].get_make_model()
        << "   " <<
        vehicle_inventory[i].get_year() 
        << "   " << '$' <<
        setw(10) << fixed << setprecision(2) << right << 
        vehicle_inventory[i].get_price() 
        << endl;
    }
    cout << "\n\n"; 
}

void InventorySystem::SearchByMakeModel() {
    string make_model;
    int count = 0;
        
    cout << "Enter name and model: ";
    cin.ignore();
    getline(cin, make_model);
    cout << make_model << " Inventory >>>" << endl;

    for (int i=0; i<16; i++) {  // 16 hard coded !!!!!
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
                Quit();
                break;
            default: // Handles the '0' return
                HandleInvalidInput();
                break;
        }
    }
    while (selection != 3);
}

////
int main() {
    cout << " *** Welcome to Foothill Dealership ***\n\n";
    Delay (3000, "Loading inventory, please wait ", '.'); //dummy delay
    cout << endl << endl;
    InventorySystem dealer1;
    dealer1.BuildInventory();
    dealer1.Run();
}
////


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