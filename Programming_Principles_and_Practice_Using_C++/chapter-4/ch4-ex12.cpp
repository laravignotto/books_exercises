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
    int max = {0};

    cout << "Insert a number. I'll find all the primes between 1 and that number: ";
    cin >> max;

    for (int i = 2; i<=max; ++i) {
        if (isPrime(i, v)) {
            v.push_back(i);
        }
    }

    cout << "The prime numbers between 1 and " << max << " are: ";
    for (int x : v)
        cout << x << " ";

    cout << endl;
}