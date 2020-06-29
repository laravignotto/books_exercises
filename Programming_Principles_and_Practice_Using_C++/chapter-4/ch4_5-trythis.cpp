#include "std_lib_facilities.h"

int square(int x)
{
    int result = {0};

    for (int i=1; i<=x; i++) {
        result += x;
    }

    return result;
}

int main()
{
    cout << square(2) << endl;
    cout << square(10) << endl;
    cout << square(12) << endl;
}