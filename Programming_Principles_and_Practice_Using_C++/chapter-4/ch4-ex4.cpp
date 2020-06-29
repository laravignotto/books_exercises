#include "std_lib_facilities.h"

int calculateN(int h, int l)
{
    return ((h - l) / 2) + l;
}

int main()
{
    int l = {0};
    int h = {100};
    int n = calculateN(h, l);

    cout << "Think of a number between 1 and 100.\nAnswer the following questions with 'y' or 'n'." << endl 
        << endl
        << "Is the number you are thinking of less than " << n << "?" << endl;

    for (char c; cin >> c;) {

        if (c == 'y') {
            h = n;
            n = calculateN(h, l);
            cout << "Is the number you are thinking of less than " << n << "?" << endl;
        }

        else if (c == 'n') {
            char a;

            cout << "Is the number " << n << "?" << endl;
            cin >> a;

            if (a == 'y') {
                cout << "Number guessed!" << endl;
                break;
            }
            else if (a == 'n') {
                l = n;
                n = calculateN(h, l);
                cout << "Is the number you are thinking of less than " << n << "?" << endl;
            }            
            else {
            cout << "Unknown answer. Answer the questions with 'y' or 'n'." << endl;
            }
        }

        else {
            cout << "Unknown answer. Answer the questions with 'y' or 'n'." << endl;
        }
    }
}