/*
Implement a simple mortgage calculation program 
The program will start out by asking for:
property zip code, property's full address, 
annual interest rate (in percentage), 
number of years to pay off the loan, 
property's value and percentage of down payment. 
It will then calculate the loan amount, 
monthly mortgage payment, total monthly payment 
including property tax and total payment 
over the loan period and will display the results of its calculations
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {

    int zip_code = 0;
    int duration = 10;
    string address;
    float offer_price = 100;
    float down_pymnt_pct = 20;  // in percent
    float annual_rate = 5;  // in percent

    cout << "Enter property zip code: ";
    cin >> zip_code;
    
    cout << "Enter property address: ";
    cin.ignore();
    getline (cin, address);
    
    cout << "Enter property offer price (principal): ";
    cin >> offer_price;
    cout << "Enter down payment (in percentage %): ";
    cin >> down_pymnt_pct;
    cout << "Enter annual interest rate (in percentage %): ";
    cin >> annual_rate;
    cout << "Enter number of years financing: ";
    cin >> duration;

    float down_pymt = offer_price * ( 1 - down_pymnt_pct / 100);

    cout << "\t\t***************************" << endl << endl;
    cout << "\t\tMORTGAGE CALCULATOR RESULTS" << endl << endl;
    cout << "\t\t***************************" << endl << endl;
    cout << "Property adress: " << address << endl;
    cout << "Property offer price (principal): " << offer_price << endl;
    cout << "Down payment: " << down_pymt;
}

