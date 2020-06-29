#include "std_lib_facilities.h"

int main()
{
    double n1 = {0};
    double n2 = {0};
    char o = {' '};

    cout << "Insert two numbers and an operator, space-separated (e.g.: '35.6 24.1 +') and press [enter]." << endl;

    for (; cin >> n1 >> n2 >> o;) {

        if (o == '+') {
            cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << endl;
            break;
        }

        else if (o == '-') {
            cout << "The difference between " << n1 << " and " << n2 << " is " << n1 - n2 << endl;
            break;
        }

        else if ((o == '*') || (o == 'x')) {
            cout << "The product of " << n1 << " and " << n2 << " is " << n1 * n2 << endl;
            break;
        }

        else if ((o == '/') || (o == ':')) {
            cout << "The quotient between " << n1 << " and " << n2 << " is " << n1 / n2 << endl;
            break;
        }

        else {
            cout << "Incorrect operator. Valid operators are '+', '-', '*' (or 'x'), and '/' (or ':')." <<  endl;
        }
    }
}