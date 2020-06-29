#include "std_lib_facilities.h"

int main()
{
    vector<string> disliked = {"broccoli", "fish", "mushrooms"};

    cout << "Write a few space-separated words, then press [enter] and [ctrl]+[D]" << endl;
    vector<string> words;
    for (string temp; cin>>temp; ) 
        words.push_back(temp);

    for (int i=0; i<words.size(); ++i) {
        for (int j=0; j<disliked.size(); ++j)
            if (words[i] == disliked[j]) {
                words[i] = "BLEEP";
                break;
            }
        cout << words[i] << endl;
    }
}