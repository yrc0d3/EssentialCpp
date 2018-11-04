#include <iostream>
#include <vector>

using namespace std;

inline bool check_validity(int pos)
{
    return (pos <= 0 || pos > 64) ? false : true;
}

const vector<int>* penta_vec(int pos)
{
    static vector<int> vec;
    if (check_validity(pos) && pos > vec.size())
    {
        for (int i = vec.size() + 1; i <= pos; i++)
            vec.push_back(i * (3 * i - 1) / 2);
    }

    return &vec;
}

bool penta_elem(int pos, int &elem)
{
    if (!check_validity(pos))
    {
        cerr << "Invalid position: " << pos << endl;
        elem = 0;
        return false;
    }

    const vector<int>* vec = penta_vec(pos);
    elem = (*vec)[pos - 1];
    return true;
}

void display_vec(vector<int> &vec, const string &title, ostream &os = cout)
{
    os << title << "\n";
    for (int i = 0 ; i < vec.size(); i++)
        os << vec[i] << " ";
    os << endl;
}

int main()
{
    int elem;

    if (penta_elem(0, elem))
        cout << "element 0 is " << elem << '\n';
    if (penta_elem(64, elem))
        cout << "element 64 is " << elem << '\n';
    if (penta_elem(10, elem))
        cout << "element 10 is " << elem << '\n';
    if (penta_elem(65, elem))
        cout << "element 65 is " << elem << '\n';

    return 0;
}
