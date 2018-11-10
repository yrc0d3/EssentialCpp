#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void read_families(ifstream &ifile, map<string, vector<string> > &m)
{
    string line;
    while (getline(ifile, line, '\n')) {
        string family_name;
        vector<string> children;
        string::size_type pos = 0, prev_pos = 0, line_size = line.size();

        if (!line_size)
            continue;

        if (line.find_first_of(' ', pos) == string::npos) {
            family_name = line;
            prev_pos = line_size;
        } else {
            while ((pos = line.find_first_of(' ', pos)) != string::npos) {
                string::size_type len = pos - prev_pos;
                if (prev_pos == 0) 
                    family_name = line.substr(prev_pos, len);
                else
                    children.push_back(line.substr(prev_pos, len));
                ++pos;
                prev_pos = pos;
            }
        }

        // last child
        if (prev_pos < line_size)
            children.push_back(line.substr(prev_pos, pos - prev_pos));

        if (!m.count(family_name))
            m[family_name] = children;
        else
            cerr << "family name [" << family_name << "] is already in map" << endl;
    }
}

void query_map(map<string, vector<string> > &m)
{
	string family;
	cout << "Please enter a family name to search:";
	cin >> family;

	map<string, vector<string> >::const_iterator it = m.find(family);
	if (it == m.end()) 
	{
		cout << "Sorry. Family " << family << " is not found." << endl;
		return;
	}
		
	cout << "Family " << family; 
    if (!it->second.size())
		cout << " has no children" << endl;
	else 
    {
		cout << " has " << it->second.size() << " children: ";
		vector<string>::const_iterator iter = it->second.begin(), end_iter = it->second.end();
		while (iter != end_iter) {
			cout << *iter << " ";
			++iter;
		}
	    cout << endl;
	}
}

void display_map(map<string, vector<string> > &m)
{
	map<string, vector<string> >::const_iterator it = m.begin(), end_it = m.end();
    for (; it != end_it; it++) {
        cout << "Family " << it->first << endl;
        if (it->second.empty()) {
             cout << " has no children" << endl;
        } else {
            cout << " has " << it->second.size() << " children: ";
		    vector<string>::const_iterator iter = it->second.begin(), end_iter = it->second.end();
		    for (; iter != end_iter; iter++) {
		    	cout << *iter << " ";
		    }
            cout << endl;
        }
    }
}

int main()
{
    ifstream ifile("families.txt");
    
    if (!ifile) {
        cout << "Unable to open file!\n";
        return -1;
    }

    map<string, vector<string> > m;
    read_families(ifile, m);
	query_map(m);
    display_map(m);

    return 0;
}
