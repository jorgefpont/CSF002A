/* ======================================================
File Name   : hwk1.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk1, move ticket exercise
Revision History:  initial
Date        : 9/26/2020

Version     : 1.0
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

string movie_title;
string movie_rating = "PG-13";
string am_pm;
int hour = 1;
int minutes = 0;
int day = 1;
int month = 1;
int year = 2020;
int theater_loc = 1;
double price = 12.75;

cout << "Enter year: ";
cin >> year;
cout << "Enter month: ";
cin >> month;
cout << "Enter day: ";
cin >> day;
cout << "Enter movie title: ";

//had to research for multi word input
//need the cin.ignore()
cin.ignore();
getline (cin, movie_title);

cout << "Enter time - hour: ";
cin >> hour;
cout << "Enter time - minutes: ";
cin >> minutes;
cout << "Enter time - am or pm: ";
cin >> am_pm;

cout << "---------------------------------------------------------------------\n\n";
cout << "\t\t\tAMC Universal CityWalk\n\n" << "\t\t\t     Presenting\n\n";
cout << "\t\t\t" << movie_title << endl << endl;
printf("Show time: %02d:%02d ", hour, minutes);
cout << am_pm << "\t";
printf("Date: %02d/%02d/%i\n\n", month, day, year);
//cout << "Date: " << month << "/" << day << "/" << year << endl << endl;
cout << "Theater: " <<  theater_loc << "\t\tRating: " << movie_rating << endl << endl;
cout << "Adult Admission $" << price << endl << endl;
cout << "Don't forget to get your free small popcorn with 4 tickets or more!!!\n\n";
cout << "---------------------------------------------------------------------\n";

}