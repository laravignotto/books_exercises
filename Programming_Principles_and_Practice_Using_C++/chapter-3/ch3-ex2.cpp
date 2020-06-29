#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the number of miles you want to convert to kilometers:" << endl;
    double miles = {0};
    cin >> miles;

    cout << miles << " mi = " << miles * 1.609 << " km" << endl;
}