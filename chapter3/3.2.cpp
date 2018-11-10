#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LessThan {
public:
    bool operator()(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
};

int main()
{
    ifstream ifile("3.1.txt");
    
    if (!ifile) {
        cout << "Unable to open file!\n";
        return -1;
    }

    vector<string> vec;
	string word;
	while (ifile >> word) {
        vec.push_back(word);
	}

    sort(vec.begin(), vec.end(), LessThan());

    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
