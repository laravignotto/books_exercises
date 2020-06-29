#include "std_lib_facilities.h"

double calculate_delta(int a, int b, int c)
{
    return ((b * b) - (4 * a * c));
}

vector<double> solve_equation(int a, int b, int c)
{
    vector<double> v = {};

    double delta = calculate_delta(a, b, c);
    // if the equation has no solutions, return an empty vector
    if (delta < 0)
        return v;

    double x1 = ((-b - sqrt(delta)) / (2 * a));
    double x2 = ((-b + sqrt(delta)) / (2 * a));

    if (x1 == x2)
        v.push_back(x1);
    else {
        v.push_back(x1);
        v.push_back(x2);
    }

    return v;
}

int main()
{
    double a = {0},
            b = {0},
            c = {0};

    cout << "I'm a quadratic equation solver! A quadratic equation is of the form ax^2 + 2x + c = 0." << endl
        << "Insert a: ";
    cin >> a;
    cout << "Insert b: ";
    cin >> b;
    cout << "Insert c: ";
    cin >> c;

    vector<double> v = solve_equation(a, b, c);

    if (v.size() == 2)
        cout << "The solutions are " << v[0] << " and " << v[1] << endl; 
    else if (v.size() == 1)
        cout << "The solution is " << v[0] << endl;
    else
        cout << "This equation has no solutions." << endl;
}