#include "std_lib_facilities.h"

bool is_prime(int i, vector<int> v)
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
    int N = {0};

    cout << "Insert a number N. I'll find the first N prime numbers: ";
    cin >> N;

    vector<int> v = {};

    for (int i=2; ; ++i) {
        if (is_prime(i, v)) {
            v.push_back(i);
        }
        if (v.size() >= N) {
            break;
        }
    }

    cout << "The first " << N <<" prime numbers are: ";
    for (int x : v) 
        cout << x << " ";
    cout << endl;
}