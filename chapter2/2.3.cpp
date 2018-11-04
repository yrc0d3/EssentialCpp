#include <iostream>
#include <vector>

using namespace std;

inline bool check_validity(int pos)
{
    return (pos <= 0 || pos > 64) ? false : true;
}

void penta_elems(vector<int> &vec, int pos)
{
    for (int i = vec.size() + 1; i <= pos; i++)
        vec.push_back(i * (3 * i - 1) / 2);
}

bool penta_seq(vector<int> &vec, int pos)
{
    if (!check_validity(pos))
    {
        cerr << "Invalid position: " << pos << endl;
        return false;
    }

    if (pos > vec.size())
        penta_elems(vec, pos);

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
    const string title("Pentagonal Seq");
    vector<int> vec;

    if (penta_seq(vec, 0))
        display_vec(vec, title);
    if (penta_seq(vec, 10))
        display_vec(vec, title);
    if (penta_seq(vec, 65))
        display_vec(vec, title);

    return 0;
}
