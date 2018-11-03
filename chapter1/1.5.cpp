#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "please enter your name: ";
    cin >> name;
    if (name.size() <= 2)
        cout << "Your name is too short!\n";
    else
        cout << "Hello, " << name << "!" << endl;

    return 0;
}
