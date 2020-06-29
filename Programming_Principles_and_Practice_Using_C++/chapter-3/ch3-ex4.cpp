#include "std_lib_facilities.h"

int main()
{
    cout << "Enter two space-separated integers:" << endl;
    int val1 = {0};
    int val2 = {0};
    cin >> val1;
    cin >> val2;

    if (val1 < val2)
    {
        cout << "Smaller: " << val1 << endl
             << "Larger: " << val2 << endl;
    }
    else if (val1 > val2)
    {
        cout << "Smaller: " << val2 << endl
             << "Larger: " << val1 << endl;
    }
    else
    {
        cout << "Smaller = Larger: " << val1 << endl;
    }

    cout << "Sum: " << val1 + val2 << endl
         << "Difference: " << val1 - val2 << endl
         << "Product: " << val1 * val2 << endl;

    double dval1 = {val1};
    double dval2 = {val2};

    cout << "Ratio: " << dval1 / dval2 << endl;
}