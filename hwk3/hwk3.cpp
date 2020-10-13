/* ======================================================
File Name   : hwk2.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk3, ...
Revision History:  initial
Date        : 10/11/2020

Version     : 1
Comments    : 
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

    // UI memu
    cout << "*****************************" << endl;
    cout << "*          FUN MENU         *" << endl;
    cout << "*****************************" << endl << endl;
    cout << "  <S>um of natural integers" << endl;
    cout << "  <L>eap year check" << endl;
    cout << "  <C>ount vowels" << endl;
    cout << "  <E>xit" << endl << endl;
    cout << "*****************************" << endl << endl;

    // Function declaration
    int SumOfIntegers(int number);

    // variable declaration
    int anum = 0;
    int ayear = 0;
    string sometext;

    // User input
    char sel = 'S';


    while (sel != 'E' || 'e') {

        cout << "Please choose an option fromt the FUN MENU: ";
        cin >> sel;

        switch (sel) {
            case 'S': case 's':
                cout << "Enter an integer: ";
                cin >> anum;
                if (anum >= 0) {
                    cout << "Sum of integers is: " << 
                             SumOfIntegers(anum) << endl;    
                }
                else {
                    cout << "Negative numbers are not valid\n";
                }
                break;
            case 'L': case 'l':
                cout << "Enter a year: ";
                cin >> ayear;
                if (ayear >= 0) {
                    cout << ayear << endl;    
                }
                else {
                    cout << "Negative years are not valid\n";
                }
                break;
            case 'C': case 'c':
                cout << "Enter some text: ";
                cin.ignore();
                getline (cin, sometext);
                cout << sometext << endl;
                break;
            case 'E': case 'e':
                cout << "Bye, thanks for playing\n";
                exit(0);
            default:
                cout << "\nInvalid input, try again ...\n";
                break;
        }
    }
    return 0;
}

int SumOfIntegers(int number) {
    int sum = 0;
    while (number != 0) {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}