/* ======================================================
File Name   : hwk2.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk2, a mortgage calculator
Revision History:  initial
Date        : 10/1/2020

Version     : 1.0
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h> //#include <cmath> did not work

using namespace std;
const double kPropertyTaxRate = 1.5;  // hwk requirement to declare const

// Timer function
void  Delay (int  milliseconds,  
            std::string delay_msg = "",  
            char  delay_symbol = '.') ;

int main() {

    int zip_code = 0;
    int duration = 10;
    string address;
    double offer_price = 1000.0;
    double down_pct = 20.0;  // in percent
    double annual_rate = 5.0;  // in percent

    cout << "Enter property zip code: ";
    cin >> zip_code;
    
    cout << "Enter property address: ";
    cin.ignore();
    getline (cin, address);

    cout << "Enter property offer price (principal): ";
    cin >> offer_price;
    cout << "Enter down payment (in percentage %): ";
    cin >> down_pct;
    cout << "Enter annual interest rate (in percentage %): ";
    cin >> annual_rate;
    cout << "Enter number of years financing: ";
    cin >> duration;
    cout << endl << endl;

    // Dummy delay
    Delay (5000, "Mortgage calculator is processing your data ... Please wait.");
    cout << endl << endl;

    double down_payment = offer_price * (down_pct / 100);
    double loan_amount = offer_price - down_payment;
    double monthly_rate = annual_rate / 12.0;
    double mortgage_monthly_payment = loan_amount * (monthly_rate/100.0) / 
                    (1.0 - 
                    1.0 / (pow(1.0 + monthly_rate / 100, duration * 12)));
    
    double monthly_tax = offer_price * kPropertyTaxRate / 100 / 12;
    double monthly_payment_w_tax = mortgage_monthly_payment + monthly_tax;
    double total_payment = mortgage_monthly_payment * 12.0 * duration;
    string maturity_date = "12/31/" + to_string(duration + 2020);

    // output
    cout << "\t\t***************************" << endl << endl;
    cout << "\t\tMORTGAGE CALCULATOR RESULTS" << endl << endl;
    cout << "\t\t***************************" << endl << endl;
    cout << "Property adress: " << address << endl;
    cout << fixed << setprecision (2);   // 2 digits after the decimal point
    cout << "Property offer price (principal): \t\t$ " << setw(10) 
            << offer_price << endl;
    cout << "Down payment: \t\t\t\t\t$ " << setw(10) << down_payment << endl;
    cout << "Loan amount: \t\t\t\t\t$ " << setw(10) << loan_amount << endl;
    cout << "Loan maturity date: \t\t\t\t" << setw(12) 
            << maturity_date << endl;
    cout << "Mortgage monthly payment: \t\t\t$ " << setw(10)
            << mortgage_monthly_payment << endl;
    cout << "Monthly payment (property tax included): \t$ " << setw(10) 
            << monthly_payment_w_tax << endl;
    cout << "Total payment: \t\t\t\t\t$ " << setw(10) << total_payment << endl;
    cout << "\n\n";

    return 0; // I won't forget this time ...
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

