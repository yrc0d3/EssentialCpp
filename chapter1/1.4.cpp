#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first_name;
    string last_name;
    cout << "please enter your first name: ";
    cin >> first_name;
    cout << "please enter your last name: ";
    cin >> last_name;
    cout << '\n'
         << "Hello, "
         << first_name
         << " "
         << last_name
         << " ... and googbye!\n";

    return 0;
}
