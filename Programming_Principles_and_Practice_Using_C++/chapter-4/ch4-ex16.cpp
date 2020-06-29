#include "std_lib_facilities.h"

/* Given a vector of ints, returns its mode,
 * that is the number that appears the most times.
 */
int find_mode(vector<int> v)
{
    sort(v);

    int current_number = {0};
    int previous_number = {v[0]};
    int count = {0};
    int max = {0};
    int mode = {0};

    for (int i=1; i<v.size(); ++i) {
        previous_number = v[i-1];
        current_number = v[i];
        if (current_number == previous_number) {
            ++count;
            if (count >= max) {
                max = count;
                mode = current_number;
            }
        }
        else
            count = 0;
    }

    return mode;
}

int main()
{
    int n = {0};
    vector<int> v = {};

    cout << "Insert a number and press [enter]. Insert a character and press [enter] to finish: ";

    while(cin >> n) {
        v.push_back(n);
        cout << "Insert another number or finish: ";
    }

    int mode = find_mode(v);

    cout << endl << "The mode is: " << mode << endl;
}