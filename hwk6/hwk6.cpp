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
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;

float random_num(double low, double high);

/////////////// Fruit Class

class Fruit {
    private:  
        string fruit_name;
        double weight;
        double unit_price;
        string fruit_types;
        
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
    cout << setw(10) << left << fruit_name << "  "
         << setw(8) << fixed << setprecision(2) << right
         << "$" << unit_price << "\t" << weight << endl << left;
}

/////////////// End of Fruit Class

/////////////// Online Supermarket Class

class OnlineSuperMarket {
    private:
        string market_name;
        string web_address;

        // Member functions
        string GetUserChoice();
        void Quit();

    public:
        static const int MAX_FRUITS = 8;
        static const string DEFAULT_MARKET_NAME;
        static const string DEFAULT_WEB_ADDRESS;
        static double high_price[MAX_FRUITS];
        static double low_weight;
        static double high_weight;

        // Constructor destructor
        OnlineSuperMarket();
        OnlineSuperMarket(string m_market_name, string m_web_address);
        ~OnlineSuperMarket();

        // Accessors and mutators
        string get_market_name() const;
        string get_web_address() const;
        void set_market_name(string m_market_name);
        void set_web_address(string m_web_address);

        // Public member functions
        static void Init(Fruit fruits[], int count);
        static void ShowFruits(Fruit fruits[], int count);
        static void BubbleSort (Fruit fruits[], int count);
        void Run();
    
    private:  // had to put this below the public declaration of MAX_FRUITS for it to work
        static Fruit fruit_inventory[MAX_FRUITS];
        static string fruit_types[MAX_FRUITS];
        static double low_price[MAX_FRUITS];
};

// Variables
const string OnlineSuperMarket::DEFAULT_MARKET_NAME {"No Market"};
const string OnlineSuperMarket::DEFAULT_WEB_ADDRESS {"http://www.martkey.com"};
string OnlineSuperMarket::fruit_types[MAX_FRUITS] = {"Banana", "Strawberry", "Orange", "Grapes", "Watermelon", 
    "Apple", "Blueberry", "Mango"};
double OnlineSuperMarket::low_price[MAX_FRUITS] = {0.50, 2.10, 2.00, 2.15, 0.60, 1.50, 3.00, 2.25};
double OnlineSuperMarket::high_price[MAX_FRUITS] = {0.85, 3.50, 3.50, 4.50, 1.45, 3.20, 4.50, 3.25};
double OnlineSuperMarket::low_weight = 10.0;
double OnlineSuperMarket::high_weight = 50.0;

// Constructors and destructor
OnlineSuperMarket::OnlineSuperMarket(): 
    market_name(DEFAULT_MARKET_NAME), 
    web_address(DEFAULT_WEB_ADDRESS) { }

OnlineSuperMarket::OnlineSuperMarket(string m_market_name, string m_web_address):
    market_name(m_market_name), web_address(m_web_address) { }

OnlineSuperMarket::~OnlineSuperMarket() {
    cout << "Online supermarket " << market_name << "at "
         << web_address << " is closed" << endl; 
}

// Accessors and mutators definitions
string OnlineSuperMarket::get_market_name() const {return market_name;}
string OnlineSuperMarket::get_web_address() const {return web_address;}
void  OnlineSuperMarket::set_market_name(string m_market_name) {market_name = m_market_name;}
void OnlineSuperMarket::set_web_address(string m_web_address) {web_address = m_web_address;}


void OnlineSuperMarket::Init(Fruit fruits[], int count) {
    int rand_number = 0;
    srand(static_cast<unsigned int> (time (0))); //seed for rand
    for (int i=0; i<count; i++) {
            fruits[i].set_fruit_name(fruit_types[i]);
            fruits[i].set_unit_price(random_num(low_price[i], high_price[i]));
            fruits[i].set_weight(random_num(low_weight, high_weight));
    }
}

void OnlineSuperMarket::BubbleSort (Fruit fruits[], int count) {
   bool swapped = true;
   int j = 0;

   Fruit temp_obj;

   while (swapped) {
       swapped = false;
       j++;

       for (int i = 0; i < count - j; i++) {
             if (fruits[i].get_fruit_name().compare (fruits[i + 1].get_fruit_name ()) > 0) {
                  temp_obj = fruits[i];
                  fruits[i] = fruits[i + 1];
                  fruits[i + 1] = temp_obj;
                  swapped = true;
              }
       }
    }
}

void OnlineSuperMarket::ShowFruits(Fruit fruits[], int count) {

    cout << "      *************************\n";
    cout << "           FRUIT INVENTORY\n";
    cout << "        Fruit / Price / Weight\n";
    cout << "      *************************\n";

    for (int i=0; i<count; i++){ 
        fruits[i].Fruit::Display();
    }
}

// void OnlineSuperMarket::SearchByMakeModel() {
//     string make_model;
//     int count = 0;
        
//     cout << "Enter name and model: ";
//     cin.ignore();
//     getline(cin, make_model);

//     for (int i=0; i<OnlineSuperMarket::MAX_FRUITS; i++) {  
//         if (make_model == fruit_inventory[i].get_make_model()) { // could built this into a ftn, used twice
//             cout << setw(20) << right << 
//             fruit_inventory[i].get_make_model()
//             << "   " <<
//             fruit_inventory[i].get_year() 
//             << "   " << '$' <<
//             setw(10) << fixed << setprecision(2) << right << 
//             fruit_inventory[i].get_price() 
//             << endl;
//             count ++;
//         }
//     }
// }


void OnlineSuperMarket::Run() {
    string user_input;
    string fruit_name;
    double weight;

    cout << "*** Welcome to " << endl
         << get_market_name() << endl
         << get_web_address() << endl
         << "***\n\n";

    do
    {
        cout << "\nEnter 'order' or 'XXX' to quit: ";
        getline(cin, user_input);

        if (user_input == "order" || user_input == "ORDER" || user_input == "Order") {
            cout << "Enter fruit name: ";
            getline(cin, fruit_name);
            cout << "Enter weight to purchase: ";
            cin >> weight;
            cin.ignore(); //needed to clear the '\n' in the buffer after a cin >>
            cout << endl;
            cout << "Ordering: " << fruit_name << ", " << weight;
            //Find(fruit_name, weight); //need to define 
        }
        else if (user_input == "xxx" || user_input == "XXX") {
            Quit();
        }
    }
    while (user_input != "xxx" || user_input != "XXX");
}

void OnlineSuperMarket::Quit() {
    cout << "Thanks for your visit and come again ...\n\n";
    exit(0);
}

float random_num(double low, double high) {

    return (low + static_cast<float> (rand()) / 
        static_cast<float> (RAND_MAX / (high-low)));
}

//---------------------------------------------------------------

int main() {
    Fruit afruit;
    afruit.Display();
    cout << endl;

    Fruit afruit1("Apple", 20.0, 100.0);
    afruit1.Display();
    cout << endl;

    OnlineSuperMarket sup1("Draegers", "http://www.draegers.com");
    cout << sup1.get_market_name() << endl;
    cout << sup1.get_web_address() << endl;
    cout << endl;

    // array with default fruit objects
    Fruit fruit_inventory[OnlineSuperMarket::MAX_FRUITS];
    OnlineSuperMarket::ShowFruits(fruit_inventory, OnlineSuperMarket::MAX_FRUITS);
    cout << endl;

    OnlineSuperMarket::Init(fruit_inventory, OnlineSuperMarket::MAX_FRUITS);
    OnlineSuperMarket::ShowFruits(fruit_inventory, OnlineSuperMarket::MAX_FRUITS);
    cout << endl;
    
    OnlineSuperMarket::BubbleSort(fruit_inventory, OnlineSuperMarket::MAX_FRUITS);
    OnlineSuperMarket::ShowFruits(fruit_inventory, OnlineSuperMarket::MAX_FRUITS);
    cout << endl;

    //sup1.Run();
}
