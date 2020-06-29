#include "std_lib_facilities.h"

int main()
{
    cout << "Spell a number (all lowercase):" << endl;
    string number = {""};
    cin >> number;

    if (number == "zero")
    {
        cout << "0" << endl;
    }
    else if (number == "one")
    {
        cout << "1" << endl;
    }
    else if (number == "two")
    {
        cout << "2" << endl;
    }
    else if (number == "three")
    {
        cout << "3" << endl;
    }
    else if (number == "four")
    {
        cout << "4" << endl;
    }
    else
    {
        cout << "Not a number I know" << endl;
    }
}