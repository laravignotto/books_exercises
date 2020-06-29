#include "std_lib_facilities.h"

bool isPrime(int i, vector<int> v)
{
    if (i == 2)
        return true;
    
    for (int x : v) {
        if (i % x == 0)
            return false;
    }
    return true;
}

int main()
{
    vector<int> v = {};

    for (int i=2; i<=100; ++i) {
        if (isPrime(i, v)) {
            v.push_back(i);
        }
    }

    cout << "The prime numbers between 1 and 100 are: ";
    for (int x : v)
        cout << x << " ";

    cout << endl;
}