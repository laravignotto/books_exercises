#include "std_lib_facilities.h"

int main()
{
    cout << "Enter two space-separated floating point numbers:" << endl;
    double val1 = {0};
    double val2 = {0};
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

    cout << "Ratio: " << val1 / val2 << endl;
}