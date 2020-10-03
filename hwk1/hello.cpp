#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
   cout << "Hello World!\n";
   int a=1, x=2, y=3, z=4;  
   a %= x + y + z;
   int a2 = a % (x + y + z);
   int a3 = a % x+ a % y + a % z;
   cout << "a = " << a << endl;
   cout << "a2 = " << a2 << endl;
   cout << "a3 = " << a3 << endl;
   
   cout << "\n\n\n";

   return 0;
}
