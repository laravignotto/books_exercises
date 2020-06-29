#include "std_lib_facilities.h"

int main()
{
    vector<string> names = {};
    vector<int> scores = {};
    string n = {" "};
    int s = {0};

    cout << "Enter a name and a score, e.g. 'Lara 10'. Enter 'NoName 0' to quit: ";

    while (cin >> n >> s) {
        if ((n == "NoName") && (s == 0))
            break;

        names.push_back(n);
        scores.push_back(s);

        // Check if the last entered name already appears
        // in 'names'. If so, delete both the name and its
        // score from the vector.
        for (int i=0; i<(names.size()-1); ++i) {
            if (n == names[i]) {
                cout << "This name has already been entered! ";
                names.pop_back();
                scores.pop_back();
                break;
            }
        }

        cout << "Enter another name and score, or exit: ";
    }

    for (int i=0; i<names.size(); ++i)
        cout << names[i] << '\t' << scores[i] << endl;
}