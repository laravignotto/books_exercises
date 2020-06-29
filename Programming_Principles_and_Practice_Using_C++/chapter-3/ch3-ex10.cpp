#include "std_lib_facilities.h"

int main()
{
    cout << "Enter an operation followed by two operand, such as '+ 5 3.5' or 'div 8 4':" << endl;
    string operand = {""};
    double val1 = {0}, val2 = {0};
    cin >> operand >> val1 >> val2;

    if ((operand == "+") || (operand == "plus"))
    {
        cout << val1 + val2 << endl;
    }
    else if ((operand == "-") || (operand == "minus"))
    {
        cout << val1 - val2 << endl;
    }
    else if ((operand == "*") || (operand == "x") || (operand == "mul"))
    {
        cout << val1 * val2 << endl;
    }
    else if ((operand == "/") || (operand == ":") || (operand == "div"))
    {
        cout << val1 / val2 << endl;
    }
    else
    {
        cout << "Couldn't understand" << endl;
    }
}