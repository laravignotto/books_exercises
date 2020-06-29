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

    cout << "Names and scores registered." << endl << "Enter a number to find the corresponding names with that score, or enter a letter to exit: ";

    bool found = false;
    while (cin >> s) {
        // Check if the entered score is in the vector 
        for (int i=0; i<scores.size(); ++i) {
            if (s == scores[i]) {
                cout << names[i] << endl; // print the names
                found = true;
            }
        }

        // If the score is not in the vector, print not found
        if (!found)
            cout << "Score not found." << endl;
        found = false;
        
        cout << "Enter another score, or exit: ";
    }
}