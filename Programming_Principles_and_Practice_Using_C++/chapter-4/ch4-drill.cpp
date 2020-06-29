#include "std_lib_facilities.h"

int main()
{
    constexpr double cm_in_m = 100;
    constexpr double cm_in_in = 2.54;
    constexpr double in_in_ft = 12;

    cout << "Insert a number and a unit (cm, m, in, ft) and press [enter] (e.g. '10.3 cm').\nWrite '|' and press [enter] to exit:" << endl;

    double number = {0};
    string unit = " ";

    cin >> number >> unit;

    double smallest = {number};
    double largest = {number};
    double sum_of_values = {number};
    int number_of_values = {1};
    vector<double> all_values = {number};

    cout << number << " " << unit << " the smallest and largest so far" << endl;

    while (cin >> number >> unit) { // read values from cin into number and unit

        // check valid units
        if ((unit == "m") || (unit == "cm") || (unit == "in") || (unit == "ft")) {
            // convert units to meters
            if (unit == "cm")
                number = number / cm_in_m;
            else if (unit == "in")
                number = (number * cm_in_in) / cm_in_m;
            else if (unit == "ft")
                number = ((number * in_in_ft) * cm_in_in) / cm_in_m;

            // determine if the number is the largest, smallest, or neither
            if (number > largest)
            {
                largest = number;
                cout << largest << " m"<< " the largest so far" << endl;
            }
            else if (number < smallest)
            {
                smallest = number;
                cout << smallest << " m"<< " the smallest so far" << endl;
            }
            else
            {
                cout << number << " m"<< endl;
            }

            // update number of values and sum of values
            number_of_values += 1;
            sum_of_values += number;
            all_values.push_back(number);
        }

        // invalid unit!
        else
            cout << "Invalid unit, try again. Units accapted: m, cm, in, ft." << endl;
        
    }

    // print desired values
    sort(all_values);
    cout << "Smallest: " << smallest << " m" << endl
         << "Largest: " << largest << " m" << endl
         << "Number of values: " << number_of_values << endl
         << "Sum of values: " << sum_of_values << " m" << endl
         << "All values entered, sorted: " << all_values[0] << " m";
    for (int i=1; i<all_values.size(); i++) 
        cout << ", " << all_values[i] << " m";
    cout << endl;
}