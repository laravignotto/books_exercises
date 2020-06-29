#include "std_lib_facilities.h"

int main()
{
    int current_grains = {1};
    int previous_grains = {1};

    bool found_thousand = false;
    bool found_million = false;
    bool found_billion = false;

    int thousand = {0};
    int million = {0};
    int billion = {0};

        for (int i = 1; i <= 64; ++i)
    {
        cout << "Square no. " << i << "\tNo. of grains: " << current_grains << endl;

        if ((current_grains >= 1000) && (found_thousand == false)) {
            thousand = i;
            found_thousand = true;
        }

        if ((current_grains >= 1000000) && (found_million == false)) {
            million = i;
            found_million = true;
        }

        if ((current_grains >= 1000000000) && (found_billion == false)) {
            billion = i;
            found_billion = true;
            break;
        }

        current_grains = previous_grains * 2;
        previous_grains = current_grains;
    }

    cout << endl << "For at least 1000 grains of rice, are needed " << thousand << " squares." << endl
         << "For at least 1,000,000 grains of rice, are needed " << million << " squares." << endl
         << "For at least 1,000,000,000 grains of rice, are needed " << billion << " squares." << endl;
}