#include "std_lib_facilities.h"

int main()
{
    cout << "Enter three space-separated words:" << endl;
    string st1 = {0}, st2 = {0}, st3 = {0};
    cin >> st1 >> st2 >> st3;

    if (st1 <= st2) // 1 < 2
    {
        if (st2 <= st3) // 2 < 3
        {
            cout << st1 << " " << st2 << " " << st3 << endl;
        }
        else // 3 < 2
        {
            if (st1 <= st3) // 1 < 3
            {
                cout << st1 << " " << st3 << " " << st2 << endl;
            }
            else // 3 < 1
            {
                cout << st3 << " " << st1 << " " << st2 << endl;
            }
        }
    }
    else // 2 < 1
    {
        if (st3 <= st2) // 3 < 2
        {
            cout << st3 << " " << st2 << " " << st1 << endl;
        }
        else // 2 < 3
        {
            if (st1 <= st3) // 1 < 3
            {
                cout << st2 << " " << st1 << " " << st3 << endl;
            }
            else // 3 < 1
            {
                cout << st2 << " " << st3 << " " << st1 << endl;
            }
        }
    }
}