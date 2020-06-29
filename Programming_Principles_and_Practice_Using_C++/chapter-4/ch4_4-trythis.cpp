#include "std_lib_facilities.h"

int main()
{
    constexpr double dollar_per_yen = 0.0093;
    constexpr double dollar_per_euro = 1.1;
    constexpr double dollar_per_pound = 1.26;

    double money = 1;

    char unit = ' ';

    cout << "Please enter an amount of money followed by a currency ('y' for yen, 'e' for euro, 'p' for pound):" << endl;
    cin >> money >> unit;

    if (unit == 'y')
        cout << "¥" << money << " == $" << money * dollar_per_yen << endl;
    else if (unit == 'e')
        cout << money << "€ == $" << money * dollar_per_euro << endl;
    else if (unit == 'p')
        cout << "£" << money << " == $" << money * dollar_per_pound << endl;
    else
        cout << "Sorry, I don't know a currency called '" << unit << "'" << endl;
}