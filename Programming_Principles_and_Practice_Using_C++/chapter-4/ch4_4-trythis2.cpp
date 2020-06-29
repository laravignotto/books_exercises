#include "std_lib_facilities.h"

int main()
{
    constexpr double dollar_per_yen = 0.0093;
    constexpr double dollar_per_euro = 1.1;
    constexpr double dollar_per_pound = 1.26;
    constexpr double dollar_per_yuan = 0.14;
    constexpr double dollar_per_krone = 0.098;

    double money = 1;

    char unit = ' ';

    cout << "Please enter an amount of money followed bya space and a currency ('y' for yen, 'e' for euro, 'p' for pound, 'r' for yuan, 'k' for krone):" << endl;
    cin >> money >> unit;

    switch (unit) {
    case 'y':
        cout << "¥" << money << " == $" << money * dollar_per_yen << endl;
        break;
    case 'e':
        cout << money << " € == $" << money * dollar_per_euro << endl;
        break;
    case 'p':
        cout << "£" << money << " == $" << money * dollar_per_pound << endl;
        break;
    case 'r':
        cout << money << " ¥ == $" << money * dollar_per_yuan << endl;
        break;
    case 'k':
        cout << money << " kr == $" << money * dollar_per_krone << endl;
        break;
    default:
        cout << "Sorry, I don't know a currency called '" << unit << "'" << endl;
        break;
    }
}