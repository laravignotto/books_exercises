#include "std_lib_facilities.h"

int main()
{
    for (char c = 'a'; c <= 'z'; ++c) {
        int i = c;
        cout << c << '\t' << i << endl;
    }

    for (char c = 'A'; c <= 'Z'; ++c) {
        int i = c;
        cout << c << '\t' << i << endl;
    }

    for (int i = 0; i <= 9; ++i) {
        cout << i << '\t' << i << endl;
    }
}