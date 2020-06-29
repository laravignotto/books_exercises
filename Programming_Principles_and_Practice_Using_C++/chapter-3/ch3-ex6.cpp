#include "std_lib_facilities.h"

int main()
{
    cout << "Enter three space-separated integers:" << endl;
    int val1 = {0};
    int val2 = {0};
    int val3 = {0};
    cin >> val1;
    cin >> val2;
    cin >> val3;

    if (val1 <= val2) // 1 < 2
    {
        if (val2 <= val3) // 2 < 3
        {
            cout << val1 << " " << val2 << " " << val3 << endl;
        }
        else // 3 < 2
        {
            if (val1 <= val3) // 1 < 3
            {
                cout << val1 << " " << val3 << " " << val2 << endl;
            }
            else // 3 < 1
            {
                cout << val3 << " " << val1 << " " << val2 << endl;
            }
        }
    }
    else // 2 < 1
    {
        if (val3 <= val2) // 3 < 2
        {
            cout << val3 << " " << val2 << " " << val1 << endl;
        }
        else // 2 < 3
        {
            if (val1 <= val3) // 1 < 3
            {
                cout << val2 << " " << val1 << " " << val3 << endl;
            }
            else // 3 < 1
            {
                cout << val2 << " " << val3 << " " << val1 << endl;
            }
        }
    }
}