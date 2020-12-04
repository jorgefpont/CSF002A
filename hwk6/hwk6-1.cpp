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

/////////////// Online Supermarket Class

class OnlineSuperMarket {
    private:
        string market_name;
        string web_address;
        double static tax_rate;

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
        static double get_tax_rate();
        void set_market_name(string m_market_name);
        void set_web_address(string m_web_address);

        // Public member functions
        void Init();
        void ShowFruits();
        void BubbleSort ();
        void Run();
        int Find(string fruit, double weight);
        int Order(int res, double weight);
    
    private:  // had to put this below the public declaration of MAX_FRUITS for it to work
        //static Fruit fruit_inventory[MAX_FRUITS];
        Fruit fruit_inventory[MAX_FRUITS];
        static string fruit_types[MAX_FRUITS];
        static double low_price[MAX_FRUITS];
};

// Variables ---------------------------------------
const string OnlineSuperMarket::DEFAULT_MARKET_NAME {"No Market"};
const string OnlineSuperMarket::DEFAULT_WEB_ADDRESS {"http://www.martkey.com"};
string OnlineSuperMarket::fruit_types[MAX_FRUITS] = {"Banana", "Strawberry", "Orange", "Grapes", "Watermelon", 
    "Apple", "Blueberry", "Mango"};
double OnlineSuperMarket::low_price[MAX_FRUITS] = {0.50, 2.10, 2.00, 2.15, 0.60, 1.50, 3.00, 2.25};
double OnlineSuperMarket::high_price[MAX_FRUITS] = {0.85, 3.50, 3.50, 4.50, 1.45, 3.20, 4.50, 3.25};
double OnlineSuperMarket::low_weight = 10.0;
double OnlineSuperMarket::high_weight = 50.0;
double OnlineSuperMarket::tax_rate = 0.085;

// Constructors and destructor ---------------------
OnlineSuperMarket::OnlineSuperMarket(): 
    market_name(DEFAULT_MARKET_NAME), 
    web_address(DEFAULT_WEB_ADDRESS) { }

OnlineSuperMarket::OnlineSuperMarket(string m_market_name, string m_web_address):
    market_name(m_market_name), web_address(m_web_address) { }

OnlineSuperMarket::~OnlineSuperMarket() {
    cout << "Online supermarket " << market_name << "at "
         << web_address << " is closed" << endl; 
}

// Accessors and mutators definitions ---------------
string OnlineSuperMarket::get_market_name() const {return market_name;}
string OnlineSuperMarket::get_web_address() const {return web_address;}
double OnlineSuperMarket::get_tax_rate() {return tax_rate;}
void  OnlineSuperMarket::set_market_name(string m_market_name) {market_name = m_market_name;}
void OnlineSuperMarket::set_web_address(string m_web_address) {web_address = m_web_address;}


void OnlineSuperMarket::Init() {
    int rand_number = 0;
    srand(static_cast<unsigned int> (time (0))); //seed for rand
    for (int i=0; i<MAX_FRUITS; i++) {
            fruit_inventory[i].set_fruit_name(fruit_types[i]);
            fruit_inventory[i].set_unit_price(random_num(low_price[i], high_price[i]));
            fruit_inventory[i].set_weight(random_num(low_weight, high_weight));
    }
}

void OnlineSuperMarket::BubbleSort () {
   bool swapped = true;
   int j = 0;

   Fruit temp_obj;

   while (swapped) {
       swapped = false;
       j++;

       for (int i = 0; i < MAX_FRUITS - j; i++) {
             if (fruit_inventory[i].get_fruit_name().compare (fruit_inventory[i + 1].get_fruit_name ()) > 0) {
                  temp_obj = fruit_inventory[i];
                  fruit_inventory[i] = fruit_inventory[i + 1];
                  fruit_inventory[i + 1] = temp_obj;
                  swapped = true;
              }
       }
    }
}

void OnlineSuperMarket::ShowFruits() {

    cout << "      *************************\n";
    cout << "           FRUIT INVENTORY\n";
    cout << "        Fruit / Price / Weight\n";
    cout << "      *************************\n";

    for (int i=0; i<MAX_FRUITS; i++){ 
        fruit_inventory[i].Fruit::Display();
    }
}

int OnlineSuperMarket::Find(string fruit, double weight) {
    for (int i=0; i<MAX_FRUITS; i++) {  
        if (fruit == fruit_inventory[i].get_fruit_name()) { 
            return i;
        }
    }
    return -1;
}

int OnlineSuperMarket::Order(int res, double weight) {
    if(weight > fruit_inventory[res].get_weight()) {
        cout << "We do not have enough " << fruit_inventory[res].get_fruit_name() 
             << " to fulfill your order";
        return -1;
    }
    else {
        double cost = weight * fruit_inventory[res].get_unit_price() * 
            (1.0 + get_tax_rate());
        cout << "Cost for " << weight << " of " 
             << fruit_inventory[res].get_fruit_name()
             << " is $" << cost << endl; 
        return 0;
    }
}

void OnlineSuperMarket::Run() {
    string user_input;
    string fruit_name;
    double weight;

    cout << "*** Welcome to " << endl
         << get_market_name() << endl
         << get_web_address() << endl
         << "***Watermelon\n";

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
            cout << "Ordering: " << fruit_name << ", " << weight << endl;

            int res = Find(fruit_name, weight);
            if (res > -1) {
                Order(res, weight);
            } 
            else {
                cout << "Fruit not found" << endl;
            }
            
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

    OnlineSuperMarket sup1("Draegers", "http://www.draegers.com");
    cout << sup1.get_market_name() << endl;
    cout << sup1.get_web_address() << endl;
    cout << endl;
    
    sup1.ShowFruits();
    cout << endl;

    sup1.Init();
    sup1.ShowFruits();
    cout << endl;
    
    sup1.BubbleSort();
    sup1.ShowFruits();
    cout << endl;

    sup1.Run();
}
