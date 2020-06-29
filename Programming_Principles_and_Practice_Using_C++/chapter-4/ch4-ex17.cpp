#include "std_lib_facilities.h"

/* Given a vector of strings, returns the min, max,
 * and mode (the string that appears the most times).
 */
string find_mode(vector<string> v)
{
    sort(v);

    string current_str = {0};
    string previous_str = {v[0]};
    int count = {0};
    int max = {0};
    string mode = {" "};

    for (int i=1; i<v.size(); ++i) {
        previous_str = v[i-1];
        current_str = v[i];
        if (current_str == previous_str) {
            ++count;
            if (count >= max) {
                max = count;
                mode = current_str;
            }
        }
        else
            count = 0;
    }

    return mode;
}

int main()
{
    string n = {" "};
    vector<string> v = {};

    cout << "Insert a word and press [enter]. Write 'quit' and press [enter] to finish: ";

    while(cin >> n) {
        if (n != "quit") {
            v.push_back(n);
            cout << "Insert another number or finish: ";
        }
        else
            break;
    }

    sort(v);
    cout << endl << "The min is: " << v[0] << endl;
    cout << "The max is: " << v[v.size()-1] << endl;
    string mode = find_mode(v);
    cout << "The mode is: " << mode << endl;
}