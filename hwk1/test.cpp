// extract to string
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main ()
{
  string name;
  int day, date;

  cout << "Enter day: ";
  cin >> day;
  cout << "Please, enter your full name: ";
  getline (cin,name);
  cout << "Please, enter your date: ";
  cin >> date;
  cout << "Hello, " << name << "--" << date << "!\n";

  return 0;
}