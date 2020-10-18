/* ======================================================
File Name   : hwk2.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk3 cdf002A
Rev History :  initial
Date        : 10/11/2020

Version     : 1.0
Comments    : 
Change ID   : NA     
Author      : Jorge Pont      
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

// Function declaration
int SumOfIntegers(int number);
bool CheckLeapYear(int year);
int NumberOfVowels (string astring);
void Menu();


int main() {
    // Show the UI memu
    Menu();

    // variable declaration
    int anum = 0;
    int ayear = 0;
    string sometext;
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
                    bool leap = CheckLeapYear(ayear);
                    if (leap){
                        cout << ayear << " is a leap year\n";
                    }
                    else {
                        cout << ayear << " is not a leap year\n";
                    }
                        
                }
                else {
                    cout << "Negative years are not valid\n";
                }
                break;

            case 'C': case 'c':
                cout << "Enter some text: ";
                cin.ignore();
                getline (cin, sometext);
                cout << "Your entry has " << NumberOfVowels(sometext) << " vowels\n";
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

int SumOfIntegers(int number) 
{
    int sum = 0;
    while (number != 0) 
    {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

bool CheckLeapYear(int year)
{
    bool leap = true;

    if (year % 4 != 0)
    {
        leap = false;
    }
    else
    {
        if (year % 100 != 0)
        {
            leap = true;
        }
        else
        {
            if (year % 400 == 0)
            {
                leap = true;
            }
            else
            {
                leap = false;
            }
        }
    }
    return leap;
}

int NumberOfVowels (string astring)
{
    int vowell_counter = 0;

    for (int i=0; i < astring.length(); i++)
    {
        if (astring[i] == 'a' || astring[i] == 'A' ||
            astring[i] == 'e' || astring[i] == 'E' ||
            astring[i] == 'i' || astring[i] == 'I' ||
            astring[i] == 'o' || astring[i] == 'O' ||
            astring[i] == 'u' || astring[i] == 'U')
        {
            vowell_counter ++;
        }
    }
    return vowell_counter;
}

void Menu()
{
    cout << "*****************************\n";
    cout << "*          FUN MENU         *\n";
    cout << "*****************************\n";
    cout << "  <S>um of natural integers\n";
    cout << "  <L>eap year check\n";
    cout << "  <C>ount vowels\n";
    cout << "  <E>xit\n";
    cout << "*****************************\n\n";
}