#include <iostream>
#include <string>
using namespace std;

int main()
{
    string user_name;
    cout << "please enter your first name: ";
    cin >> user_name;
    cout << '\n'
         << "Hello, "
         << user_name
         << " ... and googbye!\n";

    return 0;
}
