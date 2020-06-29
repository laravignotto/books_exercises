#include "std_lib_facilities.h"

int main()
{
    double penny = {0}, nickel = {0}, dime = {0}, quarter = {0}, half = {0}, dollar = {0};
    cout << "How many pennies do you have?" << endl;
    cin >> penny;
    cout << "How many nickels do you have?" << endl;
    cin >> nickel;
    cout << "How many dimes do you have?" << endl;
    cin >> dime;
    cout << "How many quarters do you have?" << endl;
    cin >> quarter;
    cout << "How many half dollars do you have?" << endl;
    cin >> half;
    cout << "How many one-dollars do you have?" << endl;
    cin >> dollar;

    if (penny != 1)
    {
        cout << "You have " << penny << " pennies." << endl;
    }
    else
    {
        cout << "You have " << penny << " penny." << endl;
    }
    if (nickel != 1)
    {
        cout << "You have " << nickel << " nickels." << endl;
    }
    else
    {
        cout << "You have " << nickel << " nickel." << endl;
    }
    if (dime != 1)
    {
        cout << "You have " << dime << " dimes." << endl;
    }
    else
    {
        cout << "You have " << dime << " dime." << endl;
    }
    if (quarter != 1)
    {
        cout << "You have " << quarter << " quarters." << endl;
    }
    else
    {
        cout << "You have " << quarter << " quarter." << endl;
    }
    if (half != 1)
    {
        cout << "You have " << half << " half dollars." << endl;
    }
    else
    {
        cout << "You have " << half << " half dollar." << endl;
    }
    if (dollar != 1)
    {
        cout << "You have " << dollar << " dollars." << endl;
    }
    else
    {
        cout << "You have " << dollar << " dollar." << endl;
    }

    double total = {0};
    total = (penny + (nickel * 5) + (dime * 10) + (quarter * 25) + (half * 50) + (dollar * 100)) / 100;

    cout << "The value of all your coins is $" << total << endl;
}