#include "std_lib_facilities.h"

int main()
{
    cout << "Enter an integer to find out if it's even or odd:" << endl;
    int number = {0};
    cin >> number;

    if ((number % 2) == 0)
    {
        cout << "The value " << number << " is an even number" << endl;
    }
    else
    {
        cout << "The value " << number << " is an odd number" << endl;
    }
}