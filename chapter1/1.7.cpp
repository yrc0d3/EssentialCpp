#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ifstream infile("input.txt");
    if (!infile)
    {
        cerr << "Oops! Unable to open input.txt" << endl;
        return -1;
    }

    string line;
    vector<string> lines;
    while (infile >> line)
    {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    ofstream outfile("output.txt");
    if (!outfile)
    {
        cerr << "Oops! Unable to save data to output.txt" << endl;
        return -1;
    }
    for (int i = 0; i < lines.size(); ++i)
    {
        outfile << lines[i];
        if (i != lines.size() - 1)
            outfile << "\n";
    }
    outfile << endl;

    return 0;
}
