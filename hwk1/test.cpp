// extract to string
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double per_guest = 13.95;

int main ()
{
  int guests = 8;
  double bill = guests * per_guest;

  cout << fixed << setprecision (2);

  cout << "The bill is $" << bill << " (for " << guests << 
        " persons). See you again!" << endl;

  return 0;
}