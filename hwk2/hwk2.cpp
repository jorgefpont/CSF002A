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
//#include <cmath>
#include <math.h>

using namespace std;

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

    double down_payment = offer_price * (down_pct / 100);
    double loan_amount = offer_price - down_payment;
    double monthly_rate = annual_rate / 12.0;
    double mortgage_monthly_payment = loan_amount * (monthly_rate/100.0) / 
                    (1.0 - 
                    1.0 / (pow(1.0 + monthly_rate / 100, duration * 12)));
    
    // need to make global
    double property_tax_rate = 1.5;
    double monthly_tax = offer_price * property_tax_rate / 100 / 12;

    double monthly_payment_w_tax = mortgage_monthly_payment + monthly_tax;
    double total_payment = mortgage_monthly_payment * 12.0 * duration;

    cout << "\t\t***************************" << endl << endl;
    cout << "\t\tMORTGAGE CALCULATOR RESULTS" << endl << endl;
    cout << "\t\t***************************" << endl << endl;
    cout << "Property adress: \t\t\t\t" << address << endl;
    cout << "Property offer price (principal): \t\t" << offer_price << endl;
    cout << "Down payment: \t\t\t\t\t" << down_payment << endl;
    cout << "Loan amount: \t\t\t\t\t" << loan_amount << endl;
    cout << "Loan maturity date: \t\t\t" << endl;
    cout << "Mortgage monthly payment: \t\t\t" << mortgage_monthly_payment << endl;
    cout << "Monthly payment (property tax included): \t" << monthly_payment_w_tax << endl;
    cout << "Total payment: \t\t\t\t\t" << total_payment << endl;

    cout << "\n\n";
    
}

