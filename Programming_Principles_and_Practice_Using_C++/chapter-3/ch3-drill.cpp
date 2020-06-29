#include "std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to:\n";
    string first_name = {"???"};
    cin >> first_name;

    cout << "Enter the age of the person you want to write to:\n";
    int age = {0};
    cin >> age;
    if ((age < 0) || (age > 110))
    {
        simple_error("You're kidding!");
    }

    cout << "Enter the name of another friend:\n";
    string friend_name = {"???"};
    cin >> friend_name;

    char friend_sex = {0};
    cout << "If " << friend_name << " is male enter 'm', if she's female enter 'f':\n";
    cin >> friend_sex;

    // Letter:
    cout << endl
         << "Dear " << first_name << "," << endl
         << "\tHow are you? I am fine. I miss you. I'm quarantined right now, because of the COVID-19 pandemic. I guess you are too, aren't you?" << endl
         << "\tHave you seen " << friend_name << " lately? ";
    if (friend_sex == 'm')
    {
        cout << "If you see " << friend_name << " please ask him to call me." << endl;
    }
    else if (friend_sex == 'f')
    {
        cout << "If you see " << friend_name << " please ask her to call me." << endl;
    }
    cout << "\tI hear you just had a birthday and you are " << age << " years old. ";
    if (age < 12)
    {
        cout << "Next year you will be " << age + 1 << "." << endl;
    }
    else if (age == 17)
    {
        cout << "Next year you will be able to vote." << endl;
    }
    else if (age > 70)
    {
        cout << "I hope you are enjoying retirement." << endl;
    }
    else
    {
        cout << endl;
    }
    cout << "Yours sincerely," << endl
         << endl
         << "Lara" << endl
         << endl;
}