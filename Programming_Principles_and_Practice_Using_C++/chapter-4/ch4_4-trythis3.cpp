#include "std_lib_facilities.h"

int main()
{
    char c = 'a';
    while (c <= 'z') {
        int i = c;
        cout << c << '\t' << i << endl;
        ++c;
    }
}