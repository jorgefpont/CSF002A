//============================================================================
// File Name   : main.cpp
// Author      : <your name>
// Copyright   : Your copyright notice
// Description :  This program is to display a business card.

// Disclaimer:  If this program works obviously it's written by the above author. If it doesn't I don't know who wrote it.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 01-08-18          1.0           123               <your name>       Initial creation
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// main program is the entry point of a C++ program
main ( )  {

    cout << "\t\t Foothill College\n";     // \t is the tab character, \n is the new line character.

    cout << "\t\t John Doe\n";
    cout << "\t\t IT support\n";
    cout << endl;            // endl is from iomanip library which is to insert a new line.
    cout << "\n";

    cout << "Address:  Los Altos Hills, CA 94022"  <<  endl;
    cout << "Phone:    1-650-222-3333" << endl;          
    cout << "Email:     john_doe@fh.edu" << endl;

    return 0;
}
