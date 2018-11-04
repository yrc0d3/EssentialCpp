#include <iostream>

using namespace std;

bool fibon_elem(int pos, int &elem)
{
    if (pos < 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int ix = 3; ix <= pos; ++ix)
    {
        elem = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
    }
    
    return true;
}

int main()
{
    int pos;
    cout << "please enter a position:\n";
    int elem;
    while (cin >> pos)
    {
        if (fibon_elem(pos, elem))
            cout << "element # " << pos
                 << " is " << elem << endl;
        else
            cout << "Sorry. Could not calculate element # "
                 << pos << endl;
    }

    return 0;
}
