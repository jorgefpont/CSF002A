#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    int one_digit = 0;
    int ten_digit = 0;
    int hundred_digit = 0;
    int thousand_digit = 0;
    int number = 7145;  // or better to ask for user input.

    cout << number << endl;
    cout << number / 1000 << endl;
    cout << number % 1000 << endl;
    cout << number % 100 << endl;
    cout << number % 10 << endl << endl;

    thousand_digit = number / 1000;
    cout << thousand_digit << endl;
    //hundred_digit = ( number - thousand_digit * 1000 ) / 100;
    hundred_digit = ( number % 1000 ) / 100;
    cout << hundred_digit << endl;
    //ten_digit = ( number - thousand_digit * 1000 - ten_digit * 100) / 10;
    ten_digit = ( number % 100 ) / 10;
    cout << ten_digit << endl;
    //one_digit = (I am stuck can someone helps me?);
    one_digit = number % 10;
    cout << one_digit << endl;

}