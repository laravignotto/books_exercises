#include "std_lib_facilities.h"

/* Given a vector of ints from 2 to n,
 * returns a vector of primes.
 * The primes are calculated with the
 * Sieve of Eratosthenes method.
 */
vector<int> isPrime(vector<int> v)
{
    for (int i=0; i<sqrt(v.size()); ++i) {
        if (v[i] != 0) {
            for (int j=(i+v[i]); j<v.size(); j+=v[i])
                v[j] = 0;
        }
    }
    vector<int> r = {};
    for (int x : v) {
        if (x != 0)
            r.push_back(x);
    }
    return r;
}

int main()
{
    // vector of ints from 2 to 100
    vector<int> v = {};
    for (int i=2; i<=100; ++i)
        v.push_back(i);

    vector<int> p = isPrime(v);

    cout << "The prime numbers between 1 and 100 are: ";
    for (int x : p) 
        cout << x << " ";
    cout << endl;
}