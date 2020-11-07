/* ======================================================
File Name   : hwk4.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk4, a car dealer inventory system
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
void Menu();
void Run();
void HandleInvalidInput();
int GetUserChoice();
void  Delay (int  milliseconds,  std::string delay_msg,  char  delay_symbol);
void showVehicleInventory(string make_model_list[], int year_list[], 
    double price_list[], int size);
float random_price(double low, double high);

int main()
{
    int size = 16; // array sizes
    string make_model_list[size];
    double price_list[size];
    int year_list[size];

    // Dummy delay
    Delay (500, "Loading inventory, please wait ", '.'); // delay to 1000
    cout << endl << endl;
    
    showVehicleInventory(make_model_list, year_list, price_list, size);

    Run();

    return 0;
}

void Run()
{
    int selection = 1;

    do
    {
        Menu();
        selection = GetUserChoice();

        switch (selection)
        {
            case 1: // View inventory
                cout << "==>case1\n\n";
                break;
            case 2: // Search by make and model
                cout << "==>case2\n\n";
                break;
            case 3: // Exit
                cout << "Thanks, exiting the program ...\n\n";
                break;
            default: // Handles the '0' return
                HandleInvalidInput();
                break;
        }
    }
    while (selection != 3);
}

int GetUserChoice()
{
    int selection;

    cout << "Please choose an option from the menu (1-3): ";
    cin >> selection;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << endl;
        return 0;
    }
    else if (selection < 1 || selection > 4){
        return 0;
    }
    else{
        return selection;
    }
}

void Menu()
{
    cout << "****************************\n";
    cout << "     SMART CAR INQUIRY\n";
    cout << "****************************\n";
    cout << " 1. View Vehicle Inventory\n";
    cout << " 2. Search by Make and Model\n";
    cout << " 3. Quit\n\n";
}

void HandleInvalidInput()
{
    cout << "Invalid input, please try again\n\n\n";
}

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

void showVehicleInventory(string make_model_list[], int year_list[], 
    double price_list[], int size)
{
    string make_model;
    double price = 0;
    int rand_number = 0;

    // car data
    vector<string> cars = {"Ford Taurus", "Toyota Camry", 
        "BMW 335i", "Rolls-Royce Phantom"};
    vector<double> low = {9000.0, 12000.0, 39500.0, 50000.0};
    vector<double> high = {27000.0, 30000.0, 53500.0, 180000.0};

    srand(static_cast<unsigned int> (time (0))); //seed for rand

    // Header
    cout << "      ****************************\n";
    cout << "           VEHICLE INVENTORY\n";
    cout << "      ****************************\n";

    for (int i=0; i<size; i++)
    {
        rand_number = rand()%4;
        switch(rand_number)
        {
            case 0:
                make_model_list[i] = "Ford Taurus";
                price_list[i] = random_price(low[0], high[0]);
                year_list[i] = 2010 + (rand()%8);
                break;

            case 1:
                make_model_list[i] = "Toyota Camry";
                price_list[i] = random_price(low[1], high[1]);
                year_list[i] = 2010 + (rand()%8);
                break;

            case 2:
                make_model_list[i] = "BMW 335i";
                price_list[i] = random_price(low[2], high[2]);\
                year_list[i] = 2010 + (rand()%8);
                break;
            case 3:
                make_model_list[i] = "Rolls-Royce Phantom";
                price_list[i] = random_price(low[3], high[3]);
                year_list[i] = 2010 + (rand()%8);
                break;
        }
    }

    for (int i=0; i<size; i++)
    {
        cout << setw(20) << right << make_model_list[i] << "   " <<
        year_list[i] << "   " << '$' <<
        setw(10) << fixed << setprecision(2) << right << 
        price_list[i] << endl;
    }
    cout << "\n\n";        
}

float random_price(double low, double high)
{
    return (low + static_cast<float> (rand()) / 
        static_cast<float> (RAND_MAX / (high)));
}
