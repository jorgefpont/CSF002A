/* ======================================================
File Name   : f_to_c.cpp
Author      : Jorge Pont
Copyright   : N/A
Description : hwk2 xtra credit, deg. F to C converter
Revision History:  initial
Date        : 10/1/2020

Version     : 1.0
Change ID   : NA     
Author      : Jorge Pont      
Comment     : NA
========================================================= */

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
  double temp_f;
  
  cout << fixed << setprecision (2);   // 2 digits after the decimal point

  cout << "Enter temperature in deg. F: ";
  cin >> temp_f;
  double temp_c = (5.0/9.0) * (temp_f - 32.0);
  cout << temp_f << " F = " << temp_c << " C" << endl << endl;

  return 0;
}