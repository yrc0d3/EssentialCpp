#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class even_elem {
    public:
        bool operator()(int elem) {
            return elem % 2 ? false : true;
        }
};

int main()
{
    ofstream even_file("even.txt"),  odd_file("odd.txt");
    
    if (!even_file || !odd_file) {
        cout << "Unable to open output files!\n";
        return -1;
    }

    vector<int> input;
    istream_iterator<int> in(cin), eos;

    copy(in, eos, back_inserter(input));
    vector<int>::iterator division = partition(input.begin(), input.end(), even_elem());

    ostream_iterator<int> even_iter(even_file, "\n"), odd_iter(odd_file, " ");
    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);

    return 0;
}
