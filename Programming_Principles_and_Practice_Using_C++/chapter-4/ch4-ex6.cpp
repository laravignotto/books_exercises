#include "std_lib_facilities.h"

int main()
{
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    char choice = {' '};

    cout << "Would you like to convert digits to words ('d') or words to digits ('w')?" << endl;

    cin >> choice;

    if (choice == 'd') {
        int digit = {0};

        cout << "Insert a single digit and press [enter]." << endl;

        for (; cin >> digit;)
            cout << v[digit] << endl;
    }

    else if (choice == 'w') {
        string word = {" "};

        cout << "Insert a spelled out digit and press [enter]." << endl;

        for (; cin >> word;) {
            for (int i=0; i<v.size(); ++i) {
                if (word == v[i])
                    cout << i << endl; 
            }
        }
    }

    else 
        cout << "Invalid input. Enter eiter 'd' or 'w'." << endl; 
}