#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
    vector<double> temps;
    for (double temp; cin >> temp;)
        temps.push_back(temp);

    double sum = {0};
    for (int x : temps)
        sum += x;
    cout << "Average temperature: " << sum / temps.size() << endl;

    sort(temps);
    if (temps.size() % 2 == 1)
        cout << "Median temperature: " << temps[temps.size() / 2] << endl;
    else {
        double v1 = temps[temps.size() / 2];
        double v2 = temps[(temps.size() / 2) - 1];
        cout << "Median temperature: " << (v1 + v2) / 2 << endl;
    }
}