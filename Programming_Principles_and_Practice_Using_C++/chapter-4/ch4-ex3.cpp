#include "std_lib_facilities.h"

int main()
{
    vector<double> v = {};

    cout << "Insert a distance (e.g. 56.4) and press [enter]\nInsert a letter and press [enter] to exit." << endl;

    for (double i; cin >> i;)
        v.push_back(i);

    sort(v);

    double sum = {0};

    for (double i : v)
        sum += i;

    cout << "Total distance: " << sum << endl
        << "Smallest distance: " << v[0] << endl
        << "Greatest distance: " << v[v.size() - 1] << endl
        << "Mean distance: " << sum / v.size() << endl;    
}